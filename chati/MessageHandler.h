#pragma once  
#include <string>
#include "Message.h"
#include "ChatRoom.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "User.h" // Keep this include
#include "Sort.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;


public ref class MessageHandler {  
public:

    unordered_map<int, chati::Message>* globalMessages;
    ChatRoom* globalChatRoom;
	int messageIDToDelete;
	Panel^ panelToDelete;
	Panel^ messagesContainer;
	User* currentUser;

    void initializeChat(ChatRoom *chatRoom, FlowLayoutPanel^ messagesContainer, 
        unordered_map<int, chati::Message>& messages, User *currentUser, unordered_map<int, long long>& activity) {

		cout << "Initializing chat..." << endl;

		messagesContainer->Controls->Clear();


        //// intialize map
        //if (!chatRoom->getMessagesID().empty()) {
        //    int lastID = chatRoom->getLastMessageID();
        //    activity[chatRoom->getChatRoomID()] = lastID;
        //}


        for(auto& messageID : chatRoom->getMessagesID()) {
            createMessage(messagesContainer, messages[messageID], chatRoom, currentUser);
		}

    }

   void createMessageEvent(RichTextBox^ textBox1, FlowLayoutPanel^ messagesContainer, User *currentUser, unordered_map<int, long long>& activity,
       FlowLayoutPanel^ chatRoomsPanel, unordered_map<int, ChatRoom>& chatRooms, ChatRoom* currentChatRoom, unordered_map<int, chati::Message> messages) {
       if (textBox1->Text != "") {  
           string s = msclr::interop::marshal_as<string>(textBox1->Text);  

		   globalChatRoom = currentChatRoom;

           auto now = chrono::system_clock::now();  
           time_t now_time_t = chrono::system_clock::to_time_t(now);  
           tm* now_tm = localtime(&now_time_t);  

           ostringstream day, hour, minute;  
           day << put_time(now_tm, "%d-%m-%y"); // Format: DD-MM-YYYY  
           hour << put_time(now_tm, "%H"); 
           minute << put_time(now_tm, "%M"); 


           //? create the message to get the id directly (is better)
           chati::Message msg = chati::Message(s, currentUser->getMobileNumber(), globalChatRoom->getChatRoomID(), day.str(), stoi(hour.str()), stoi(minute.str()), false);
           // Fix: Use pointer dereference to access the map
		   msg.setMessageID(chati::Message::getMessageCounter());
		   chati::Message::incrementMessageCounter();


           (*globalMessages)[msg.getMessageID()] = msg;


           //update when a new message is sent
           (*globalMessages)[msg.getMessageID()] = msg;
           globalChatRoom->addMessageID(msg.getMessageID());

           


           globalChatRoom->addMessageID(msg.getMessageID());
           // Fix: Pass the dereferenced map to the createMessage function 
           

           createMessage(messagesContainer, (*globalMessages)[msg.getMessageID()], currentChatRoom, currentUser);

           textBox1->Clear();
		   textBox1->Focus();


           auto now1 = std::chrono::system_clock::now();

           // Convert it to milliseconds since epoch
           auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now1);
           auto value = now_ms.time_since_epoch();

           // Get the number of milliseconds as integer
           long long milliseconds = value.count();
           
           activity[globalChatRoom->getChatRoomID()] = milliseconds;

           sortChatRooms(*currentUser, activity, chatRooms, chatRoomsPanel, messages);
       }  
   }

    void createMessage(FlowLayoutPanel^ messagesContainer, chati::Message m, ChatRoom* currentChatRoom, User* currentUser)
    {  

        globalChatRoom = currentChatRoom;

        cout << "Chat room ID From MessageHandler: " << globalChatRoom->getChatRoomID() << endl;

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
        newLabel->Cursor = Cursors::IBeam;

        Label^ timeLabel = gcnew Label();
		int hour = m.getHourSent();
		int minute = m.getMinuteSent();
        timeLabel->Font = gcnew Font("Arial", 9, FontStyle::Bold);
        timeLabel->BackColor = Color::Transparent;
        // Replace the problematic line with the following code to fix the error:
        string status;
        if (hour >= 12) {
            hour %= 12;
			status = "AM";
        }
        else {
			status = "PM";
        }
        std::ostringstream timeStream;
        timeStream << hour << ':' << std::setw(2) << std::setfill('0') << minute;
        
		string time = timeStream.str() + " " + status;

        timeLabel->Text = gcnew String(time.c_str());
        string text = msclr::interop::marshal_as<std::string>(timeLabel->Text);
        timeLabel->ForeColor = Color::White;
        timeLabel->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
        timeLabel->AutoSize = true;

		PictureBox^ seenPicture = gcnew PictureBox();
		seenPicture->Size = System::Drawing::Size(17, 14);
        if(m.getIsRead()) {
            seenPicture->Image = Image::FromFile("icons/seen.png");
        } else {
            seenPicture->Image = Image::FromFile("icons/un_seen.png");
		}


        cout << "TEST 1\n";
        if(m.getSenderPhone() == currentUser->getMobileNumber()) {
            messagePanel->BackColor = Color::FromArgb(55, 128, 82);
            messagePanel->MouseDown += gcnew MouseEventHandler(this, &MessageHandler::messageRightClick); // Fix: Use 'this' to bind the delegate to the managed class
            newLabel->MouseDown += gcnew MouseEventHandler(this, &MessageHandler::messageRightClick); // Fix: Use 'this' to bind the delegate to the managed class
        } else {
            messagePanel->BackColor = Color::Gray;

		}
        cout << "TEST 2\n";

        messagePanel->Padding = Padding(5);
        messagePanel->Margin = Padding(5);        
        messagePanel->BorderStyle = BorderStyle::FixedSingle;
        messagePanel->Name = m.getMessageID().ToString();
        messagePanel->AutoSize = true;
		//?messagePanel->ContextMenuStrip 

        messagePanel->Controls->Add(newLabel);
        messagePanel->Controls->Add(timeLabel);
        if(m.getSenderPhone() == currentUser->getMobileNumber())
            messagePanel->Controls->Add(seenPicture);


        messagesContainer->Controls->Add(messagePanel);
        messagesContainer->Controls->SetChildIndex(messagePanel, 0);
        messagesContainer->ScrollControlIntoView(messagePanel);
        
        timeLabel->Location = Point(messagePanel->Width,  messagePanel->Height - 20);
		seenPicture->Location = Point(messagePanel->Width - 10, messagePanel->Height - 20);

        if (m.getSenderPhone() != currentUser->getMobileNumber())
        {
            messagePanel->Margin = Padding(1480 - messagePanel->Width, 3, 3, 3);
			messagePanel->Anchor = AnchorStyles::Left;
			messagePanel->Dock = DockStyle::Left;
        }
        else
            messagePanel->Margin = Padding(3, 3, 50, 3);
    }
    

    void messageRightClick(Object^ sender, MouseEventArgs^ e)
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

                        messageOptions(panel, label, messagesContainer);
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
                            messageOptions(panel, label, messagesContainer);
                    }
                }
            }
        }
    }

    void messageOptions( Panel^ panel, Label^ label, FlowLayoutPanel^ messagesContainer) {

        ContextMenuStrip^ contextMenu = gcnew ContextMenuStrip();

        messageIDToDelete = Convert::ToInt32(label->Name);
        panelToDelete = panel;
        this->messagesContainer = messagesContainer;

        // Add menu item
        ToolStripMenuItem^ deleteItem = gcnew ToolStripMenuItem("Delete Message");
        contextMenu->Items->Add(deleteItem);

	    deleteItem->Name = panel->Controls[0]->Name;

        deleteItem->Click += gcnew EventHandler(this, &MessageHandler::deleteMessage);

        contextMenu->Show(Control::MousePosition);
    }

    void deleteMessage(Object^ sender, EventArgs^ e) {

         ToolStripMenuItem^ optionDelete = dynamic_cast<ToolStripMenuItem^>(sender);


         globalChatRoom->deleteMessageID(messageIDToDelete);
         int x = messageIDToDelete;
		 globalMessages->erase(x);
         messagesContainer->Controls->Remove(panelToDelete);
	 }
};
