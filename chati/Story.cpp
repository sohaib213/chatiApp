#include "Story.h"

Story::Story(string userID, string publishTime, string storyText, string storyPhoto)
    : userID(userID), publishTime(publishTime), storyText(storyText), storyPhoto(storyPhoto) {
}

string Story::getUserID() const {
	return userID;
}