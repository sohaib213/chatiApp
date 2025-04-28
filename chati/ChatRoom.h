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
    vector<string> usersPhone;
    set<int> messagesID;
    bool isDual;

public:
    // constructors
    ChatRoom();
    ChatRoom(bool isDual);

    // Getters
    static int getChatRoomsCounter();
    int getChatRoomID() const;
    vector<string> getUsersID() const;
    set<int> getMessagesID() const;
    bool getIsDual() const;
    int getLastMessageID() const;

    // Setters
    static void setChatRoomsCounter(int count);
    void setChatRoomID(int id);
    void setUsersID(const vector<string>& users);
    void setMessagesID(const set<int>& messages);
    void setIsDual(bool dual);

	// Add Delete Methods
	void addUserPhone(string userID);
	void addMessageID(int messageID);
	void deleteUserPhone(string userID);
	void deleteMessageID(int messageID);

    static void incrementChatRoomsCounter();

    bool hasUser(string userID) const;

	//~ChatRoom();
};

