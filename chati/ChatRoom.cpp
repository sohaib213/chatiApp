#include "ChatRoom.h"
int ChatRoom::chatRoomCounter = 0;
ChatRoom::ChatRoom() : chatRoomID(0), isDual(false) { chatRoomID = ++chatRoomCounter; }

ChatRoom::ChatRoom(int id) : chatRoomID(id), isDual(false) { chatRoomID = ++chatRoomCounter; }

ChatRoom::ChatRoom(int id, bool isDual) : chatRoomID(id), isDual(isDual) { chatRoomID = ++chatRoomCounter; }

int ChatRoom::getChatRoomID() const { return chatRoomID; }
void ChatRoom::setChatRoomID(int chatRoomID) { this->chatRoomID = chatRoomID; }

vector<int> ChatRoom::getUsersID() const { return usersID; }
void ChatRoom::setUsersID(const vector<int>& usersID) { this->usersID = usersID; }

list<int> ChatRoom::getMessagesID() const { return messagesID; }
void ChatRoom::setMessagesID(const list<int>& messagesID) { this->messagesID = messagesID; }

bool ChatRoom::getIsDual() const { return isDual; }
void ChatRoom::setIsDual(bool isDual) { this->isDual = isDual; }

void ChatRoom::addUserID(int userID) {
	this->usersID.push_back(userID);
}
void ChatRoom::deleteUserID(int userID) {
	auto it = find(usersID.begin(), usersID.end(), userID);
	if (it != usersID.end()) {
		usersID.erase(it);
	}
}

void ChatRoom::addMessageID(int messageID) {
	this->messagesID.push_back(messageID);
}
void ChatRoom::deleteMessageID(int i) {
	int index = this->messagesID.size() - i - 1;

	auto it = this->messagesID.begin();
	std::advance(it, index); // Use advance for non-random access iterators
	this->messagesID.erase(it);

}