#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <msclr/marshal_cppstd.h>
#include "User.h"
#include "ChatRoom.h"
#include <ctime>
#include <sstream>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;
static vector<pair<int, long long>> userChatRooms;

#pragma once
static void sortChatRooms(User currentUser, unordered_map<int, long long>& activity,
	const unordered_map<int, ChatRoom>& chatRooms, FlowLayoutPanel^ chatRoomsPanel,
	unordered_map<int, chati::Message> messages) {

	userChatRooms.clear();

	//cout << "called - activity size: " << activity.size() << endl;
	//cout << "called - chatRooms size: " << chatRooms.size() << endl;
	


	for (const auto& room : chatRooms) {
		int chatRoomID = room.first;
		const ChatRoom& chatRoom = room.second;

		if (chatRoom.hasUser(currentUser.getMobileNumber())) {
			int lastMessageID = room.second.getLastMessageID();
			long long lastActivity = 0;
			auto it = messages.find(lastMessageID);
			if (it != messages.end()) {
				string date = it->second.getDateSent();
				int hour = it->second.getHourSent();
				int minute = it->second.getMinuteSent();
				int second = it->second.getSecondSent();

				int day, month, year;
				char dash;

				istringstream iss(date);
				iss >> day >> dash >> month >> dash >> year;

				// Normalize 2-digit year 
				year += (year < 1000) ? 2000 : 0;

				tm t = {};
				t.tm_year = year - 1900;
				t.tm_mon = month - 1;
				t.tm_mday = day;
				t.tm_hour = hour;
				t.tm_min = minute;
				t.tm_sec = second;
				
				lastActivity = static_cast<long long>(mktime(&t));
			}
			else if (activity.find(chatRoomID) != activity.end()) {
				lastActivity = activity[chatRoomID];
			}
			cout <<"LastActivity: " << lastActivity << endl;
			userChatRooms.push_back({ chatRoomID, lastActivity });
		}
	}


	//sort the chat rooms based on the time the message was sent at 
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
			if (button != nullptr && button->Tag != nullptr && safe_cast<int>(button->Tag) == room.first)
			{
				cout << "found button: " << room.first << endl;
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