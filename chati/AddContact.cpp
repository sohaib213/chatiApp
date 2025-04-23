#include <string>
#include <map>
#include "User.h"
using namespace std;
static int contID;
static string currentContName;
static bool checkContactExist(string contactNumber, map<string, User> users) {
	auto it = users.find(contactNumber);
	if (it != users.end()) {
		contID = it->second.getUserID();
		currentContName = it->second.getFirstName();
		return true;
	}
	return false;
}
static string showCurrentName() {
	return currentContName;
}
static bool addContact(User& user, string contactName) {
	user.addContactID(contID, contactName);
}