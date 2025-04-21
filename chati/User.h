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
	vector<int> contactsID; //?   (unorder_set+trie for autocomplete) refer to (uesrs) set because the id is unique for searching
    vector<int> stories; //? (queue) but less functionlaties
    vector<int> chatRoomsID; //? unique for both all users ()


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
    vector<int> getStories() const;
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
    void setStories(const vector<int>& stories);
    void setChatRoomsID(const vector<int>& chatRooms);
       
	// Destructor
	//~User();
};
