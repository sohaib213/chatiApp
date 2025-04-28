#pragma once
#include <string>
#include <map>
#include "User.h"
#include <iostream>

using namespace std;



 bool checkContactExist(string contactNumber, map<string, User> users, string& currentContName);
	


 bool addCont(User * user, string contactName, string contNumber);



