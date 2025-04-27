#include <string>
#include <map>
#include "User.h"
#include <iostream>

using namespace std;
static string contNumber;
static string currentContName;
static bool checkContactExist(string contactNumber, map<string, User> users) {
	auto it = users.find(contactNumber);
	if (it != users.end()) {
		contNumber = it->second.getMobileNumber();
		currentContName = it->second.getFirstName();
		return true;
	}
	return false;
}
static string showCurrentName() {
	return currentContName;
}
static bool addContact(User* user, string contactName) {
	return user->addContactPhone(contNumber, contactName);
}