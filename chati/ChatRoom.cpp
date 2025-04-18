#include "ChatRoom.h"

ChatRoom::ChatRoom(string id, ChatRoomType type)
{
	this->chatRoomID = id;
	this->type = type;
}

ChatRoom::ChatRoom(string id) {
	chatRoomID = id;
	type = ChatRoomType::OneToOne; // Default to OneToOne if type is not specified
}

string ChatRoom::getChatRoomID() {
	return chatRoomID;
}
