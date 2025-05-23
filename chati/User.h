#pragma once
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class User {
    string mobileNumber;
    string password;
    string firstName;
    string lastName;
    string profilePhoto;
    string about;
    bool visible; // for the user profile description
	unordered_map<string, string> contactsPhone; // phone number as key and name as value
    set<int> storiesID; // set to store story IDs
    unordered_set<int> chatRoomsID; // set to store chat room IDs

public:
    // Constructors
    User(string mobileNumber, string password, string firstName, string lastName, string profilePhoto);
    User();

    // Getters
    string getMobileNumber() const;
    string getPassword() const;
    string getFirstName() const;
    string getLastName() const;
    string getProfilePhoto() const;
    string getAbout() const;
    bool getVisible() const;
    unordered_map<string, string> getContactsPhones() const;
    set<int> getStoriesID() const;
    unordered_set<int> getChatRoomsID() const;

    // Setters
    void setMobileNumber(const string& mobile);
    void setPassword(const string& pass);
    void setFirstName(const string& fname);
    void setLastName(const string& lname);
    void setProfilePhoto(const string& photo);
    void setAbout(const string& about);
    void setVisible(const bool& vis);
    void setContactsPhones(const unordered_map<string, string>& contacts);
    void setStoriesID(const set<int>& stories);
    void setChatRoomsID(const unordered_set<int>& chatRooms);

    // Add/Remove methods
    bool addContactPhone(string contactID,string contactName);
    bool addStoryID(int storyID);
    bool addChatRoomID(int chatRoomID);
    void removeContactPhone(string contactID);
    void removeStory(int storyID);
    void removeChatRoomID(int chatRoomID);

    bool isUserVisible();

    // Destructor
    ~User();
};
