#pragma once  
#include <string>
#include "Message.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "ChatRoom.h"

using namespace System;  
using namespace System::Windows::Forms;  
using namespace System::Drawing;  

class MessageHandler {  
public:  

    static void initializeChat(ChatRoom chatRoom, FlowLayoutPanel^ messagesContainer, 
                               unordered_map<int, chati::Message>& messages, User currentUser) {

        for(auto& messageID : chatRoom.messagesID) {
            createMessage(messagesContainer, messages[messageID]);
		}

    }

    static void createMessageEvent(TextBox^ textBox1, FlowLayoutPanel^ messagesContainer, unordered_map<int, chati::Message> &messages, User currentUser, ChatRoom &currentChat) {
        if (textBox1->Text != "") {
            string s = msclr::interop::marshal_as<string>(textBox1->Text);

            int messageID;
            if (messages.empty()) messageID = 1;
            int maxID = 0;
            for (const auto& pair : messages) {
                if (pair.second.messageID > maxID) {
                    maxID = pair.second.messageID;
                }
            }
            messageID = maxID + 1;

            auto now = chrono::system_clock::now();
            time_t now_time_t = chrono::system_clock::to_time_t(now);
            tm* now_tm = localtime(&now_time_t);



            ostringstream day, time;
            day << std::put_time(now_tm, "%d-%m-%y"); // Format: DD-MM-YYYY
            time << std::put_time(now_tm, "%H:%M"); // Format:  HH:MM:SS


            messages[messageID] = chati::Message(s, messageID, currentUser.userID, 1, day.str(), time.str(), false);

			currentChat.messagesID.push_back(messageID);

            createMessage(messagesContainer, messages[messageID]);
            textBox1->Text = "";
        }
    }

    static void createMessage(FlowLayoutPanel^ messagesContainer, chati::Message m)  
    {  

        Label^ newLabel = gcnew Label();  
        Panel^ messagePanel = gcnew Panel();

        newLabel->Text = gcnew String(m.text.c_str());
        newLabel->Font = gcnew Font("Arial", 15, FontStyle::Bold);
        newLabel->ForeColor = Color::White;  
        newLabel->BackColor = Color::Transparent;
		newLabel->AutoSize = true;
		newLabel->Name = m.messageID.ToString();
        newLabel->Location = Point(10, 10);
        newLabel->MouseDown += gcnew MouseEventHandler(Label_RightClick);


        Label^ timeLabel = gcnew Label();  
        timeLabel->Text = gcnew String(m.timeSent.c_str()); // Convert std::string to System::String
        timeLabel->Font = gcnew Font("Arial", 7, FontStyle::Bold);
        timeLabel->BackColor = Color::Transparent;
        timeLabel->ForeColor = Color::White;
        timeLabel->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
        timeLabel->AutoSize = true;



		messagePanel->BackColor = Color::FromArgb(55, 128, 82); // Semi-transparent background
        messagePanel->Padding = Padding(10);
        messagePanel->Margin = Padding(5);        
        messagePanel->BorderStyle = BorderStyle::FixedSingle;
        messagePanel->MouseDown += gcnew MouseEventHandler(Label_RightClick);
        messagePanel->Name = m.messageID.ToString();
        messagePanel->AutoSize = true;



        // Fix: Use Location property to move the label down instead of using Move event

        messagePanel->Controls->Add(newLabel);
        messagePanel->Controls->Add(timeLabel);


        // Fix: Use DockStyle::Right instead of 'right'


        messagesContainer->Controls->Add(messagePanel);
        messagesContainer->Controls->SetChildIndex(messagePanel, 0);
        messagesContainer->ScrollControlIntoView(messagePanel);
        
        timeLabel->Location = Point(messagePanel->Width, messagePanel->Height - 20);
    }

    static void Label_RightClick(Object^ sender, MouseEventArgs^ e)
    {
        if (e->Button == MouseButtons::Right)
        {
            // Convert System::String^ to std::string using marshal_as
            System::String^ managedTypeName = sender->GetType()->Name;
            std::string s = msclr::interop::marshal_as<std::string>(managedTypeName);

            if (s == "Label")
            {
                // Handle right-click on label  
                Label^ label = dynamic_cast<Label^>(sender);
                if (label != nullptr)
                {
                    MessageBox::Show("You right-clicked on message : " + label->Name);
                }
            }
            else if (s == "Panel")
            {
                // Handle right-click on panel
                Panel^ panel = dynamic_cast<Panel^>(sender);
                if (panel != nullptr)
                {
                    Label^ label = dynamic_cast<Label^>(panel->Controls[0]); // Get the first label in the panel  

                    if (label != nullptr)
                    {
                        MessageBox::Show("You right-clicked on message : " + label->Name);
                    }
                }
            }
        }
    }
};
