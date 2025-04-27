#include "ChatRoom.h"
int ChatRoom::chatRoomCounter = 0;

ChatRoom::ChatRoom() : isDual(false) { }


ChatRoom::ChatRoom(bool isDual) : isDual(isDual) { }

int ChatRoom::getChatRoomsCounter() { return chatRoomCounter; }
void ChatRoom::setChatRoomsCounter(int chatRoomCounter) { ChatRoom::chatRoomCounter = chatRoomCounter; }

int ChatRoom::getChatRoomID() const { return chatRoomID; }
void ChatRoom::setChatRoomID(int chatRoomID) { this->chatRoomID = chatRoomID; }

vector<string> ChatRoom::getUsersID() const { return usersPhone; }
void ChatRoom::setUsersID(const vector<string>& usersID) { this->usersPhone = usersID; }

set<int> ChatRoom::getMessagesID() const { return messagesID; }
void ChatRoom::setMessagesID(const set<int>& messagesID) { this->messagesID = messagesID; }

bool ChatRoom::getIsDual() const { return isDual; }
void ChatRoom::setIsDual(bool isDual) { this->isDual = isDual; }

void ChatRoom::addUserPhone(string userID) {
	this->usersPhone.push_back(userID);
}
void ChatRoom::deleteUserPhone(string userID) {
	auto it = find(usersPhone.begin(), usersPhone.end(), userID);
	if (it != usersPhone.end()) {
		usersPhone.erase(it);
	}
}

void ChatRoom::addMessageID(int messageID) {
	this->messagesID.insert(messageID);
}
void ChatRoom::deleteMessageID(int i) {
	this->messagesID.erase(i);
}


void ChatRoom::incrementChatRoomsCounter() {
	chatRoomCounter++; // Increment the message counter
}