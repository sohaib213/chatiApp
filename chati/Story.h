#pragma once
#include <string>
#include <ctime>
#include <unordered_map>

using namespace std;

class Story {
public:
    static int storyCounter; // Static variable to keep track of story IDs
    int storyId;             // Changed from string to int
    //string userPhone;
    time_t publishTime;
    string storyPhoto;
    string storyText;
    unordered_map<int, bool>views;

    // New members for font and color
    string fontName;         // Font name
    float fontSize;          // Font size
    int fontStyle;           // Font style (stored as int)
    string colorHex;         // Color in hex format

    // Constructors
    Story();
    Story(  string storyText, time_t publishTime,
        string storyPhoto = "", string fontName = "Arial",
        float fontSize = 12.0f, int fontStyle = 0, string colorHex = "#000000");

    // Getters
    int getStoryID() const;
    //string getUserPhone() const;
    time_t getPublishTime() const;
    string getStoryPhoto() const;
    string getStoryText() const;
    string getFontName() const;
    float getFontSize() const;
    int getFontStyle() const;
    string getColorHex() const;
	unordered_map<int, bool> getViews() const;


    // Setters
    void setStoryID(const int& storyId);
    //void setUserPhone(const string& userPhone);
    void setPublishTime(const time_t& time);
    void setStoryPhoto(const string& photo);
    void setStoryText(const string& text);
    void setFontName(const string& fontName);
    void setFontSize(const float& fontSize);
    void setFontStyle(const int& fontStyle);
    void setColorHex(const string& colorHex);
	void setViews(const unordered_map<int, bool>& views);
};
