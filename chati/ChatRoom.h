#pragma once
#include <vector>
#include <string>
#include <list>
#include "Message.h"
#include "User.h"


using namespace std;


class ChatRoom {
public:
    int chatRoomID;
    vector<int> usersID;
    list<int> messagesID;
    bool isDual;

    ChatRoom();
    ChatRoom(int id);
    ChatRoom(int id, bool isDual);

};
