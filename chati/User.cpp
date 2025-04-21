#include "User.h"

User::User(string mobileNumber, string password, string firstName, string lastName)
    : mobileNumber(mobileNumber), password(password), firstName(firstName), lastName(lastName), visible(true) {
}

User::User() : userID(0), mobileNumber(""), password(""), firstName(""), lastName(""), visible(true) {}

int User::getUserID() const { return userID; }
void User::setUserID(int userID) { this->userID = userID; }

string User::getMobileNumber() const { return mobileNumber; }
void User::setMobileNumber(const string& mobileNumber) { this->mobileNumber = mobileNumber; }

string User::getPassword() const { return password; }
void User::setPassword(const string& password) { this->password = password; }

string User::getFirstName() const { return firstName; }
void User::setFirstName(const string& firstName) { this->firstName = firstName; }

string User::getLastName() const { return lastName; }
void User::setLastName(const string& lastName) { this->lastName = lastName; }

string User::getProfilePhoto() const { return profilePhoto; }
void User::setProfilePhoto(const string& profilePhoto) { this->profilePhoto = profilePhoto; }

string User::getAbout() const { return about; }
void User::setAbout(const string& about) { this->about = about; }

bool User::getVisible() const { return visible; }
void User::setVisible(bool visible) { this->visible = visible; }
