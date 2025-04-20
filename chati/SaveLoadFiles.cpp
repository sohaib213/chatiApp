#include <fstream>
#include <sstream>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "User.h"
#include <map>
#include "ChatRoom.h"
#include <unordered_map>


using namespace std;


static void writeString(ofstream& out, string word) {
	size_t len = word.size();
	out.write(reinterpret_cast<char*>(&len), sizeof(len));
	out.write(word.c_str(), len);
}

static void readString(ifstream &in, string &s) {
	string temp;
	size_t len;

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	temp.resize(len);
	in.read(&temp[0], len);
	s = temp;
}

static void writeStringVector(ofstream &out, int count, const vector<string> vec) {
	size_t len;
	out.write(reinterpret_cast<char*>(&count), sizeof(count));
	for (const string& s : vec) {
		len = s.size();
		out.write(reinterpret_cast<char*>(&len), sizeof(len));
		out.write(s.c_str(), len);
	}
}

static void writeIntVector(ofstream& out, int count, const vector<int> vec) {
	out.write(reinterpret_cast<char*>(&count), sizeof(count));
	for (const int& i : vec)
		out.write(reinterpret_cast<const char*>(&i), sizeof(i));
}

static void readStringVector(ifstream &in, vector<string> &vec) {

	string temp;
	int contactCount;
	size_t len;

	in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (int j = 0; j < contactCount; ++j) {
		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		temp.resize(len);
		in.read(&temp[0], len);
		vec.push_back(temp);
	}
}

static void readIntVector(ifstream& in, vector<int>& vec) {

	int contactCount;
	int temp;
	in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (int j = 0; j < contactCount; ++j) {
		in.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		vec.push_back(temp);
	}
}


static void saveToFile(map<string,User> users, unordered_map<int, ChatRoom> chatRooms, unordered_map<int, chati::Message> messages) {
	AllocConsole();
	if (freopen("CONOUT$", "w", stdout) == nullptr) {
		cerr << "Failed to redirect stdout to console." << endl;
		return;
	}


	//save users to file
	ofstream out("users.txt", ios::binary | ios::trunc);
	if (!out) return;

	int userCount = users.size();
	out.write(reinterpret_cast<char*>(&userCount), sizeof(userCount));

	for (const auto& pair : users) {
		const User u = pair.second;
		size_t len;

		out.write(reinterpret_cast<const char*>(&u.userID), sizeof(u.userID));


		writeString(out, u.firstName);
		//len = u.firstName.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.firstName.c_str(), len);
		
		writeString(out, u.lastName);
		//len = u.lastName.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.lastName.c_str(), len);


		writeString(out, u.mobileNumber);
		//len = u.mobileNumber.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.mobileNumber.c_str(), len);

		writeString(out, u.password);
		//len = u.password.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.password.c_str(), len);



		int contactCount = u.contactsID.size();
		writeIntVector(out, contactCount, u.contactsID);

		//out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
		//for (const string& s : u.contactsID) {
		//	len = s.size();
		//	out.write(reinterpret_cast<char*>(&len), sizeof(len)); 
		//	out.write(s.c_str(), len);                             
		//}

		int storyCount = u.stories.size();
		writeIntVector(out, storyCount, u.stories);

		//out.write(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));
		//for (const string& s : u.stories) {
		//	len = s.size();
		//	out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//	out.write(s.c_str(), len);                           
		//}




		int charRoomsCount = u.chatRoomsID.size();
		writeIntVector(out, charRoomsCount, u.chatRoomsID);

		//out.write(reinterpret_cast<char*>(&charRoomsCount), sizeof(charRoomsCount));
		//for (const string& s : u.chatRoomsID) {
		//	len = s.size();
		//	out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//	out.write(s.c_str(), len);                             
		//}


	}

	out.close();

	// save chat rooms to file
	out.open("chatRooms.txt", ios::binary | ios::trunc);
	if (!out) return;

	int chatRoomCount = chatRooms.size();
	out.write(reinterpret_cast<char*>(&chatRoomCount), sizeof(chatRoomCount));
	for (const auto& pair : chatRooms) {
		const ChatRoom c = pair.second;
		size_t len;


		out.write(reinterpret_cast<const char*>(&c.chatRoomID), sizeof(c.chatRoomID));


        out.write(reinterpret_cast<const char*>(&c.isDual), sizeof(c.isDual));

		int usersIDCount = c.usersID.size();
		writeIntVector(out, usersIDCount, c.usersID);

		int messagedCount = c.messagesID.size();
		out.write(reinterpret_cast<char*>(&messagedCount), sizeof(messagedCount));
		for (const int& i : c.messagesID) 
			out.write(reinterpret_cast<const char*>(&i), sizeof(i));
		
	}
	out.close();

	// save messages to file
	out.open("messages.txt", ios::binary | ios::trunc);
	if (!out) return;
	int messageCount = messages.size();
	out.write(reinterpret_cast<char*>(&messageCount), sizeof(messageCount));
	for (const auto& pair : messages) {
		const chati::Message m = pair.second;
		size_t len;
		out.write(reinterpret_cast<const char*>(&m.messageID), sizeof(m.messageID));
		out.write(reinterpret_cast<const char*>(&m.chatID), sizeof(m.chatID));
		out.write(reinterpret_cast<const char*>(&m.senderID), sizeof(m.senderID));
		writeString(out, m.text);
		writeString(out, m.dateSent);
		writeString(out, m.timeSent);
		out.write(reinterpret_cast<const char*>(&m.isRead), sizeof(&m.isRead));
	}
	out.close();
}

