#pragma once
#include <string>
#include <map>
#include "User.h"
#include <iostream>

using namespace std;



 bool checkUserExist(string contactNumber, map<string, User> users, string& currentContName);
	
 bool checkContactExist(string conNum, const map<string, User>& users);

 bool addCont(User * user, string contactName, string contNumber);



