#pragma once
#include <string>
#include<list>
#include<queue>
#include <unordered_set>
#include <vector>

using namespace std;

class ChatRoom;

class User {
public:
    int userID;
    string mobileNumber;
    string password;
    string firstName;
    string lastName;
	string profilePhoto;
    string about;
    bool visible; //? for the user profile description
	vector<int> contactsID; //? refer to (uesrs) set because the id is unique for searching
    vector<int> stories; //? queue but less functionlaties
    vector<int> chatRoomsID; //? unique for both all users ()



    User(string mobileNumber, string password, string firstName, string lastName);
    User();


};
