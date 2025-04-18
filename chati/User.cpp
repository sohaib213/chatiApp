#include "User.h"

using namespace std;

User::User(string mobileNumber, string password, string firstName, string lastName)
	:mobileNumber(mobileNumber), password(password),
	firstName(firstName), lastName(lastName) {
}
User::User() {

	mobileNumber = "";
	password = "";
	firstName = "";
	lastName = "";
}