#pragma once
#include <vector>
#include <string>
#include <list>
#include "Message.h"
#include "User.h"


using namespace std;

class User;
using namespace std;


enum class ChatRoomType { OneToOne, Group };

class ChatRoom {
public:
    string chatRoomID;
    vector<string> usersID[2];
    list<string> messagesID;
    ChatRoomType type;

    ChatRoom(string id);
    ChatRoom(string id, ChatRoomType type);

	string getChatRoomID();
};
