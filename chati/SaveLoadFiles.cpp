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

static string readString(ifstream& in) {
	string temp;
	size_t len;

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	temp.resize(len);
	in.read(&temp[0], len);
	return temp;
}

static void writeStringVector(ofstream& out, int count, const vector<string> vec) {
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

static void writeUnOrderedSet(ofstream& out,  unordered_set<int> s) {
	int contactCount = s.size();
	out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (const int& i : s) {
		out.write(reinterpret_cast<const char*>(&i), sizeof(i));
	}
}

static void writeSet(ofstream& out, const set<int>& s) {
	int contactCount = s.size();
	out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (const int& i : s) {
		out.write(reinterpret_cast<const char*>(&i), sizeof(i));
	}
}

static void readStringVector(ifstream& in, vector<string>& vec) {

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

static vector<int> readIntVector(ifstream& in) {
	vector<int> vec;
	int contactCount;
	int temp;
	in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (int j = 0; j < contactCount; ++j) {
		in.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		vec.push_back(temp);
	}
	return vec;
}

static set<int> readSet(ifstream& in) {
	set<int> s;
	int contactCount;
	int temp;
	in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (int j = 0; j < contactCount; ++j) {
		in.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		s.insert(temp);
	}
	return s;
}

static unordered_set<int> readUnOrderedSet(ifstream& in) {
	unordered_set<int> s;
	int contactCount;
	int temp;
	in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (int j = 0; j < contactCount; ++j) {
		in.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		s.insert(temp);
	}
	return s;
}


static void saveToFile(map<string, User> users, unordered_map<int, ChatRoom> chatRooms, unordered_map<int, chati::Message> messages) {
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

		int x = u.getUserID();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));


		writeString(out, u.getFirstName());
		//len = u.firstName.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.firstName.c_str(), len);

		writeString(out, u.getLastName());
		//len = u.lastName.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.lastName.c_str(), len);


		writeString(out, u.getMobileNumber());
		//len = u.mobileNumber.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.mobileNumber.c_str(), len);

		writeString(out, u.getPassword());
		//len = u.password.size();
		//out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//out.write(u.password.c_str(), len);



		writeUnOrderedSet(out, u.getContactsID());

		//out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
		//for (const string& s : u.contactsID) {
		//	len = s.size();
		//	out.write(reinterpret_cast<char*>(&len), sizeof(len)); 
		//	out.write(s.c_str(), len);                             
		//}

		writeSet(out, u.getStoriesID());

		//out.write(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));
		//for (const string& s : u.stories) {
		//	len = s.size();
		//	out.write(reinterpret_cast<char*>(&len), sizeof(len));
		//	out.write(s.c_str(), len);                           
		//}




		writeSet(out, u.getChatRoomsID());

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

		int x = c.getChatRoomID();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));

		x = c.getIsDual();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));

		int usersIDCount = c.getUsersID().size();
		writeIntVector(out, usersIDCount, c.getUsersID());

		int messagedCount = c.getMessagesID().size();
		out.write(reinterpret_cast<char*>(&messagedCount), sizeof(messagedCount));
		for (const int& i : c.getMessagesID())
			out.write(reinterpret_cast<const char*>(&i), sizeof(i));

	}
	out.close();

	// save messages to file
	out.open("messages.txt", ios::binary | ios::trunc);
	if (!out) return;
	int messageCounter = chati::Message::getMessageCounter();
	out.write(reinterpret_cast<char*>(&messageCounter), sizeof(messageCounter));
	int messageCount = messages.size();
	out.write(reinterpret_cast<char*>(&messageCount), sizeof(messageCount));
	for (const auto& pair : messages) {
		const chati::Message m = pair.second;
		size_t len;
		int x;
		x = m.getMessageID();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getChatID();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getSenderID();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		writeString(out, m.getText());
		writeString(out, m.getDateSent());
		x = m.getHourSent();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getMinuteSent();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getIsRead();
		out.write(reinterpret_cast<const char*>(&x), sizeof(&x));
	}
	out.close();
}

