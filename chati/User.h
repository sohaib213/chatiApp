#pragma once
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>

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
    bool visible; // for the user profile description
    map<int,string> contactsID; // unordered_set for fast lookups, unique for each user
    set<int> storiesID; // set to store story IDs
    set<int> chatRoomsID; // set to store chat room IDs

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
    map<int, string> getContactsID() const;
    set<int> getStoriesID() const;
    set<int> getChatRoomsID() const;

    // Setters
    void setUserID(int id);
    void setMobileNumber(const string& mobile);
    void setPassword(const string& pass);
    void setFirstName(const string& fname);
    void setLastName(const string& lname);
    void setProfilePhoto(const string& photo);
    void setAbout(const string& about);
    void setVisible(bool vis);
    void setContactsID(const map<int, string>& contacts);
    void setStoriesID(const set<int>& stories);
    void setChatRoomsID(const set<int>& chatRooms);

    // Add/Remove methods
    bool addContactID(int contactID,string contactName);
    bool addStoryID(int storyID);
    bool addChatRoomID(int chatRoomID);
    void removeContactID(int contactID);
    void removeStory(int storyID);
    void removeChatRoomID(int chatRoomID);

    bool isUserVisible();

    // Destructor
    ~User();
};
