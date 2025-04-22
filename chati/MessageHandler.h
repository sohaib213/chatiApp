#pragma once  
#include <string>
#include "Message.h"
#include "ChatRoom.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace System;  
using namespace System::Windows::Forms;  
using namespace System::Drawing;



ref class MessageHandler {  
public:

    unordered_map<int, chati::Message>* globalMessages;
    ChatRoom* globalChatRoom;

    void initializeChat(ChatRoom *chatRoom, FlowLayoutPanel^ messagesContainer, 
                               unordered_map<int, chati::Message>& messages, User *currentUser) {

		cout << "Initializing chat..." << endl;
        for(auto& messageID : chatRoom->getMessagesID()) {
            createMessage(messagesContainer, messages[messageID], messages);
		}
		globalMessages = &messages;
		globalChatRoom = chatRoom;
    }
    //ContextMenuStrip^ BuildStandardContextMenu()
    //{
    //    ContextMenuStrip^ menu = gcnew ContextMenuStrip();

    //    ToolStripMenuItem^ deleteItem = gcnew ToolStripMenuItem("Delete");
    //    ToolStripMenuItem^ infoItem = gcnew ToolStripMenuItem("Info");

    //    //deleteItem->Click += gcnew EventHandler(this, &YourForm::DeleteMessage_Click);
    //    //infoItem->Click += gcnew EventHandler(this, &YourForm::InfoMessage_Click);

    //    menu->Items->Add(deleteItem);
    //    menu->Items->Add(infoItem);

    //    return menu;
    //}

   void createMessageEvent(RichTextBox^ textBox1, FlowLayoutPanel^ messagesContainer, User currentUser) {  
       if (textBox1->Text != "") {  
           string s = msclr::interop::marshal_as<string>(textBox1->Text);  


           auto now = chrono::system_clock::now();  
           time_t now_time_t = chrono::system_clock::to_time_t(now);  
           tm* now_tm = localtime(&now_time_t);  

           ostringstream day, time;  
           day << std::put_time(now_tm, "%d-%m-%y"); // Format: DD-MM-YYYY  
           time << std::put_time(now_tm, "%H:%M");  // Format: HH:MM  

           //? create the message to get the id directly (is better)
		   chati::Message msg =  chati::Message(s,currentUser.getUserID(), globalChatRoom->getChatRoomID(), day.str(), time.str(), false);
           // Fix: Use pointer dereference to access the map  
		   (*globalMessages)[msg.getMessageID()] = msg; 
           globalChatRoom->addMessageID(msg.getMessageID());

           // Fix: Pass the dereferenced map to the createMessage function  
           createMessage(messagesContainer, (*globalMessages)[msg.getMessageID()], *globalMessages);
           textBox1->Clear();
		   textBox1->Focus();
       }  
   }

    void createMessage(FlowLayoutPanel^ messagesContainer, chati::Message m, unordered_map<int, chati::Message>& messages)
    {  
		//? picture box for the profile photo 
		//? Label for the sender name
        //? Label for the status of icon
        Label^ newLabel = gcnew Label();  
        Panel^ messagePanel = gcnew Panel();

        newLabel->Text = gcnew String(m.getText().c_str());
        newLabel->Font = gcnew Font("Arial", 15, FontStyle::Bold);
        newLabel->ForeColor = Color::White;  
        newLabel->BackColor = Color::Transparent;
        newLabel->AutoSize = true;
        newLabel->Name = m.getMessageID().ToString();
        newLabel->Location = Point(10, 10);
        newLabel->MouseDown += gcnew MouseEventHandler(this, &MessageHandler::Label_RightClick); // Fix: Use 'this' to bind the delegate to the managed class
        newLabel->Cursor = Cursors::IBeam;

        Label^ timeLabel = gcnew Label();  
        timeLabel->Text = gcnew String(m.getTimeSent().c_str());
        timeLabel->Font = gcnew Font("Arial", 9, FontStyle::Bold);
        timeLabel->BackColor = Color::Transparent;
        timeLabel->ForeColor = Color::White;
        timeLabel->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
        timeLabel->AutoSize = true;



		messagePanel->BackColor = Color::FromArgb(55, 128, 82); // Semi-transparent background
        messagePanel->Padding = Padding(10);
        messagePanel->Margin = Padding(5);        
        messagePanel->BorderStyle = BorderStyle::FixedSingle;
        messagePanel->MouseDown += gcnew MouseEventHandler(this, &MessageHandler::Label_RightClick); // Fix: Use 'this' to bind the delegate to the managed class
        messagePanel->Name = m.getMessageID().ToString();
        messagePanel->AutoSize = true;
		//?messagePanel->ContextMenuStrip 

        messagePanel->Controls->Add(newLabel);
        messagePanel->Controls->Add(timeLabel);

        messagesContainer->Controls->Add(messagePanel);
        messagesContainer->Controls->SetChildIndex(messagePanel, 0);
        messagesContainer->ScrollControlIntoView(messagePanel);
        
        timeLabel->Location = Point(messagePanel->Width, messagePanel->Height - 20);
    }

    void Label_RightClick(Object^ sender, MouseEventArgs^ e)
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
                    // Fix: Explicitly cast Parent->Parent to FlowLayoutPanel^
                    FlowLayoutPanel^ messagesContainer = dynamic_cast<FlowLayoutPanel^>(label->Parent->Parent);
                    Panel^ panel = dynamic_cast<Panel^>(label->Parent);

                    if (messagesContainer != nullptr)
                    {
                        deleteMessage(messagesContainer, Convert::ToInt32(label->Name), panel);
                    }
                }
            }
            else if (s == "Panel")
            {
                // Handle right-click on panel
                Panel^ panel = dynamic_cast<Panel^>(sender);
                if (panel != nullptr)
                {
                    Label^ label = dynamic_cast<Label^>(panel->Controls[0]); 

                    if (label != nullptr)
                    {
                        FlowLayoutPanel^ messagesContainer = dynamic_cast<FlowLayoutPanel^>(label->Parent->Parent);

                        if (messagesContainer != nullptr)
                        {
                            deleteMessage(messagesContainer, Convert::ToInt32(label->Name), panel);
                        }
                    }
                }
            }
        }
    }

     void deleteMessage(FlowLayoutPanel^ messagesContainer, int messageID, Panel^ panel) {

		 globalChatRoom->deleteMessageID(messageID);
		 globalMessages->erase(messageID);
		 messagesContainer->Controls->Remove(panel);
     }
};
