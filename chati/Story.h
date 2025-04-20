#pragma once
#include <string>

using namespace std;

class Story {
public:
    string userID;
    string publishTime;
    string storyPhoto;
    string storyText;

    Story(string userID, string publishTime, string storyText, string storyPhoto = "");
	string getUserID() const;
};

