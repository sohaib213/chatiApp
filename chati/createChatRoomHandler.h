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
#include "User.h"


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

		ChatRoom* chatRoom = &(*chatRooms)[chatRoomID];

		User* otherUser;
		String^ imagePath;
		if (chatRoom->getIsDual()) {
			if (chatRoom->getUsersID()[0] == (*currentUser)->getMobileNumber())
				otherUser = &(*users)[chatRoom->getUsersID()[1]];
			else
				otherUser = &(*users)[chatRoom->getUsersID()[0]];

			string otherUserPhone = otherUser->getMobileNumber();
			string photoName = (*users)[otherUserPhone].getProfilePhoto();
			imagePath = Path::Combine(imagesFolder, gcnew String(photoName.c_str()));
		}
		else {
			// For group chat, get group image
			string photoName = chatRoom->getGroupPhoto();
			imagePath = Path::Combine(imagesFolder, gcnew String(photoName.c_str()));
		}


		//chatroom button
		Button^ chatRoomButton = gcnew Button();
		chatRoomButton->BackColor = Color::FromArgb(60, 60, 60);
		chatRoomButton->Size = System::Drawing::Size(contactsPanel->Width - 5, 80); // Set the size of the panel
		chatRoomButton->Location = System::Drawing::Point(0, 0); // Set the location of the panel
		chatRoomButton->Dock = DockStyle::Top;
		chatRoomButton->Padding = Padding(5);
		chatRoomButton->Tag = chatRoomID;
		chatRoomButton->Click += gcnew EventHandler(this, &createChatRoomHandler::onChatRoomButtonClick); // Fix: Use 'this' to bind the delegate to the managed class
		chatRoomButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		chatRoomButton->FlatAppearance->BorderSize = 1;
		chatRoomButton->TextAlign = ContentAlignment::MiddleLeft;
		chatRoomButton->FlatAppearance->MouseOverBackColor = Color::FromArgb(80, 80, 80);


		//contact label
		Label^ contactNameLabel = gcnew Label();
		contactNameLabel->AutoSize = true;
		contactNameLabel->BackColor = Color::Transparent;
		contactNameLabel->Text = gcnew System::String(contName.c_str());
		contactNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		contactNameLabel->ForeColor = Color::White;
		contactNameLabel->Location = System::Drawing::Point(60, 10);
		contactNameLabel->Click += gcnew System::EventHandler(this, &createChatRoomHandler::onChatRoomButtonClick);

		contactNameLabel->MouseEnter += gcnew EventHandler(this, &createChatRoomHandler::HoverEnter);
		contactNameLabel->MouseLeave += gcnew EventHandler(this, &createChatRoomHandler::HoverLeave);

		// contact/group image
		PictureBox^ profilePic = gcnew PictureBox();
		profilePic->Size = System::Drawing::Size(50, 50);
		profilePic->Location = System::Drawing::Point(5, 10);
		profilePic->Image = Image::FromFile(imagePath);
		profilePic->SizeMode = PictureBoxSizeMode::Zoom;
		profilePic->BackColor = Color::Transparent;
		profilePic->Click += gcnew System::EventHandler(this, &createChatRoomHandler::onChatRoomButtonClick);
		profilePic->MouseEnter += gcnew EventHandler(this, &createChatRoomHandler::HoverEnter);

		profilePic->MouseLeave += gcnew EventHandler(this, &createChatRoomHandler::HoverLeave);


		chatRoomButton->Controls->Add(profilePic);
		chatRoomButton->Controls->Add(contactNameLabel);
		contactsPanel->Controls->Add(chatRoomButton);

		chatRoomButton->MouseDown += gcnew MouseEventHandler(this, &createChatRoomHandler::ChatRoomRightClick);
		contactNameLabel->MouseDown += gcnew MouseEventHandler(this, &createChatRoomHandler::ChatRoomRightClick);
		profilePic->MouseDown += gcnew MouseEventHandler(this, &createChatRoomHandler::ChatRoomRightClick);

	}


	void HoverEnter(Object^ sender, EventArgs^ e)
	{
		System::String^ managedTypeName = sender->GetType()->Name;
		std::string s = msclr::interop::marshal_as<std::string>(managedTypeName);
		Button^ panelButton;
		int chatRoomID;
		if (s == "PictureBox")
		{
			cout << "Enter PictureBox" << endl;
			PictureBox^ pictureBox = dynamic_cast<PictureBox^>(sender);
			panelButton = dynamic_cast<Button^>(pictureBox->Parent);

		}
		else if (s == "Label") {
			Label^ label = dynamic_cast<Label^>(sender);
			panelButton = dynamic_cast<Button^>(label->Parent);
		}

		if (panelButton != nullptr) {
			cout << "Change Color" << endl;
			panelButton->BackColor = Color::FromArgb(80, 80, 80);
		}
	}

	void HoverLeave(Object^ sender, EventArgs^ e)
	{
		System::String^ managedTypeName = sender->GetType()->Name;
		std::string s = msclr::interop::marshal_as<std::string>(managedTypeName);
		Button^ panelButton;
		int chatRoomID;
		if (s == "PictureBox")
		{
			PictureBox^ pictureBox = dynamic_cast<PictureBox^>(sender);
			panelButton = dynamic_cast<Button^>(pictureBox->Parent);

		}
		else if (s == "Label") {
			Label^ label = dynamic_cast<Label^>(sender);
			panelButton = dynamic_cast<Button^>(label->Parent);
		}

		if (panelButton != nullptr) {
			panelButton->BackColor = Color::FromArgb(60, 60, 60);
		}
	}
	void ChatRoomRightClick(Object^ sender, MouseEventArgs^ e) {
		if (e->Button == MouseButtons::Right) {
			Button^ targetButton = nullptr;

			// Find the parent Button control regardless of what was clicked
			Control^ control = dynamic_cast<Control^>(sender);
			while (control != nullptr && dynamic_cast<Button^>(control) == nullptr) {
				control = control->Parent;
			}

			targetButton = dynamic_cast<Button^>(control);

			if (targetButton != nullptr) {

				int chatRoomID = safe_cast<int>(targetButton->Tag);
				ChatRoom* chatRoom = &(*chatRooms)[chatRoomID];

				ContextMenu^ contextMenu = gcnew ContextMenu();

				if (chatRoom->getIsDual()) {
					MenuItem^ deleteOption = gcnew MenuItem("Delete");
					deleteOption->Click += gcnew EventHandler(this, &createChatRoomHandler::deleteContact);
					contextMenu->MenuItems->Add(deleteOption);
				}
				else {
					MenuItem^ leaveOption = gcnew MenuItem("Leave");
					leaveOption->Click += gcnew EventHandler(this, &createChatRoomHandler::leaveGroup);
					contextMenu->MenuItems->Add(leaveOption);
				}

				// Show the context menu at the mouse position
				contextMenu->Show(targetButton, Point(e->X, e->Y));
			}
		}
	}
	void deleteContact(Object^ sender, EventArgs^ e) {


		MenuItem^ menuItem = dynamic_cast<MenuItem^>(sender);
		ContextMenu^ contextMenu = dynamic_cast<ContextMenu^>(menuItem->Parent);

		// Get the button that owns the context menu
		Button^ targetButton = dynamic_cast<Button^>(contextMenu->SourceControl);
		int chatRoomID = safe_cast<int>(targetButton->Tag);

		ChatRoom* chatRoom = &(*chatRooms)[chatRoomID];


		User* otherUser;
		if (chatRoom->getUsersID()[0] == (*currentUser)->getMobileNumber())
			otherUser = &(*users)[chatRoom->getUsersID()[1]];
		else
			otherUser = &(*users)[chatRoom->getUsersID()[0]];

		otherUser->removeChatRoomID(chatRoom->getChatRoomID());
		(*currentUser)->removeChatRoomID(chatRoom->getChatRoomID());
		otherUser->removeContactPhone((*currentUser)->getMobileNumber());
		(*currentUser)->removeContactPhone(otherUser->getMobileNumber());

		chatRooms->erase(chatRoom->getChatRoomID());


		FlowLayoutPanel^ contactsPanel = dynamic_cast<FlowLayoutPanel^>(targetButton->Parent);
		if (contactsPanel != nullptr) {
			contactsPanel->Controls->Remove(targetButton);
		}

		// b) Remove the messages panel
		if (chatRoomsPanels->ContainsKey(chatRoom->getChatRoomID())) {
			messagesFlowPanelsContainer->Controls->Remove(chatRoomsPanels[chatRoom->getChatRoomID()]);
			chatRoomsPanels->Remove(chatRoom->getChatRoomID());
		}
		MessageBox::Show("Contact deleted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	void leaveGroup(Object^ sender, EventArgs^ e) {

		MenuItem^ menuItem = dynamic_cast<MenuItem^>(sender);
		ContextMenu^ contextMenu = dynamic_cast<ContextMenu^>(menuItem->Parent);

		Button^ targetButton = dynamic_cast<Button^>(contextMenu->SourceControl);
		int chatRoomID = safe_cast<int>(targetButton->Tag);

		ChatRoom* chatRoom = &(*chatRooms)[chatRoomID];

		if (chatRoom->getAdminID() == (*currentUser)->getMobileNumber()) {
			chatRoom->setAdminID(chatRoom->getUsersID()[1]);

			std::string adminId = chatRoom->getAdminID();
			System::String^ adminIdStr = gcnew System::String(adminId.c_str());

			MessageBox::Show("Admin will be assigned to " + adminIdStr, "Info");

		}

		(*currentUser)->removeChatRoomID(chatRoom->getChatRoomID());

		//Remove ui
		FlowLayoutPanel^ contactsPanel = dynamic_cast<FlowLayoutPanel^>(targetButton->Parent);
		if (contactsPanel != nullptr) {
			contactsPanel->Controls->Remove(targetButton);
		}

		if (chatRoomsPanels->ContainsKey(chatRoomID)) {
			messagesFlowPanelsContainer->Controls->Remove(chatRoomsPanels[chatRoomID]);
			chatRoomsPanels->Remove(chatRoomID);
		}

		// If this was the current chat room, clear the display
		if (*currentChatRoom && (*currentChatRoom)->getChatRoomID() == chatRoomID) {
			*currentChatRoom = nullptr;
			footerContainer->Visible = false;
			headerContainer->Visible = false;
		}
		MessageBox::Show("You left the group successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	void onChatRoomButtonClick(Object^ sender, EventArgs^ e) {

		System::String^ managedTypeName = sender->GetType()->Name;
		std::string s = msclr::interop::marshal_as<std::string>(managedTypeName);
		int chatRoomID;
		if (s == "Button")
		{
			Button^ chatRoom = dynamic_cast<Button^>(sender);
			chatRoomID = safe_cast<int>(chatRoom->Tag);
		}
		else if (s == "Label") {
			Label^ chatRoom = dynamic_cast<Label^>(sender);
			chatRoomID = safe_cast<int>(chatRoom->Parent->Tag);
		}
		else if (s == "PictureBox") {
			PictureBox^ chatRoom = dynamic_cast<PictureBox^>(sender);
			chatRoomID = safe_cast<int>(chatRoom->Parent->Tag);
		}


		if (*currentChatRoom != nullptr)
			chatRoomsPanels[(*currentChatRoom)->getChatRoomID()]->Visible = false;

		*currentChatRoom = &(*chatRooms)[chatRoomID];

		// Fix: Correctly access the groupName and ensure proper type handling  
		PictureBox^ chatRoomPicture = dynamic_cast<PictureBox^>(headerContainer->Controls["chatPicture"]);
		PictureBox^ addMemPic = dynamic_cast<PictureBox^>(headerContainer->Controls["addMemPicBox"]);
		Label^ chatRoomNameLabel = dynamic_cast<Label^>(headerContainer->Controls["chatName"]);
		if (chatRoomPicture != nullptr) {
			if ((*currentChatRoom)->getIsDual()) {
				addMemPic->Visible = false;
				User* otherUser;
				if ((*currentChatRoom)->getUsersID()[0] == (*currentUser)->getMobileNumber()) {

					otherUser = &(*users)[(*currentChatRoom)->getUsersID()[1]];
					chatRoomNameLabel->Text = gcnew String((*currentUser)->getContactsPhones()[otherUser->getMobileNumber()].c_str());

				}
				else {
					otherUser = &(*users)[(*currentChatRoom)->getUsersID()[0]];
					chatRoomNameLabel->Text = gcnew String((otherUser->getFirstName() + ' ' + otherUser->getLastName()).c_str());
				}
				String^ destinationPath = Path::Combine(imagesFolder, gcnew String(otherUser->getProfilePhoto().c_str()));
				if (File::Exists(destinationPath)) {
					chatRoomPicture->Image = Image::FromFile(destinationPath);
				}
				else {
					chatRoomPicture->Image = Image::FromFile(Path::Combine(projectRoot, "defaultProfile.png"));
				}


			}
			else if ((*currentChatRoom)->getAdminID() == (*currentUser)->getMobileNumber()) {

				String^ groupPhoto = Path::Combine(imagesFolder, gcnew String((*currentChatRoom)->getGroupPhoto().c_str()));
				addMemPic->Visible = true;
				chatRoomPicture->Image = Image::FromFile(groupPhoto);
				chatRoomNameLabel->Text = gcnew String((*currentChatRoom)->getGroupName().c_str());

			}
			else {
				addMemPic->Visible = false;
				String^ groupPhoto = Path::Combine(imagesFolder, gcnew String((*currentChatRoom)->getGroupPhoto().c_str()));
				chatRoomPicture->Image = Image::FromFile(groupPhoto);
				chatRoomNameLabel->Text = gcnew String((*currentChatRoom)->getGroupName().c_str());
			}
		}

		chatRoomsPanels[chatRoomID]->Visible = true;

		if (chatRoomsPanels[chatRoomID]->Controls->Count > 0)
			chatRoomsPanels[chatRoomID]->ScrollControlIntoView(chatRoomsPanels[chatRoomID]->Controls[chatRoomsPanels[chatRoomID]->Controls->Count - 1]);

		footerContainer->Visible = true;
		headerContainer->Visible = true;

		(*currentChatRoom)->getMessagesID().updateMessagesSeen(*messages, *currentUser);
	}


	void createRoom(string contNum, string contName, User* currentUser, TextBox^ addContName_field, TextBox^ addContNum_field,
		unordered_map<int, ChatRoom>& chatRooms, FlowLayoutPanel^ chatRoomsPanel,
		unordered_map<int, long long>& activity, Panel^ messagesContainer, unordered_map<string,
		User>& users, string img, unordered_map<int, chati::Message>& messages) {


		addCont(*currentUser, contName, contNum);
		addCont(users[contNum], currentUser->getFirstName() + currentUser->getLastName(), currentUser->getMobileNumber());
		addContName_field->Clear();
		addContNum_field->Clear();
		MessageBox::Show("Contact added", "Success");

		ChatRoom* chatRoom = new ChatRoom(true);

		chatRoom->setChatRoomID(ChatRoom::getChatRoomsCounter());
		ChatRoom::incrementChatRoomsCounter();
		chatRoom->setGroupPhoto(img);
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
		unordered_map<int, long long>& activity, string img, unordered_map<int, chati::Message>& messages) {

		ChatRoom* chatRoom = new ChatRoom(false);
		chatRoom->setChatRoomID(ChatRoom::getChatRoomsCounter());
		chatRoom->setGroupPhoto(img);
		chatRoom->setGroupName(groupName);
		ChatRoom::incrementChatRoomsCounter();
		createChatRoomGUI(chatRoom->getChatRoomID(), messagesContainer);

		int chatRoomID = chatRoom->getChatRoomID();

		chatRoom->addUserPhone(currentUser->getMobileNumber());
		chatRoom->setAdminID(currentUser->getMobileNumber());
		currentUser->addChatRoomID(chatRoomID);

		msclr::interop::marshal_context context;

		for each (String ^ item in usersListBox->CheckedItems) {

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

	void addMember(int chatRoomID, string memNum, unordered_map<string, User>& users, unordered_map<int, ChatRoom>& chatRooms) {
		chatRooms[chatRoomID].addUserPhone(memNum);
		users[memNum].addChatRoomID(chatRoomID);
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