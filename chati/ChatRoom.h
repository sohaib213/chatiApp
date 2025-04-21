#pragma once
#include <vector>
#include <string>
#include <list>
#include "Message.h"
#include "User.h"

using namespace std;

class ChatRoom {
public:
	static int chatRoomCounter; // Static variable to keep track of chat room IDs
    int chatRoomID;
    vector<int> usersID;
    list<int> messagesID;
    bool isDual;

    // constructors
    ChatRoom();
    ChatRoom(int id);
    ChatRoom(int id, bool isDual);

    // Getters
    int getChatRoomID() const;
    vector<int> getUsersID() const;
    list<int> getMessagesID() const;
    bool getIsDual() const;

    // Setters
    void setChatRoomID(int id);
    void setUsersID(const vector<int>& users);
    void setMessagesID(const list<int>& messages);
    void setIsDual(bool dual);

	//~ChatRoom();
};

