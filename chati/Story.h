#pragma once
#include <string>
#include <ctime>

using namespace std;

class Story {
public:
    static int storyCounter; // Static variable to keep track of story IDs
    int storyId;             // Changed from string to int
    int userID;
    time_t publishTime;
    string storyPhoto;
    string storyText;

    // Constructors
    Story();
    Story(int userID, time_t publishTime, string storyText, string storyPhoto = "");

    // Getters
    int getStoryID() const;
    int getUserID() const;
    time_t getPublishTime() const;
    string getStoryPhoto() const;
    string getStoryText() const;

    // Setters
    void setStoryID(const int& storyId);
    void setUserID(const int& id);
    void setPublishTime(const time_t& time);
    void setStoryPhoto(const string& photo);
    void setStoryText(const string& text);
};
