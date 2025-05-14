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
using namespace System::IO;

public ref class MessageHandler {
public:

    unordered_map<string, User>* users;
    unordered_map<int, chati::Message>* globalMessages;
    ChatRoom** globalChatRoom;
    int messageIDToDelete;
    Panel^ panelToDelete;
    Panel^ messagesContainer;
    User** currentUser, **otherUser;
    String^ projectRoot = Directory::GetParent(Application::StartupPath)->Parent->FullName;
    String^ iconsFolder = Path::Combine(projectRoot, "icons");
    

    void initializeChat(ChatRoom* chatRoom, FlowLayoutPanel^ messagesContainer,
        unordered_map<int, chati::Message>& messages, User* currentUser, unordered_map<int, long long>& activity,
        unordered_map<string, User>* users) {

        cout << "Initializing chat..." << endl;

        messagesContainer->Controls->Clear();

        Panel^ fillerPanel = gcnew Panel();
        if (chatRoom->getIsDual() && currentUser->getContactsPhones().count((*otherUser)->getMobileNumber()) < 1)
        {
            fillerPanel->Size = System::Drawing::Size(300, 451);
            cout << "HERE 1" << endl;
        }
        else
        {
            fillerPanel->Size = System::Drawing::Size(300, 750);
            cout << "HERE 2" << endl;

        }
        

        fillerPanel->BackColor = Color::Transparent;
        messagesContainer->Controls->Add(fillerPanel);

        chati::LinkedList list1 = chatRoom->getMessagesID();

        chati::Node* temp = list1.begin();
        for (chati::Node* item = list1.begin(); item != list1.end(); item = item->next) {

            createMessage(messagesContainer, messages[item->value], chatRoom, currentUser, users, 1);

            if (item->next == list1.end())
                createDateLabel(messagesContainer, messages[item->value].getDateSent(), "", 1);
            else
                createDateLabel(messagesContainer, messages[temp->value].getDateSent(), messages[item->value].getDateSent(), 1);

            temp = item;
        }

        if (chatRoom->getIsDual() && currentUser->getContactsPhones().count((*otherUser)->getMobileNumber()) < 1)
            addConfirmContact(messagesContainer);
    }

    void createMessageEvent(RichTextBox^ textBox1, FlowLayoutPanel^ messagesContainer, User* currentUser, unordered_map<int, long long>& activity,
        FlowLayoutPanel^ chatRoomsPanel, unordered_map<int, ChatRoom>& chatRooms, ChatRoom* currentChatRoom, unordered_map<int, chati::Message> messages, unordered_map<string, User>* users) {
        if (textBox1->Text != "") {
            string s = msclr::interop::marshal_as<string>(textBox1->Text);


            auto now = chrono::system_clock::now();
            time_t now_time_t = chrono::system_clock::to_time_t(now);
            tm* now_tm = localtime(&now_time_t);

            ostringstream day, hour, minute, second;
            day << put_time(now_tm, "%d-%m-20%y"); // Format: DD-MM-YYYY
            hour << put_time(now_tm, "%H");
            minute << put_time(now_tm, "%M");
            second << put_time(now_tm, "%S");



            //? create the message to get the id directly (is better)
            chati::Message msg = chati::Message(s, currentUser->getMobileNumber(), (*globalChatRoom)->getChatRoomID(), day.str(), stoi(hour.str()), stoi(minute.str()), stoi(second.str()), false);
            // Fix: Use pointer dereference to access the map
            msg.setMessageID(chati::Message::getMessageCounter());
            chati::Message::incrementMessageCounter();


            (*globalMessages)[msg.getMessageID()] = msg;

            if ((*globalChatRoom)->getMessagesID().Length() == 0)
                createDateLabel(messagesContainer, day.str(), "", 2);
            else
                createDateLabel(messagesContainer, day.str(), messages[(*globalChatRoom)->getLastMessageID()].getDateSent(), 2);

            //update when a new message is sent
            (*globalMessages)[msg.getMessageID()] = msg;
            (*globalChatRoom)->addMessageID(msg.getMessageID());

            // Fix: Pass the dereferenced map to the createMessage function 


            createMessage(messagesContainer, (*globalMessages)[msg.getMessageID()], currentChatRoom, currentUser, users, 2);

            textBox1->Clear();
            textBox1->Focus();


            auto now1 = std::chrono::system_clock::now();

            // Convert it to milliseconds since epoch
            auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now1);
            auto value = now_ms.time_since_epoch();

            // Get the number of milliseconds as integer
            long long milliseconds = value.count();

            activity[(*globalChatRoom)->getChatRoomID()] = milliseconds;

            sortChatRooms(*currentUser, activity, chatRooms, chatRoomsPanel, messages);
        }
    }

    void createMessage(FlowLayoutPanel^ messagesContainer, chati::Message m, ChatRoom* currentChatRoom, User* currentUser, unordered_map<string, User>* users, int source)
    {

        //? picture box for the profile photo 
        //? Label for the sender name
        //? Label for the status of icon
        Panel^ messagePanel = gcnew Panel();

        Label^ messageTextLabel = gcnew Label();
        messageTextLabel->Text = gcnew String(m.getText().c_str());
        messageTextLabel->Font = gcnew Font("Arial", 15, FontStyle::Bold);
        messageTextLabel->ForeColor = Color::White;
        messageTextLabel->BackColor = Color::Transparent;
        messageTextLabel->AutoSize = true;
        messageTextLabel->Name = m.getMessageID().ToString();
        messageTextLabel->Location = Point(10, 10);
        messageTextLabel->Cursor = Cursors::IBeam;

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
        ostringstream timeStream;
        timeStream << hour << ':' << std::setw(2) << std::setfill('0') << minute;

        string time = timeStream.str() + " " + status;

        timeLabel->Text = gcnew String(time.c_str());
        timeLabel->ForeColor = Color::FromArgb(160, 160, 160);
        timeLabel->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
        timeLabel->AutoSize = true;

        PictureBox^ seenPicture = gcnew PictureBox();
        seenPicture->Size = System::Drawing::Size(17, 14);
        if (m.getIsRead()) {
            seenPicture->Image = Image::FromFile(Path::Combine(iconsFolder, "seen.png"));
        }
        else {
            seenPicture->Image = Image::FromFile(Path::Combine(iconsFolder, "un_seen.png"));
        }

        Panel^ SenderNameContainer;
        Label^ senderName;
        Label^ senderPhone;
        if (!currentChatRoom->getIsDual() && m.getSenderPhone() != currentUser->getMobileNumber())
        {
            SenderNameContainer = gcnew Panel();
            SenderNameContainer->AutoSize = true;
            //SenderNameContainer->BackColor = Color::FromArgb(150, 144, 144);
            SenderNameContainer->BackColor = Color::Transparent;

            senderName = gcnew Label();
            senderName->Text = gcnew String(((*users)[m.getSenderPhone()].getFirstName() + ' ' + (*users)[m.getSenderPhone()].getLastName()).c_str());
            senderName->AutoSize = true;
            senderName->ForeColor = Color::FromArgb(0, 200, 240);
            senderName->Font = gcnew System::Drawing::Font("Arial", 11, FontStyle::Bold);

            senderPhone = gcnew Label();
            senderPhone->Text = gcnew String(m.getSenderPhone().c_str());
            senderPhone->AutoSize = true;
            senderPhone->ForeColor = Color::FromArgb(160, 160, 160);
            senderPhone->Font = gcnew System::Drawing::Font("Arial", 11, FontStyle::Bold);

            SenderNameContainer->Controls->Add(senderName);
            SenderNameContainer->Controls->Add(senderPhone);

            SenderNameContainer->Size = Size(senderName->Width, senderName->Height);
            messagePanel->Controls->Add(SenderNameContainer);
            SenderNameContainer->Dock = DockStyle::Top;
            senderName->TextAlign = ContentAlignment::MiddleLeft;
            senderPhone->Dock = DockStyle::Right;


            messageTextLabel->Location = Point(10, SenderNameContainer->Height + 10);

        }



        if (m.getSenderPhone() == currentUser->getMobileNumber()) {
            messagePanel->BackColor = Color::FromArgb(11, 117, 66);
            messagePanel->MouseDown += gcnew MouseEventHandler(this, &MessageHandler::messageRightClick); // Fix: Use 'this' to bind the delegate to the managed class
            messageTextLabel->MouseDown += gcnew MouseEventHandler(this, &MessageHandler::messageRightClick); // Fix: Use 'this' to bind the delegate to the managed class
        }
        else {
            messagePanel->BackColor = Color::FromArgb(65, 65, 65);

        }

        messagePanel->Padding = Padding(5);
        messagePanel->Margin = Padding(5);
        messagePanel->BorderStyle = BorderStyle::FixedSingle;
        messagePanel->Name = m.getMessageID().ToString();
        messagePanel->AutoSize = true;
        //?messagePanel->ContextMenuStrip 

        messagePanel->Controls->Add(messageTextLabel);
        messagePanel->Controls->Add(timeLabel);
        if (m.getSenderPhone() == currentUser->getMobileNumber())
            messagePanel->Controls->Add(seenPicture);


        messagesContainer->Controls->Add(messagePanel);
        if (source == 1)
            messagesContainer->Controls->SetChildIndex(messagePanel, 1);
        if (source == 2)
            messagesContainer->ScrollControlIntoView(messagePanel);


        timeLabel->Location = Point(messagePanel->Width, messagePanel->Height - 20);
        if (!currentChatRoom->getIsDual() && m.getSenderPhone() != currentUser->getMobileNumber())
            timeLabel->Margin = Padding(0, 10, 0, 10);
        else
            seenPicture->Location = Point(messagePanel->Width - 10, messagePanel->Height - 20);



        if (senderName != nullptr)
        {
            if (messagePanel->Width < (senderName->Width + senderPhone->Width + 15))
            {
                int messagePanelHeight = messagePanel->Height;
                messagePanel->AutoSize = false;
                messagePanel->Size = Size(senderName->Width + senderPhone->Width + 15, messagePanelHeight);
            }

        }

        if (m.getSenderPhone() != currentUser->getMobileNumber())
        {
            messagePanel->Margin = Padding(1460 - messagePanel->Width, 3, 3, 3);
            messagePanel->Anchor = AnchorStyles::Left;
            messagePanel->Dock = DockStyle::Left;
        }
        else
            messagePanel->Margin = Padding(30, 3, 3, 3);
    }

    void createDateLabel(FlowLayoutPanel^ messagesContainer, string currentDay, string previousDay, int source) {
        if (messagesContainer->Controls->Count == 0 || currentDay != previousDay) {


            Label^ dateLabel = gcnew Label();
            dateLabel->Text = gcnew String(currentDay.c_str());
            dateLabel->Font = gcnew Font("Arial", 15, FontStyle::Bold);
            dateLabel->ForeColor = Color::White;
            dateLabel->BackColor = Color::FromArgb(87, 83, 83);
            dateLabel->AutoSize = true;

            messagesContainer->Controls->Add(dateLabel);
            if (source == 1)
                messagesContainer->Controls->SetChildIndex(dateLabel, 1);
            dateLabel->Margin = Padding(750, 10, 3, 10);

        }
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

    void messageOptions(Panel^ panel, Label^ label, FlowLayoutPanel^ messagesContainer) {

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


        (*globalChatRoom)->deleteMessageID(messageIDToDelete);
        int x = messageIDToDelete;
        globalMessages->erase(x);
        messagesContainer->Controls->Remove(panelToDelete);
    }

    void addConfirmContact(FlowLayoutPanel^ messagesContainer) {
        // confirm Panel
        Panel^ confirmContactPanel;
        Label^ confirmRequestMessageLabel;
        Button^ noButton;
        Button^ okButton;
        confirmContactPanel = gcnew Panel();
        confirmRequestMessageLabel = gcnew Label();
        noButton = gcnew Button();
        okButton = gcnew Button();

        confirmContactPanel->SuspendLayout();
        messagesContainer->Controls->Add(confirmContactPanel);
        // confirmContactPanel
    // 
        confirmContactPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)),
            static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(75)));
        confirmContactPanel->Controls->Add(confirmRequestMessageLabel);
        confirmContactPanel->Controls->Add(noButton);
        confirmContactPanel->Controls->Add(okButton);
        confirmContactPanel->Location = System::Drawing::Point(320, 277);
        confirmContactPanel->Name = L"confirmContactPanel";
        confirmContactPanel->Size = System::Drawing::Size(844, 339);
        confirmContactPanel->TabIndex = 1;
        confirmContactPanel->BorderStyle = BorderStyle::FixedSingle;
        // 
        // confirmRequestMessageLabel
        // 
        confirmRequestMessageLabel->AutoSize = true;
        confirmRequestMessageLabel->BackColor = System::Drawing::Color::Transparent;
        confirmRequestMessageLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        confirmRequestMessageLabel->ForeColor = System::Drawing::Color::White;
        confirmRequestMessageLabel->Location = System::Drawing::Point(180, 58);
        confirmRequestMessageLabel->Name = L"confirmRequestMessageLabel";
        confirmRequestMessageLabel->Size = System::Drawing::Size(460, 62);
        confirmRequestMessageLabel->TabIndex = 3;
        confirmRequestMessageLabel->Text = gcnew String(((*otherUser)->getFirstName() + ' ' + (*otherUser)->getLastName() + " Sent You Contact Request\r\n             Do You Accept Him\r\n").c_str());
        // 
        // noButton
        // 
        noButton->Cursor = System::Windows::Forms::Cursors::Hand;
        noButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        noButton->Location = System::Drawing::Point(179, 266);
        noButton->Name = L"noButton";
        noButton->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
        noButton->Size = System::Drawing::Size(98, 45);
        noButton->TabIndex = 2;
        noButton->Text = L"NO";
        noButton->UseVisualStyleBackColor = true;
        noButton->Click += gcnew EventHandler(this, &MessageHandler::NoButtonClicked);
        // 
        // okButton
        // 
        okButton->Cursor = System::Windows::Forms::Cursors::Hand;
        okButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        okButton->Location = System::Drawing::Point(579, 266);
        okButton->Name = L"okButton";
        okButton->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
        okButton->Size = System::Drawing::Size(98, 45);
        okButton->TabIndex = 1;
        okButton->Text = L"OK";
        okButton->UseVisualStyleBackColor = true;
        okButton->Click += gcnew EventHandler(this, &MessageHandler::OkButtonClicked);


        confirmContactPanel->ResumeLayout(false);
        messagesContainer->Controls->SetChildIndex(confirmContactPanel, 1);

        confirmContactPanel->PerformLayout();
    }
    void OkButtonClicked(Object^ sender, EventArgs^ e) {

        Button^ okButton = dynamic_cast<Button^>(sender);
        Panel^ confirmMessagePanel = dynamic_cast<Panel^>(okButton->Parent);
        FlowLayoutPanel^ messageContainer = dynamic_cast<FlowLayoutPanel^>(confirmMessagePanel->Parent);

        // Fix: Use dynamic_cast to convert the Control^ to Panel^
        Panel^ fillerPanel = dynamic_cast<Panel^>(messageContainer->Controls[0]);

        fillerPanel->Size = Size(300, 750);
        messageContainer->Controls->Remove(confirmMessagePanel);



        cout << "Added: " << (*currentUser)->addContactPhone((*otherUser)->getMobileNumber(), (*otherUser)->getFirstName() + ' ' + (*otherUser)->getLastName()) << endl;
    }
    void NoButtonClicked(Object^ sender, EventArgs^ e) {

        Button^ okButton = dynamic_cast<Button^>(sender);
        Panel^ confirmMessagePanel = dynamic_cast<Panel^>(okButton->Parent);
        FlowLayoutPanel^ messageContainer = dynamic_cast<FlowLayoutPanel^>(confirmMessagePanel->Parent);

        Panel^ fillerPanel = dynamic_cast<Panel^>(messageContainer->Controls[0]);


        fillerPanel->Size = Size(300, 750);
        messageContainer->Controls->Remove(confirmMessagePanel);

    }
};
