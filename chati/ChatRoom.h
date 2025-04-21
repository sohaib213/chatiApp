#pragma once
#include <vector>
#include <string>
#include <set>
#include "Message.h"
#include "User.h"

using namespace std;

class ChatRoom {
	static int chatRoomCounter; // Static variable to keep track of chat room IDs
    int chatRoomID;
    vector<int> usersID;
    set<int> messagesID;
    bool isDual;

public:
    // constructors
    ChatRoom();
    ChatRoom(int id);
    ChatRoom(int id, bool isDual);

    // Getters
    int getChatRoomID() const;
    vector<int> getUsersID() const;
    set<int> getMessagesID() const;
    bool getIsDual() const;

    // Setters
    void setChatRoomID(int id);
    void setUsersID(const vector<int>& users);
    void setMessagesID(const set<int>& messages);
    void setIsDual(bool dual);

	// Add Delete Methods
	void addUserID(int userID);
	void addMessageID(int messageID);
	void deleteUserID(int userID);
	void deleteMessageID(int messageID);

	//~ChatRoom();
};

