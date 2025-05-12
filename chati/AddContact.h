#pragma once
#include <string>
#include <map>
#include "User.h"
#include <iostream>
#include "ChatRoom.h"

using namespace std;



 bool checkUserExist(string contactNumber, unordered_map<string, User> users, string& currentContName);
	
 bool checkContactExist(string conNum, const User users);

 bool addCont(User& user, string contactName, string contNumber);

 bool checkMemberExist(string, ChatRoom*);

