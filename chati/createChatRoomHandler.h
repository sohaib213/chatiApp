#pragma once
#include "ChatRoom.h"
#include <unordered_map>
#include <list>
#include <chrono>
#include <ctime>
#include <msclr/marshal_cppstd.h> // Include this header for string conversion
#include <iostream>
#include "AddContact.h"
#include "MessageHandler.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class createChatRoomHandler {


public:
	MessageHandler messageHandler;

	ChatRoom** currentChatRoom;
	unordered_map<int, ChatRoom>* chatRooms;
	Panel^ messagesFlowPanelsContainer;

	User** currentUser;
	unordered_map<string, User>* users;
	unordered_map<int, long long>* activity;
	unordered_map<int, chati::Message>* messages;
	//System::Collections::Generic::Dictionary<int, FlowLayoutPanel^>^% chatRoomsPanels;
    System::Collections::Generic::Dictionary<int, FlowLayoutPanel^>^ chatRoomsPanels;
	Panel^ footerContainer;
	Panel^ headerContainer;
	String^ projectRoot = Directory::GetParent(Application::StartupPath)->Parent->FullName;
	String^ imagesFolder = Path::Combine(projectRoot, "usersImages");

	void addChatRoomPanel(string contName, int chatRoomID, FlowLayoutPanel^ contactsPanel) {


		Button^ chatRoomButton = gcnew Button();
		chatRoomButton->BackColor = Color::FromArgb(60, 60, 60);
		chatRoomButton->Size = System::Drawing::Size(330, 100); // Set the size of the panel
		chatRoomButton->Location = System::Drawing::Point(0, 0); // Set the location of the panel
		chatRoomButton->Tag = chatRoomID;
		chatRoomButton->Click += gcnew EventHandler(this, &createChatRoomHandler::onChatRoomButtonClick); // Fix: Use 'this' to bind the delegate to the managed class
		chatRoomButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		chatRoomButton->FlatAppearance->BorderSize = 2;

		Label^ contactNameLabel = gcnew Label();
		contactNameLabel->AutoSize = true;
		contactNameLabel->BackColor = Color::Transparent;
		contactNameLabel->Text = gcnew System::String(contName.c_str());
		contactNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		contactNameLabel->ForeColor = Color::White;

		chatRoomButton->Controls->Add(contactNameLabel);
		contactsPanel->Controls->Add(chatRoomButton);
	}


    void onChatRoomButtonClick(Object^ sender, EventArgs^ e) {  
        Button^ chatRoom = dynamic_cast<Button^>(sender);  

        int chatRoomID = safe_cast<int>(chatRoom->Tag);  

        if (*currentChatRoom != nullptr)  
            chatRoomsPanels[(*currentChatRoom)->getChatRoomID()]->Visible = false;  

        *currentChatRoom = &(*chatRooms)[chatRoomID];  

        // Fix: Correctly access the groupName and ensure proper type handling  
        PictureBox^ chatRoomPicture = dynamic_cast<PictureBox^>(headerContainer->Controls["chatPicture"]);
		Label^ chatRoomNameLabel = dynamic_cast<Label^>(headerContainer->Controls["chatName"]);
        if (chatRoomPicture != nullptr) {  
            if ((*currentChatRoom)->getIsDual()) {  
                User* otherUser;  
                if ((*currentChatRoom)->getUsersID()[0] == (*currentUser)->getMobileNumber()) { 

					otherUser = &(*users)[(*currentChatRoom)->getUsersID()[1]];
					chatRoomNameLabel->Text = gcnew String((*currentUser)->getContactsPhones()[otherUser->getMobileNumber()].c_str());

                } else {  
                    otherUser = &(*users)[(*currentChatRoom)->getUsersID()[0]];  
					chatRoomNameLabel->Text = gcnew String((otherUser->getFirstName() + ' ' + otherUser->getLastName()).c_str());
                }  
                String^ destinationPath = Path::Combine(imagesFolder, gcnew String(otherUser->getProfilePhoto().c_str()));  
                if (File::Exists(destinationPath)) {  
                    chatRoomPicture->Image = Image::FromFile(destinationPath);  
                } else {  
                    chatRoomPicture->Image = Image::FromFile(Path::Combine(projectRoot, "defaultProfile.png"));  
                }


            } else {  
                //String^ groupPhoto = gcnew String((*currentChatRoom)->getGroupPhoto().c_str());  
                String^ destinationPath = Path::Combine(imagesFolder, "default-group.png");
                chatRoomPicture->Image = Image::FromFile(destinationPath);

				chatRoomNameLabel->Text = gcnew String((*currentChatRoom)->getGroupName().c_str());
  
            }  
        }  

        chatRoomsPanels[chatRoomID]->Visible = true;  
		
		if(chatRoomsPanels[chatRoomID]->Controls->Count > 0)
			chatRoomsPanels[chatRoomID]->ScrollControlIntoView(chatRoomsPanels[chatRoomID]->Controls[chatRoomsPanels[chatRoomID]->Controls->Count - 1]);

        footerContainer->Visible = true;
		headerContainer->Visible = true;

        (*currentChatRoom)->getMessagesID().updateMessagesSeen(*messages, *currentUser);  
    }


    void createRoom(string contNum, string contName, User* currentUser, TextBox^ addContName_field, TextBox^ addContNum_field,
        unordered_map<int, ChatRoom>& chatRooms, FlowLayoutPanel^ chatRoomsPanel, unordered_map<int, long long>& activity, Panel^ messagesContainer, unordered_map<string, User>& users) {


        addCont(*currentUser, contName, contNum);
		addCont(users[contNum], currentUser->getFirstName() + currentUser->getLastName(), currentUser->getMobileNumber());
        addContName_field->Clear();
        addContNum_field->Clear();
        MessageBox::Show("Contact added", "Success");

        ChatRoom* chatRoom = new ChatRoom(true);

        chatRoom->setChatRoomID(ChatRoom::getChatRoomsCounter());
        ChatRoom::incrementChatRoomsCounter();

        createChatRoomGUI(chatRoom->getChatRoomID(), messagesContainer);

        chatRoom->addUserPhone(currentUser->getMobileNumber());
        chatRoom->addUserPhone(contNum);

        chatRooms[chatRoom->getChatRoomID()] = *chatRoom;

        int chatRoomID = chatRoom->getChatRoomID();
        addChatRoomPanel(contName, chatRoomID, chatRoomsPanel);

        currentUser->addChatRoomID(chatRoomID);
        users[contNum].addChatRoomID(chatRoomID); // Fix: Ensure 'users' is passed by reference
        auto now = std::chrono::system_clock::now();

        // Convert it to milliseconds since epoch
        auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        auto value = now_ms.time_since_epoch();

        // Get the number of milliseconds as integer
        long long milliseconds = value.count();

        activity[chatRoomID] = milliseconds;
    }

	void createGroup(User* currentUser, unordered_map<int, ChatRoom>& chatRooms,
		Panel^ messagesContainer, CheckedListBox^ usersListBox, unordered_map<string,
		User>& users, FlowLayoutPanel^ chatRoomsPanel, string groupName,
		unordered_map<int, long long>& activity) {

		ChatRoom* chatRoom = new ChatRoom(false);
		chatRoom->setChatRoomID(ChatRoom::getChatRoomsCounter());
		chatRoom->setGroupName(groupName);
		ChatRoom::incrementChatRoomsCounter();
		createChatRoomGUI(chatRoom->getChatRoomID(), messagesContainer);

		int chatRoomID = chatRoom->getChatRoomID();

		chatRoom->addUserPhone(currentUser->getMobileNumber());
		currentUser->addChatRoomID(chatRoomID);


		msclr::interop::marshal_context context;

		for each(String ^ item in usersListBox->CheckedItems) {

			int parenIndex = item->IndexOf(" ");
			String^ phone = parenIndex > 0 ? item->Substring(0, parenIndex) : item;

			string phoneStr = context.marshal_as<std::string>(phone);

			if (users.find(phoneStr) != users.end()) {
				cout << "chatRoomId:" << users[phoneStr].getChatRoomsID().size() << endl;
				chatRoom->addUserPhone(phoneStr);
				users[phoneStr].addChatRoomID(chatRoomID);
				cout << "chatRoomId:" << users[phoneStr].getChatRoomsID().size() << endl;
			}
			else {
				MessageBox::Show("User with phone " + phone + " not found", "Error");
			}
		}

		chatRooms[chatRoomID] = *chatRoom;
		addChatRoomPanel(groupName, chatRoomID, chatRoomsPanel);

		auto now = std::chrono::system_clock::now();
		auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
		long long milliseconds = now_ms.time_since_epoch().count();
		activity[chatRoomID] = milliseconds;

		MessageBox::Show("Group created successfully!", "Success");
	}

	FlowLayoutPanel^ createChatRoomGUI(int chatRoomID, Panel^ chatsContainer) {
		FlowLayoutPanel^ chatRoomPanel = gcnew FlowLayoutPanel();
		chatRoomPanel->Name = gcnew System::String(std::to_string(chatRoomID).c_str());
		chatRoomPanel->BackColor = Color::Transparent;
		chatRoomPanel->AutoScroll = true;
		chatRoomPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		chatRoomPanel->Padding = System::Windows::Forms::Padding(2);
		chatRoomPanel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		//chatRoomPanel->Size = System::Drawing::Size(1479, 995);
		chatRoomPanel->WrapContents = false;
		chatsContainer->Controls->Add(chatRoomPanel);
		chatRoomPanel->Dock = System::Windows::Forms::DockStyle::Fill;
		chatRoomPanel->Visible = false;

		Panel^ fillerPanel = gcnew Panel();
		fillerPanel->Size = System::Drawing::Size(10, 750);
		fillerPanel->BackColor = Color::Transparent;
		chatRoomPanel->Controls->Add(fillerPanel);

		chatRoomsPanels[chatRoomID] = chatRoomPanel;

		return chatRoomPanel;

	}
};