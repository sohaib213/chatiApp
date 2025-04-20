#pragma once
#include <string>
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
    vector<int> contactsID;
    vector<int> stories;
	vector<int> chatRoomsID;



    User(string mobileNumber, string password, string firstName, string lastName);
    User();


};
