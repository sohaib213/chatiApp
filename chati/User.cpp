#include "User.h"

using namespace std;
int userID;
string mobileNumber;
string password;
string firstName;
string lastName;
vector<string> contactsID;
vector<string> stories;
vector<string> chatRoomsID;

User::User(string mobileNumber, string password, string firstName, string lastName) {

	this->mobileNumber = mobileNumber;
	this->password = password;
	this->firstName = firstName;
	this->lastName = lastName;
	this->userID = userID;
	this->contactsID = vector<int>();
	this->chatRoomsID = vector<int>();
	this->stories = vector<int>();
}
User::User() {

	mobileNumber = "";
	password = "";
	firstName = "";
	lastName = "";
	
}