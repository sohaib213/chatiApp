#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include "ChatRoom.h"
#include "Sort.h"

static void searchChatRooms(string chatname, unordered_map<int, ChatRoom> chatRooms, FlowLayoutPanel^ chatRoomsPanel) {
	if (chatname.empty())
		return;

	List<Control^>^ buttons = gcnew List<Control^>();

	// Find buttons in chatRoomsPanel that match the chatroom name
	for (auto& room : userChatRooms) {
		for each (Control ^ control in chatRoomsPanel->Controls) {
			Button^ button = dynamic_cast<Button^>(control);
			if (button != nullptr && button->Tag != nullptr && safe_cast<int>(button->Tag) == room.first && chatRooms.at(room.first).getGroupName()==chatname) {
				buttons->Add(button);
				break;
			}
		}
	}

	// Clear the chatRoomsPanel and add the new buttons
	chatRoomsPanel->SuspendLayout();
	chatRoomsPanel->Controls->Clear();
	for each (Control ^ button in buttons) {
		chatRoomsPanel->Controls->Add(button);
	}
	chatRoomsPanel->ResumeLayout();
}
