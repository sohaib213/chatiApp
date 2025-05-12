#pragma once
#include <vector>
#include <string>
#include <set>
#include "Message.h"
#include "User.h"
#include "LinkedList.h"

using namespace std;

class ChatRoom {
	static int chatRoomCounter; // Static variable to keep track of chat room IDs
    int chatRoomID;
    vector<string> usersPhone;
    chati::LinkedList messagesID;
    bool isDual;
    string groupName;
	string groupPhoto;
	string adminID;
public:
    // constructors
    ChatRoom();
    ChatRoom(bool isDual);

    // Getters
    static int getChatRoomsCounter();
    int getChatRoomID() const;
    vector<string> getUsersID() const;
    chati::LinkedList getMessagesID() const;
    bool getIsDual() const;
    int getLastMessageID() const;
    string getGroupName() const;
	string getGroupPhoto() const;
	string getAdminID() const;

    // Setters
    static void setChatRoomsCounter(int count);
    void setChatRoomID(int id);
    void setUsersID(const vector<string>& users);
    void setMessagesID(const chati::LinkedList& messages);
    void setIsDual(bool dual);
    void setGroupName(const string &groupName);
	void setGroupPhoto(const string& groupPhoto);
	void setAdminID(const string& adminID);
	

	// Add Delete Methods
	void addUserPhone(string userID);
	void addMessageID(int messageID);
	void addMessageIDInFiles(int messageID);
	void deleteUserPhone(string userID);
	void deleteMessageID(int messageID);
    void clearMessages();

    static void incrementChatRoomsCounter();

    bool hasUser(string userID) const;

	//~ChatRoom();
};