static void loadFromFile(map<string, User>& users, unordered_map<int, ChatRoom>& chatRooms, unordered_map<int, chati::Message>& messages) {

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	//load users from file
	ifstream in("users.txt", ios::binary);
	if (!in) {
		cout << "Could not open users file for reading." << endl;
		return;
	}
	users.clear();
	int userCount = 0;
	in.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));
	for (int i = 0; i < userCount; ++i) {
		User u;

		int x;
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		u.setUserID(x);

		u.setFirstName(readString(in));
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.firstName = temp;



		u.setLastName(readString(in));
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.lastName = temp;

		u.setMobileNumber(readString(in));
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.mobileNumber = temp;

		u.setPassword(readString(in));
		//in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//temp.resize(len);
		//in.read(&temp[0], len);
		//u.password = temp;


		u.setContactsID(readUnOrderedSet(in));
		//int contactCount;
		//in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
		//for (int j = 0; j < contactCount; ++j) {
		//	in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//	temp.resize(len);
		//	in.read(&temp[0], len);
		//	u.contactsID.push_back(temp);
		//}

		u.setStoriesID(readSet(in));
		//int storyCount;
		//in.read(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));
		//for (int j = 0; j < storyCount; ++j) {
		//	in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//	temp.resize(len);
		//	in.read(&temp[0], len);
		//	u.stories.push_back(temp);
		//}

		u.setChatRoomsID(readSet(in));
		//int charRoomsCount;
		//in.read(reinterpret_cast<char*>(&charRoomsCount), sizeof(charRoomsCount));
		//for (int j = 0; j < charRoomsCount; ++j) {
		//	in.read(reinterpret_cast<char*>(&len), sizeof(len));
		//	temp.resize(len);
		//	in.read(&temp[0], len);
		//	u.chatRoomsID.push_back(temp);
		//}
		users[u.getMobileNumber()] = u;

	}

	in.close();

	// load chatRooms from file
	in.open("chatRooms.txt", ios::binary);

	if (!in) {
		cout << "Could not open chatRooms file for reading." << endl;
		return;
	}
	chatRooms.clear();
	int chatRoomCount = 0;
	in.read(reinterpret_cast<char*>(&chatRoomCount), sizeof(chatRoomCount));
	for (int i = 0; i < chatRoomCount; ++i) {

		ChatRoom c;

		int x;
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		c.setChatRoomID(x);


		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		c.setIsDual(x);

		int usesrsIDCount = c.getUsersID().size();
		c.setUsersID(readIntVector(in));

		int temp;
		int messagedCount;
		in.read(reinterpret_cast<char*>(&messagedCount), sizeof(messagedCount));
		for (int j = 0; j < messagedCount; ++j) {
			in.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			c.addMessageID(temp);

		}

		chatRooms[c.getChatRoomID()] = c;

	}
	in.close();

	// load messages from file
	in.open("messages.txt", ios::binary);
	if (!in) {
		cout << "Could not open messages file for reading." << endl;
		return;
	}
	messages.clear();
	int messagesCounter = 0;
	in.read(reinterpret_cast<char*>(&messagesCounter), sizeof(messagesCounter));
	chati::Message::setMessageCounter(messagesCounter);
	int messageCount = 0;
	in.read(reinterpret_cast<char*>(&messageCount), sizeof(messageCount));
	for (int i = 0; i < messageCount; ++i) {
		chati::Message m;
		size_t len;

		int x;
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		m.setMessageID(x);
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		m.setChatID(x);
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		m.setSenderID(x);
		m.setText(readString(in));
		m.setDateSent(readString(in));
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		m.setHourSent(x);
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		m.setMinuteSent(x);
		bool is;
		in.read(reinterpret_cast<char*>(&is), sizeof(&is));
		m.setIsRead(is);


		messages[m.getMessageID()] = m;

	}
	in.close();
}
