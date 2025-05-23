#include <string>
#include <vector>
#include <iostream>
#include "User.h"
#include <unordered_map>


static bool checkUser(const string mobileNumber, const unordered_map<string, User> users) {

	if (users.find(mobileNumber) != users.end()) {
		return true;
	}
	return false;
}


static void signUp(string mob_num, string pass, string firstName, string lastName, unordered_map<string, User>& users, string imageName) {

	User u(mob_num, pass, firstName, lastName, imageName);

	users[mob_num] = u;
}

static bool checkSignIn(string mobileNumber, string password, unordered_map<string, User>& users) {

	if (users.find(mobileNumber) != users.end()) {
		if (users[mobileNumber].getPassword() == password) {
			return true;
		}
	}
	return false;
}