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
	Panel^ chatsContainer;
	User* currentUser;
	unordered_map<int, long long>* activity;
	unordered_map<int, chati::Message>* messages;
	//System::Collections::Generic::Dictionary<int, FlowLayoutPanel^>^% chatRoomsPanels;
    System::Collections::Generic::Dictionary<int, FlowLayoutPanel^>^ chatRoomsPanels;

	void addChatRoomPanel(string contName, int chatRoomID, FlowLayoutPanel^ contactsPanel) {
		Button^ chatRoomButton = gcnew Button();
		chatRoomButton->BackColor = Color::Black;
		chatRoomButton->Size = System::Drawing::Size(338, 100); // Set the size of the panel
		chatRoomButton->Location = System::Drawing::Point(0, 0); // Set the location of the panel
		chatRoomButton->Tag = chatRoomID;
		chatRoomButton->Click += gcnew EventHandler(this, &createChatRoomHandler::onChatRoomButtonClick); // Fix: Use 'this' to bind the delegate to the managed class


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

		*currentChatRoom = &(*chatRooms)[chatRoomID];

		cout << "Current Chat Room ID" << (*currentChatRoom)->getChatRoomID() << endl;

		chatRoomsPanels[chatRoomID]->BringToFront();

		cout << chatRoomsPanels->Values->Count << endl;
    }


	void createRoom(string currentNum, string contName, User* currentUser, TextBox^ addContName_field, TextBox^ addContNum_field,
		unordered_map<int, ChatRoom>& chatRooms, FlowLayoutPanel^ chatRoomsPanel, unordered_map<int, long long>& activity, Panel^ messagesContainer) {

		addCont(currentUser, contName, currentNum);
		addContName_field->Clear();
		addContNum_field->Clear();
		MessageBox::Show("Contact added", "Success");


		ChatRoom* chatRoom = new ChatRoom(true);

		chatRoom->setChatRoomID(ChatRoom::getChatRoomsCounter());
		ChatRoom::incrementChatRoomsCounter();


		createChatRoomGUI(chatRoom->getChatRoomID(), messagesContainer);


		chatRoom->addUserPhone(currentUser->getMobileNumber());
		chatRoom->addUserPhone(contName);


		chatRooms[chatRoom->getChatRoomID()] = *chatRoom;


		int chatRoomID = chatRoom->getChatRoomID();
		addChatRoomPanel(contName, chatRoomID, chatRoomsPanel);


		currentUser->addChatRoomID(chatRoomID);

		auto now = std::chrono::system_clock::now();

		// Convert it to milliseconds since epoch
		auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
		auto value = now_ms.time_since_epoch();

		// Get the number of milliseconds as integer
		long long milliseconds = value.count();

		activity[chatRoomID] = milliseconds;
		cout << "TESTING 3" << endl;

	}

	FlowLayoutPanel^ createChatRoomGUI(int chatRoomID, Panel^ chatsContainer) {
		FlowLayoutPanel^ chatRoomPanel = gcnew FlowLayoutPanel();
		chatRoomPanel->Name = gcnew System::String(std::to_string(chatRoomID).c_str());
		chatRoomPanel->BackColor = Color::Transparent;
		chatRoomPanel->AutoScroll = true;
		chatRoomPanel->Dock = System::Windows::Forms::DockStyle::Fill;
		chatRoomPanel->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
		chatRoomPanel->Location = System::Drawing::Point(0, 0);
		chatRoomPanel->Padding = System::Windows::Forms::Padding(2);
		chatRoomPanel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		chatRoomPanel->Size = System::Drawing::Size(1479, 995);
		chatRoomPanel->TabIndex = 2;
		chatRoomPanel->WrapContents = false;
		chatsContainer->Controls->Add(chatRoomPanel);
		chatRoomPanel->SendToBack();

		chatRoomsPanels[chatRoomID] = chatRoomPanel;

		return chatRoomPanel;

	}
};