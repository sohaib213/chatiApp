#include "Story.h"

// Initialize static member
int Story::storyCounter = 0;

// Default constructor
Story::Story() : storyId(++storyCounter), userPhone(0), publishTime(time(nullptr)), storyPhoto(""), storyText("") {}

// Parameterized constructor
Story::Story(string userPhone, time_t publishTime, string storyText, string storyPhoto)
    : userPhone(userPhone), publishTime(publishTime), storyText(storyText), storyPhoto(storyPhoto) {
    storyId = ++storyCounter;
}

// Getters
int Story::getStoryID() const {
    return storyId;
}

string Story::getUserPhone() const {
	return userPhone;
}

time_t Story::getPublishTime() const {
    return publishTime;
}

string Story::getStoryPhoto() const {
    return storyPhoto;
}

string Story::getStoryText() const {
    return storyText;
}

// Setters
void Story::setStoryID(const int& id) {
    storyId = id;
}

void Story::setUserPhone(const string& userPhone) {
    this->userPhone = userPhone;
}

void Story::setPublishTime(const time_t& time) {
    publishTime = time;
}

void Story::setStoryPhoto(const string& photo) {
    storyPhoto = photo;
}

void Story::setStoryText(const string& text) {
    storyText = text;
}
