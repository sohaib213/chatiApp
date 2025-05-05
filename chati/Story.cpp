#include "Story.h"

// Initialize static member
int Story::storyCounter = 0;

// Default constructor
Story::Story() 
    : storyId(++storyCounter), storyText(""), publishTime(time(nullptr)), storyPhoto(""),
      fontName("Arial"), fontSize(12.0f), fontStyle(0), colorHex("#000000") {}

// Parameterized constructor
Story::Story( string storyText, time_t publishTime,
             string storyPhoto, string fontName, float fontSize, int fontStyle, string colorHex)
    : publishTime(publishTime), storyText(storyText), storyPhoto(storyPhoto),
      fontName(fontName), fontSize(fontSize), fontStyle(fontStyle), colorHex(colorHex) 
{
    storyId = ++storyCounter;
}

// Getters
int Story::getStoryID() const {
    return storyId;
}

//string Story::getUserPhone() const {
//	return userPhone;
//}

time_t Story::getPublishTime() const {
    return publishTime;
}

string Story::getStoryPhoto() const {
    return storyPhoto;
}

string Story::getStoryText() const {
    return storyText;
}
string Story::getFontName() const {
	return fontName;
}
float Story::getFontSize() const {
	return fontSize;
}
int Story::getFontStyle() const {
	return fontStyle;
}
string Story::getColorHex() const {
	return colorHex;
}

// Setters
void Story::setStoryID(const int& id) {
    storyId = id;
}

void Story::setFontName(const string& fontName) {
	this->fontName = fontName;
}
void Story::setFontSize(const float& fontSize) {
	this->fontSize = fontSize;
}
void Story::setFontStyle(const int& fontStyle) {
	this->fontStyle = fontStyle;
}
void Story::setColorHex(const string& colorHex) {
	this->colorHex = colorHex;
}

//void Story::setUserPhone(const string& userPhone) {
//    this->userPhone = userPhone;
//}

void Story::setPublishTime(const time_t& time) {
    publishTime = time;
}

void Story::setStoryPhoto(const string& photo) {
    storyPhoto = photo;
}

void Story::setStoryText(const string& text) {
    storyText = text;
}
