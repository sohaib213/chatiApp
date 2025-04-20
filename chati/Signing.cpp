#include <string>
#include <vector>
#include <iostream>
#include "User.h"
#include <map>


static bool checkUser(const string mobileNumber, const map<string, User> users) {

	if (users.find(mobileNumber) != users.end()) {
		return true;
	}

	/*for (const User& u : users) {
		if (u.mobileNumber == mobileNumber) {
			return true;
		}
	}*/
	return false;
}


static int generateID(map<string, User> users) {  
    if (users.empty()) return 1;  
    int maxID = 0;  
    for (const auto& pair : users) {  
        if (pair.second.userID > maxID) {
            maxID = pair.second.userID;
        }  
    }  
    return maxID + 1;  
}

static void signUp(string mob_num, string pass, string firstName, string lastName, map<string, User>& users) {

	User u(mob_num, pass, firstName, lastName);


	u.userID = generateID(users);
	users[mob_num] = u;
	//users.push_back(u);

}

static bool checkSignIn(string mobileNumber, string password, map<string, User>& users) {

	if (users.find(mobileNumber) != users.end()) {
		if (users[mobileNumber].password == password) {
			return true;
		}
	}
	return false;
}