#pragma once
#include <string>

using namespace std;

class Story {
public:
	static int storyCounter; // Static variable to keep track of story IDs
    string storyId;
    string userID;
    string publishTime;
    string storyPhoto;
    string storyText;

    // constructor
    Story(string userID, string publishTime, string storyText, string storyPhoto = "");

    // Getters
    string getStoryID() const;
    string getUserID() const;
    string getPublishTime() const;
    string getStoryPhoto() const;
    string getStoryText() const;

    // Setters
    void setStoryID(const string& storyId);
    void setUserID(const string& id);
    void setPublishTime(const string& time);
    void setStoryPhoto(const string& photo);
    void setStoryText(const string& text);

    //~Story();
};


