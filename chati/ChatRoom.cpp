#include "ChatRoom.h"


ChatRoom::ChatRoom() {}

ChatRoom::ChatRoom(int id, bool isDual)
{
	this->chatRoomID = id;
	this->isDual = isDual;
	this->messagesID = list<int>();
	this->usersID = vector<int>();
}

ChatRoom::ChatRoom(int id) {
	this->chatRoomID = id;
	this->isDual = 1;
	this->messagesID = list<int>();
	this->usersID = vector<int>();
}
