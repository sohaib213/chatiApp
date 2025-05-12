#include <string>
#include <unordered_map>
#include <iostream>
#include "AddContact.h"

using namespace std;

//string contNumber;
//string currentContName;

 bool checkUserExist(string contactNumber, unordered_map<string, User> users, string& currentContName) {
	auto it = users.find(contactNumber);
	if (it != users.end()) {
		//contNumber = it->second.getMobileNumber();
		currentContName = it->second.getFirstName() + ' ' + it->second.getLastName();
		return true;
	}
	return false;
 }

 bool checkContactExist(string contNum,const User user) {
	
	const auto& contacts = user.getContactsPhones(); 
	if (contacts.find(contNum) != contacts.end()) {
		return true;
	}
	return false;
 }


 bool addCont(User& user, string contactName,string contNumber) {
	return user.addContactPhone(contNumber, contactName);
 }

 bool checkMemberExist(string contNumber, ChatRoom* c) {
	 for (auto userPhone : c->getUsersID()) {
		 if (userPhone == contNumber)
			 return true;
	 }
	 return false;
 }
