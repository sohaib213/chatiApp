#include <string>
#include <vector>
#include <iostream>
#include "User.h"
#include <map>


static bool checkUser(const string mobileNumber, const map<string, User> users) {

	if (users.find(mobileNumber) != users.end()) {
		return true;
	}
	return false;
}


static void signUp(string mob_num, string pass, string firstName, string lastName, map<string, User>& users) {

	User u(mob_num, pass, firstName, lastName);

	users[mob_num] = u;
}

static bool checkSignIn(string mobileNumber, string password, map<string, User>& users) {

	if (users.find(mobileNumber) != users.end()) {
		if (users[mobileNumber].getPassword() == password) {
			return true;
		}
	}
	return false;
}