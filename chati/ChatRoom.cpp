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

chati::LinkedList ChatRoom::getMessagesID() const { return messagesID; }
void ChatRoom::setMessagesID(const chati::LinkedList& messagesID) { this->messagesID = messagesID; }

bool ChatRoom::getIsDual() const { return isDual; }
void ChatRoom::setIsDual(bool isDual) { this->isDual = isDual; }

string ChatRoom::getGroupName() const { return groupName; }
void ChatRoom::setGroupName(const string& groupName) { this->groupName = groupName; }

string ChatRoom::getGroupPhoto() const { return groupPhoto; }
void ChatRoom::setGroupPhoto(const string& groupPhoto) { this->groupPhoto = groupPhoto; }

string ChatRoom::getAdminID() const { return adminID; }
void ChatRoom::setAdminID(const string& adminID) { this->adminID = adminID; }

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
	this->messagesID.push_front(messageID);
}

void ChatRoom::addMessageIDInFiles(int messageID) {
	this->messagesID.push_back(messageID);
}

int ChatRoom::getLastMessageID() const {
	if (!messagesID.empty()) {
		return messagesID.begin()->value; 
	}
	return -1; 
}
void ChatRoom::deleteMessageID(int i) {
	this->messagesID.Delete(i);
}

bool ChatRoom::hasUser(string userPhone) const {
	return find(usersPhone.begin(), usersPhone.end(), userPhone) != usersPhone.end();
}

void ChatRoom::incrementChatRoomsCounter() {
	chatRoomCounter++; // Increment the message counter
}