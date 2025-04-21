#include "User.h"
int User::userCounter = 0; // Initialize the static user counter
User::User(string mobileNumber, string password, string firstName, string lastName)
	: mobileNumber(mobileNumber), password(password), firstName(firstName), lastName(lastName), visible(true) {
	userID = ++userCounter; // Increment the static user counter to assign a unique ID
}

User::User() : userID(0), mobileNumber(""), password(""), firstName(""), lastName(""), visible(true) {
	userID = ++userCounter; // Increment the static user counter to assign a unique ID
}

int User::getUserID() const { return userID; }
void User::setUserID(int userID) { this->userID = userID; }

string User::getMobileNumber() const { return mobileNumber; }
void User::setMobileNumber(const string& mobileNumber) { this->mobileNumber = mobileNumber; }

string User::getPassword() const { return password; }
void User::setPassword(const string& password) { this->password = password; }

string User::getFirstName() const { return firstName; }
void User::setFirstName(const string& firstName) { this->firstName = firstName; }

string User::getLastName() const { return lastName; }
void User::setLastName(const string& lastName) { this->lastName = lastName; }

string User::getProfilePhoto() const { return profilePhoto; }
void User::setProfilePhoto(const string& profilePhoto) { this->profilePhoto = profilePhoto; }

string User::getAbout() const { return about; }
void User::setAbout(const string& about) { this->about = about; }

bool User::getVisible() const { return visible; }
void User::setVisible(bool visible) { this->visible = visible; }

bool User::isUserVisible(){ 
	return visible; 
}

vector<int> User::getContactsID() const { return contactsID; }
vector<int> User::getStoriesID() const {return storiesID;}
vector<int> User::getChatRoomsID() const { return chatRoomsID; }

void User::setContactsID(const vector<int>& contactsID) { this->contactsID = contactsID; }
void User::setStoriesID(const vector<int>& storiesID) { this->storiesID = storiesID; }
void User::setChatRoomsID(const vector<int>& chatRoomsID) { this->chatRoomsID = chatRoomsID; }


void User::addContactID(int contactID) {  
    this->contactsID.push_back(contactID);  
}
void User::addStoryID(int storyID) {  
	this->storiesID.push_back(storyID);  
}
void User::addChatRoomID(int chatRoomID) {  
	this->chatRoomsID.push_back(chatRoomID);  
}

void User::removeContactID(int contactID) {
	auto it = find(contactsID.begin(), contactsID.end(), contactID);
	if (it != contactsID.end()) {
		contactsID.erase(it);
	}
}
void User::removeStory(int storyID) {
	auto it = find(storiesID.begin(), storiesID.end(), storyID);
	if (it != storiesID.end()) {
		storiesID.erase(it);
	}
}
void User::removeChatRoomID(int chatRoomID) {
	auto it = find(chatRoomsID.begin(), chatRoomsID.end(), chatRoomID);
	if (it != chatRoomsID.end()) {
		chatRoomsID.erase(it);
	}
}


User::~User() {
	
}