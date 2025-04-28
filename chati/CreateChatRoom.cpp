#include "ChatRoom.h"
#include <unordered_map>
#include "CreateChatRooms.h"
#include <list>
#include <chrono>
#include <ctime>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;


  void addChatRoomPanel(string contName, int chatRoomID, FlowLayoutPanel^ chatRoomsPanel) {
	Button^ chatRoomButton = gcnew Button();
	chatRoomButton->BackColor = Color::Black;
	chatRoomButton->Size = System::Drawing::Size(338, 100); // Set the size of the panel
	chatRoomButton->Location = System::Drawing::Point(0, 0); // Set the location of the panel
	chatRoomButton->Tag = chatRoomID;

	Label^ contactNameLabel = gcnew Label();
	contactNameLabel->AutoSize = true;
	contactNameLabel->BackColor = Color::Transparent;
	contactNameLabel->Text = gcnew System::String(contName.c_str());
	contactNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	contactNameLabel->ForeColor = Color::White;

	chatRoomButton->Controls->Add(contactNameLabel);
	chatRoomsPanel->Controls->Add(chatRoomButton);
	chatRoomsPanel->Refresh();
  }


 void createRoom(string currentNum,string contName, User* currentUser, TextBox^ addContName_field, TextBox^ addContNum_field,
	unordered_map<int, ChatRoom>& chatRooms, FlowLayoutPanel^ chatRoomsPanel, unordered_map<int, long long>& activity,ChatRoom* currentChatRoom) {

	addCont(currentUser, contName,currentNum);
	addContName_field->Clear();
	addContNum_field->Clear();
	MessageBox::Show("Contact added", "Success");


	ChatRoom* chatRoom = new ChatRoom(true);

	chatRoom->setChatRoomID(ChatRoom::getChatRoomsCounter());
	ChatRoom::incrementChatRoomsCounter();

	chatRoom->addUserPhone(currentUser->getMobileNumber());

	chatRooms[chatRoom->getChatRoomID()] = *chatRoom;

	int chatRoomID = chatRoom->getChatRoomID();
	addChatRoomPanel(contName, chatRoomID, chatRoomsPanel);

	currentChatRoom = chatRoom;

	auto now = std::chrono::system_clock::now();

	// Convert it to milliseconds since epoch
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
	auto value = now_ms.time_since_epoch();

	// Get the number of milliseconds as integer
	long long milliseconds = value.count();

	activity[chatRoomID] = milliseconds;

 }


 void sortChatRooms(User currentUser,  unordered_map<int, long long>& activity,
	const unordered_map<int, ChatRoom>& chatRooms, FlowLayoutPanel^ chatRoomsPanel) {

	 cout << "called - map size: " << activity.size() << endl;
	 
	vector<pair<int, int>> userChatRooms;

	//push chatrooms that current user is a member of 
	for (auto& chatRoom : activity) {
		if (chatRooms.at(chatRoom.first).hasUser(currentUser.getMobileNumber())) {
			userChatRooms.push_back({ chatRoom.first, chatRoom.second });
		}
	}

	//sort the chat rooms based on the last message ID
	for (int i = 0; i < userChatRooms.size(); ++i) {
		for (int j = i + 1; j < userChatRooms.size(); ++j) {
			if (userChatRooms[i].second < userChatRooms[j].second) {
				swap(userChatRooms[i], userChatRooms[j]);
			}
		}
	}

	//List to store buttons
	List<Control^>^ buttons = gcnew List<Control^>();
	
	
	// Find buttons in chatRoomsPanel that match the chat room IDs
	for (auto& room : userChatRooms) {
		for each (Control ^ control in chatRoomsPanel->Controls) {
			Button^ button = dynamic_cast<Button^>(control);
			if (button != nullptr && button->Tag != nullptr && safe_cast<int>(button->Tag) == room.first) {
				buttons->Add(button);
				break;
			}
		}
	}

	// Clear the chatRoomsPanel and add the sorted buttons
	chatRoomsPanel->SuspendLayout();
	chatRoomsPanel->Controls->Clear();
	for each (Control ^ button in buttons) {
		chatRoomsPanel->Controls->Add(button);
	}
	chatRoomsPanel->ResumeLayout();
 }