static void loadFromFile(map<string,User>& users, unordered_map<int, ChatRoom> &chatRooms, unordered_map<int, chati::Message> &messages) {

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	//load users from file
	ifstream in("users.txt", ios::binary);
	if (!in) {
		cout << "Could not open users file for reading." << endl;
		return;
	}
	users.clear();
	int userCount;
	in.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));

	for (int i = 0; i < userCount; ++i) {
		User u;

		in.read(reinterpret_cast<char*>(&u.userID), sizeof(u.userID));

		readString(in, u.firstName);
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.firstName = temp;



		readString(in, u.lastName);
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.lastName = temp;

		readString(in, u.mobileNumber);
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.mobileNumber = temp;

		readString(in, u.password);
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.password = temp;


		readIntVector(in, u.contactsID);
		//int contactCount;
		//in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
		//for (int j = 0; j < contactCount; ++j) {
		//	in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//	temp.resize(len);
		//	in.read(&temp[0], len);
		//	u.contactsID.push_back(temp);
		//}

		readIntVector(in, u.stories);
		//int storyCount;
		//in.read(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));
		//for (int j = 0; j < storyCount; ++j) {
		//	in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//	temp.resize(len);
		//	in.read(&temp[0], len);
		//	u.stories.push_back(temp);
		//}

		readIntVector(in, u.chatRoomsID);
		//int charRoomsCount;
		//in.read(reinterpret_cast<char*>(&charRoomsCount), sizeof(charRoomsCount));
		//for (int j = 0; j < charRoomsCount; ++j) {
		//	in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//	temp.resize(len);
		//	in.read(&temp[0], len);
		//	u.chatRoomsID.push_back(temp);
		//}
		users[u.mobileNumber] = u;
		
	}

	in.close();

	// load chatRooms from file
	in.open("chatRooms.txt", ios::binary);

	if (!in) {
		cout << "Could not open chatRooms file for reading." << endl;
		return;
	}
	chatRooms.clear();
	int chatRoomCount;
	in.read(reinterpret_cast<char*>(&chatRoomCount), sizeof(chatRoomCount));
	for (int i = 0; i < chatRoomCount; ++i) {

		ChatRoom c;

		in.read(reinterpret_cast<char*>(&c.chatRoomID), sizeof(c.chatRoomID));


		in.read(reinterpret_cast<char*>(&c.isDual), sizeof(c.isDual));
		
		int usesrsIDCount = c.usersID.size();
		readIntVector(in, c.usersID);

		int temp;
		int messagedCount;
		in.read(reinterpret_cast<char*>(&messagedCount), sizeof(messagedCount));
		for (int j = 0; j < messagedCount; ++j) {
			in.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			c.messagesID.push_back(temp);

		}
		
		chatRooms[c.chatRoomID] = c;
		
	}
	in.close();

	// load messages from file
	in.open("messages.txt", ios::binary);
	if (!in) {
		cout << "Could not open messages file for reading." << endl;
		return;
	}
	messages.clear();
	int messageCount;
	in.read(reinterpret_cast<char*>(&messageCount), sizeof(messageCount));
	for (int i = 0; i < messageCount; ++i) {
		chati::Message m;
		size_t len;

		in.read(reinterpret_cast<char*>(&m.messageID), sizeof(m.messageID));
		in.read(reinterpret_cast<char*>(&m.chatID), sizeof(m.chatID));
		in.read(reinterpret_cast<char*>(&m.senderID), sizeof(m.senderID));
		readString(in, m.text);
		readString(in, m.dateSent);
		readString(in, m.timeSent);
		in.read(reinterpret_cast<char*>(&m.isRead), sizeof(&m.isRead));


		messages[m.messageID] = m;
		
	}
	in.close();
}