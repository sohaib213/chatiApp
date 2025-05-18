#include "User.h"
#include <iostream>


// Default Constructor
User::User(string mobileNumber, string password, string firstName, string lastName, string profilePhoto)
    : mobileNumber(mobileNumber), password(password), firstName(firstName), lastName(lastName), profilePhoto(profilePhoto) {
    visible = true;  // Assuming users are visible by default
}

// Default Constructor
User::User() : visible(true) {}

// Getters
string User::getMobileNumber() const { return mobileNumber; }
string User::getPassword() const { return password; }
string User::getFirstName() const { return firstName; }
string User::getLastName() const { return lastName; }
string User::getProfilePhoto() const { return profilePhoto; }
string User::getAbout() const { return about; }
bool User::getVisible() const { return visible; }
unordered_map<string, string> User::getContactsPhones() const { return contactsPhone; }
set<int> User::getStoriesID() const { return storiesID; }
unordered_set<int> User::getChatRoomsID() const { return chatRoomsID; }

// Setters
void User::setMobileNumber(const string& mobile) { mobileNumber = mobile; }
void User::setPassword(const string& pass) { password = pass; }
void User::setFirstName(const string& fname) { firstName = fname; }
void User::setLastName(const string& lname) { lastName = lname; }
void User::setProfilePhoto(const string& photo) { profilePhoto = photo; }
void User::setAbout(const string& about) { this->about = about; }
void User::setVisible(const bool& vis) { visible = vis; }
void User::setContactsPhones(const unordered_map<string, string>& contactsPhone) { this->contactsPhone = contactsPhone; }
void User::setStoriesID(const set<int>& stories) { storiesID = stories; }
void User::setChatRoomsID(const unordered_set<int>& chatRooms) { chatRoomsID = chatRooms; }

// Add/Remove Methods
bool User::addContactPhone(string contactPhone,string contactName) {
	return this->contactsPhone.insert({ contactPhone, contactName }).second; // Directly modify contactsID
}

bool User::addStoryID(int storyID) {
    return this->storiesID.insert(storyID).second; // Directly modify storiesID
}

bool User::addChatRoomID(int chatRoomID) {
    return this->chatRoomsID.insert(chatRoomID).second; // Directly modify chatRoomsID
}

void User::removeContactPhone(string contactPhone) {
    this->contactsPhone.erase(contactPhone); // Directly modify contactsID
}

void User::removeStory(int storyID) {
    this->storiesID.erase(storyID); // Directly modify storiesID
}

void User::removeChatRoomID(int chatRoomID) {
    this->chatRoomsID.erase(chatRoomID);
}

bool User::isUserVisible() {
    return visible;
}

// Destructor
User::~User() {
    // Any necessary cleanup (if needed)
}
