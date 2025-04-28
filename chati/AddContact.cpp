#include <string>
#include <map>
#include "User.h"
#include <iostream>
#include "AddContact.h"

using namespace std;

//string contNumber;
//string currentContName;

 bool checkContactExist(string contactNumber, map<string, User> users, string& currentContName) {
	auto it = users.find(contactNumber);
	if (it != users.end()) {
		//contNumber = it->second.getMobileNumber();
		currentContName = it->second.getFirstName();
		return true;
	}
	return false;
}
//static string showCurrentName(string& currentContName) {
//	return currentContName;
//}
 bool addCont(User* user, string contactName,string contNumber) {
	return user->addContactPhone(contNumber, contactName);
}

