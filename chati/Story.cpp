#include "Story.h"
int Story::storyCounter = 0; // Initialize the static story counter
Story::Story(string userID, string publishTime, string storyText, string storyPhoto)
    : userID(userID), publishTime(publishTime), storyText(storyText), storyPhoto(storyPhoto) {
	storyId = ++storyCounter; // Increment the static story counter to assign a unique ID
}

string Story::getUserID() const { return userID; }
void Story::setUserID(const string& userID) { this->userID = userID; }

string Story::getPublishTime() const { return publishTime; }
void Story::setPublishTime(const string& publishTime) { this->publishTime = publishTime; }

string Story::getStoryPhoto() const { return storyPhoto; }
void Story::setStoryPhoto(const string& storyPhoto) { this->storyPhoto = storyPhoto; }

string Story::getStoryText() const { return storyText; }
void Story::setStoryText(const string& storyText) { this->storyText = storyText; }
