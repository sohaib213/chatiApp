#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <msclr/marshal_cppstd.h>
#include "User.h"
#include "ChatRoom.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

#pragma once
static void sortChatRooms(User currentUser, unordered_map<int, long long>& activity,
	const unordered_map<int, ChatRoom>& chatRooms, FlowLayoutPanel^ chatRoomsPanel) {



	cout << "called - map size: " << activity.size() << endl;

	vector<pair<int, long long>> userChatRooms;


	for (const auto& room : chatRooms) {
		int chatRoomID = room.first;
		const ChatRoom& chatRoom = room.second;

		if (chatRoom.hasUser(currentUser.getMobileNumber())) {
			long long lastActivity = 0;
			if (activity.find(chatRoomID) != activity.end()) {
				lastActivity = activity[chatRoomID];
			}
			userChatRooms.push_back({ chatRoomID, lastActivity });
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