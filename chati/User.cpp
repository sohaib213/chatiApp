#include "User.h"
#include <iostream>

// Initialize the static counter
int User::userCounter = 0;

// Default Constructor
User::User(string mobileNumber, string password, string firstName, string lastName)
    : mobileNumber(mobileNumber), password(password), firstName(firstName), lastName(lastName), userID(++userCounter) {
    visible = true;  // Assuming users are visible by default
}

// Default Constructor
User::User() : userID(++userCounter), visible(true) {}

// Getters
int User::getUserID() const { return userID; }
string User::getMobileNumber() const { return mobileNumber; }
string User::getPassword() const { return password; }
string User::getFirstName() const { return firstName; }
string User::getLastName() const { return lastName; }
string User::getProfilePhoto() const { return profilePhoto; }
string User::getAbout() const { return about; }
bool User::getVisible() const { return visible; }
map<int, string> User::getContactsID() const { return contactsID; }
set<int> User::getStoriesID() const { return storiesID; }
set<int> User::getChatRoomsID() const { return chatRoomsID; }

// Setters
void User::setUserID(int id) { userID = id; }
void User::setMobileNumber(const string& mobile) { mobileNumber = mobile; }
void User::setPassword(const string& pass) { password = pass; }
void User::setFirstName(const string& fname) { firstName = fname; }
void User::setLastName(const string& lname) { lastName = lname; }
void User::setProfilePhoto(const string& photo) { profilePhoto = photo; }
void User::setAbout(const string& about) { this->about = about; }
void User::setVisible(bool vis) { visible = vis; }
void User::setContactsID(const map<int, string>& contacts) { contactsID = contacts; }
void User::setStoriesID(const set<int>& stories) { storiesID = stories; }
void User::setChatRoomsID(const set<int>& chatRooms) { chatRoomsID = chatRooms; }

// Add/Remove Methods
bool User::addContactID(int contactID,string contactName) {
	return contactsID.insert({ contactID, contactName }).second; // Directly modify contactsID
}

bool User::addStoryID(int storyID) {
    return storiesID.insert(storyID).second; // Directly modify storiesID
}

bool User::addChatRoomID(int chatRoomID) {
    return chatRoomsID.insert(chatRoomID).second; // Directly modify chatRoomsID
}

void User::removeContactID(int contactID) {
    contactsID.erase(contactID); // Directly modify contactsID
}

void User::removeStory(int storyID) {
    storiesID.erase(storyID); // Directly modify storiesID
}

void User::removeChatRoomID(int chatRoomID) {
    chatRoomsID.erase(chatRoomID); // Directly modify chatRoomsID
}

bool User::isUserVisible() {
    return visible;
}

// Destructor
User::~User() {
    // Any necessary cleanup (if needed)
}
