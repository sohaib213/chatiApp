#pragma once
#include <string>
#include<list>
#include<queue>
#include <unordered_set>
#include <vector>

using namespace std;


class User {
	static int userCounter; // Static variable to keep track of user IDs
    int userID;
    string mobileNumber;
    string password;
    string firstName;
    string lastName;
	string profilePhoto;
    string about;
    bool visible; //? for the user profile description
	vector<int> contactsID; //?   (unorder_set+trie for autocomplete) refer to (uesrs) set because the id is unique for searching
    vector<int> storiesID; //? (queue) but less functionlaties
    vector<int> chatRoomsID; //? unique for both all users ()

public:

	// Constructors
    User(string mobileNumber, string password, string firstName, string lastName);
    User();

    // Getters
    int getUserID() const;
    string getMobileNumber() const;
    string getPassword() const;
    string getFirstName() const;
    string getLastName() const;
    string getProfilePhoto() const;
    string getAbout() const;
    bool getVisible() const;
    vector<int> getContactsID() const;
    vector<int> getStoriesID() const;
    vector<int> getChatRoomsID() const;

    // Setters
    void setUserID(int id);
    void setMobileNumber(const string& mobile);
    void setPassword(const string& pass);
    void setFirstName(const string& fname);
    void setLastName(const string& lname);
    void setProfilePhoto(const string& photo);
    void setAbout(const string& about);
    void setVisible(bool vis);
    void setContactsID(const vector<int>& contacts);
    void setStoriesID(const vector<int>& stories);
    void setChatRoomsID(const vector<int>& chatRooms);


	// Add Remove methods
	void addContactID(int contactID);
	void addStoryID(int storyID);
	void addChatRoomID(int chatRoomID);
	void removeContactID(int contactID);
	void removeStory(int storyID);
	void removeChatRoomID(int chatRoomID);
	bool isUserVisible();
       
	// Destructor
	~User();
};
