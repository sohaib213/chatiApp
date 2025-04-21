#include "ChatRoom.h"

ChatRoom::ChatRoom() : chatRoomID(0), isDual(false) {}

ChatRoom::ChatRoom(int id) : chatRoomID(id), isDual(false) {}

ChatRoom::ChatRoom(int id, bool isDual) : chatRoomID(id), isDual(isDual) {}

int ChatRoom::getChatRoomID() const { return chatRoomID; }
void ChatRoom::setChatRoomID(int chatRoomID) { this->chatRoomID = chatRoomID; }

vector<int> ChatRoom::getUsersID() const { return usersID; }
void ChatRoom::setUsersID(const vector<int>& usersID) { this->usersID = usersID; }

list<int> ChatRoom::getMessagesID() const { return messagesID; }
void ChatRoom::setMessagesID(const list<int>& messagesID) { this->messagesID = messagesID; }

bool ChatRoom::getIsDual() const { return isDual; }
void ChatRoom::setIsDual(bool isDual) { this->isDual = isDual; }
