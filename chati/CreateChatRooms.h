#pragma once
#include "ChatRoom.h"
#include <unordered_map>
#include "AddContact.h"
#include <list>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;


 void addChatRoomPanel(string contName, int chatRoomID, FlowLayoutPanel^ chatRoomsPanel);

 void createRoom(string currentNum, string contName, User* currentUser,
	TextBox^ addContName_field, TextBox^ addContNum_field,unordered_map<int, ChatRoom>& chatRooms,
	 FlowLayoutPanel^ chatRoomsPanel, unordered_map<int, long long>& activity, ChatRoom* currentChatRoom);

 void sortChatRooms(User currentUser, unordered_map<int,long long>& activity,
	const unordered_map<int,ChatRoom>& chatRooms,FlowLayoutPanel^ chatRoomsPanel);
