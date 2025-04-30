#pragma once
#include <string>
#include <map>
#include "User.h"
#include <iostream>

using namespace std;



 bool checkUserExist(string contactNumber, unordered_map<string, User> users, string& currentContName);
	
 bool checkContactExist(string conNum, const User users);

 bool addCont(User& user, string contactName, string contNumber);



