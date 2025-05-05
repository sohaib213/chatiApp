#include <unordered_map>
#include <queue>
#include <string>
#include "ChatRoom.h"
#include "SearchChatrooms.h"
#include <iostream>
#include <vector>
using namespace std;

ChatRoom searchChatRooms(string chatname, unordered_map<int, ChatRoom> chatrooms) {
	priority_queue<pair<string, int>> pq;
	for (const auto& pair : chatrooms) {
		const ChatRoom& chatroom = pair.second;
		if (chatroom.getGroupName() == chatname) {
			pq.push({ chatroom.getGroupName(), chatroom.getChatRoomID() });
		}
	}
	if (pq.empty()) {
		return ChatRoom();
	}
	int chatRoomID = pq.top().second;
	return chatrooms[chatRoomID];
}
