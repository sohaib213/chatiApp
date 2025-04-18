#pragma once
#include <string>
#include <vector>
#include "ChatRoom.h"
#include "Story.h"

using namespace std;

class ChatRoom;

class User {
public:
    int userID;
    string mobileNumber;
    string password;
    string firstName;
    string lastName;
    vector<string> contactsID;
    vector<string> stories;
	vector<string> chatRoomsID;



    User(string mobileNumber, string password, string firstName, string lastName);
    User();


};
