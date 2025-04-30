#include <string>
#include <map>
#include "User.h"
#include <iostream>
#include "AddContact.h"

using namespace std;

//string contNumber;
//string currentContName;

 bool checkUserExist(string contactNumber, map<string, User> users, string& currentContName) {
	auto it = users.find(contactNumber);
	if (it != users.end()) {
		//contNumber = it->second.getMobileNumber();
		currentContName = it->second.getFirstName();
		return true;
	}
	return false;
 }

 bool checkContactExist(string contNum,const map<string, User>& users) {
	
	 for (const auto& user : users) {
		 const auto& contacts = user.second.getContactsPhones(); 
		 if (contacts.find(contNum) != contacts.end()) {
			 return true;
		 }
	 }
	return false;
 }

 bool addCont(User* user, string contactName,string contNumber) {
	return user->addContactPhone(contNumber, contactName);
 }

