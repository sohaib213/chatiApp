#include <fstream>
#include <sstream>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "User.h"
#include <map>
using namespace std;


static void saveToFile(map<string,User> users) {
	AllocConsole();
	if (freopen("CONOUT$", "w", stdout) == nullptr) {
		cerr << "Failed to redirect stdout to console." << endl;
		return;
	}
	cout << "Users to save: " << users.size() << endl;


	ofstream out("users.txt", ios::binary | ios::trunc);
	if (!out) return;

	int userCount = users.size();
	out.write(reinterpret_cast<char*>(&userCount), sizeof(userCount));

	for (const auto& pair : users) {
		const User u = pair.second;
		size_t len;

		out.write(reinterpret_cast<const char*>(&u.userID), sizeof(u.userID));

		len = u.firstName.size();
		out.write(reinterpret_cast<char*>(&len), sizeof(len));
		out.write(u.firstName.c_str(), len);

		len = u.lastName.size();
		out.write(reinterpret_cast<char*>(&len), sizeof(len));
		out.write(u.lastName.c_str(), len);

		len = u.mobileNumber.size();
		out.write(reinterpret_cast<char*>(&len), sizeof(len));
		out.write(u.mobileNumber.c_str(), len);

		len = u.password.size();
		out.write(reinterpret_cast<char*>(&len), sizeof(len));
		out.write(u.password.c_str(), len);


		int contactCount = u.contactsID.size();
		out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
		for (string contact : u.contactsID) {
			out.write(reinterpret_cast<char*>(&contact), sizeof(contact));
		}

		int storyCount = u.stories.size();
		out.write(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));
		for (string s : u.stories) {
			out.write(reinterpret_cast<char*>(&s), sizeof(s));
		}

		int charRoomsCount = u.chatRoomsID.size();
		out.write(reinterpret_cast<char*>(&charRoomsCount), sizeof(charRoomsCount));
		for (string s : u.chatRoomsID) {
			out.write(reinterpret_cast<char*>(&s), sizeof(s));
		}
	}

	out.close();
}

static void loadFromFile(map<string,User>& users) {

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	cout << "loading from file..... " << endl;

	ifstream in("users.dat", ios::binary);
	if (!in) return;

	users.clear();
	int userCount;
	in.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));

	for (int i = 0; i < userCount; ++i) {
		User u;
		size_t len;
		string temp;

		in.read(reinterpret_cast<char*>(&u.userID), sizeof(u.userID));

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		temp.resize(len);
		in.read(&temp[0], len);
		u.firstName = temp;

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		temp.resize(len);
		in.read(&temp[0], len);
		u.lastName = temp;

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		temp.resize(len);
		in.read(&temp[0], len);
		u.mobileNumber = temp;

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		temp.resize(len);
		in.read(&temp[0], len);
		u.password = temp;



		int contactCount;
		in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
		for (int j = 0; j < contactCount; ++j) {
			in.read(reinterpret_cast<char*>(&len), sizeof(len));
			temp.resize(len);
			in.read(&temp[0], len);
			u.contactsID.push_back(temp);
		}

		int storyCount;
		in.read(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));
		for (int j = 0; j < storyCount; ++j) {
			in.read(reinterpret_cast<char*>(&len), sizeof(len));
			temp.resize(len);
			in.read(&temp[0], len);
			u.stories.push_back(temp);
		}

		int charRoomsCount;
		in.read(reinterpret_cast<char*>(&charRoomsCount), sizeof(charRoomsCount));
		for (int j = 0; j < charRoomsCount; ++j) {
			in.read(reinterpret_cast<char*>(&len), sizeof(len));
			temp.resize(len);
			in.read(&temp[0], len);
			u.chatRoomsID.push_back(temp);
		}
		users[u.mobileNumber] = u;
	}

	in.close();
}