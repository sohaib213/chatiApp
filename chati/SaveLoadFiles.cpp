#include <fstream>
#include <sstream>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "User.h"
#include "Story.h"
#include "Contact.h"
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


static void writeStringVector(ofstream& out, const vector<string> vec) {
	int count = vec.size();
	size_t len;
	out.write(reinterpret_cast<char*>(&count), sizeof(count));
	for (const string& s : vec) {
		len = s.size();
		out.write(reinterpret_cast<char*>(&len), sizeof(len));
		out.write(s.c_str(), len);
	}
}
static vector<string> readStringVector(ifstream& in) {

	vector<string> vec;

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
	return vec;
}

static void writeIntVector(ofstream& out, int count, const vector<int> vec) {
	out.write(reinterpret_cast<char*>(&count), sizeof(count));
	for (const int& i : vec)
		out.write(reinterpret_cast<const char*>(&i), sizeof(i));
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


static void writeUnOrderedSet(ofstream& out,  unordered_set<int> s) {
	int contactCount = s.size();
	out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (const int& i : s) {
		out.write(reinterpret_cast<const char*>(&i), sizeof(i));
	}
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

static void writeSet(ofstream& out, const set<int>& s) {
	int contactCount = s.size();
	out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (const int& i : s) {
		out.write(reinterpret_cast<const char*>(&i), sizeof(i));
	}
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

static void writeMap(ofstream& out, const map<string, string>& c) {
	int contactCount = c.size();
	out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	for (const auto& i : c) {
		
		writeString(out, i.first);
		writeString(out, i.second);
	}
}
static map<string, string> readMap(ifstream& in) {
	map<string, string> map;

	int contactCount;
	in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));
	
	for (int j = 0; j < contactCount; ++j) {

		string temp = readString(in);
		string s = readString(in);
		map[temp] = s;
	}
	return map;
}





static void saveToFile(
	unordered_map<string, User> users,
	unordered_map<int, ChatRoom> chatRooms,
	unordered_map<int, chati::Message> messages,
	unordered_map<int, Story> stories,
	unordered_map<int, Contact> contacts) {

	AllocConsole();
	if (freopen("CONOUT$", "w", stdout) == nullptr) {
		cerr << "Failed to redirect stdout to console." << endl;
		return;
	}

	// Save users
	ofstream out("users.txt", ios::binary | ios::trunc);
	if (!out) return;
	int userCount = users.size();
	out.write(reinterpret_cast<char*>(&userCount), sizeof(userCount));

	for (const auto& pair : users) {
		const User u = pair.second;

		writeString(out, u.getFirstName());
		writeString(out, u.getLastName());
		writeString(out, u.getMobileNumber());
		writeString(out, u.getPassword());
		writeString(out, u.getProfilePhoto());

		writeMap(out, u.getContactsPhones());
		writeSet(out, u.getStoriesID());
		writeSet(out, u.getChatRoomsID());
	}
	out.close();

	// Save chat rooms
	out.open("chatRooms.txt", ios::binary | ios::trunc);
	if (!out) return;
	int chatRoomsCounter = ChatRoom::getChatRoomsCounter();
	out.write(reinterpret_cast<char*>(&chatRoomsCounter), sizeof(chatRoomsCounter));
	int chatRoomCount = chatRooms.size();
	out.write(reinterpret_cast<char*>(&chatRoomCount), sizeof(chatRoomCount));

	for (const auto& pair : chatRooms) {
		const ChatRoom c = pair.second;
		int x;

		x = c.getChatRoomID();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = c.getIsDual();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));

		writeStringVector(out, c.getUsersID());
		writeString(out, c.getGroupPhoto());
		writeString(out, c.getGroupName());
		writeString(out, c.getAdminID());

		int messagedCount = c.getMessagesID().Length();
		out.write(reinterpret_cast<char*>(&messagedCount), sizeof(messagedCount));

		chati::LinkedList list1 = c.getMessagesID();
		for (chati::Node* item = list1.begin(); item != list1.end(); item = item->next) {
			int messageID = item->value;
			out.write(reinterpret_cast<const char*>(&messageID), sizeof(messageID));
		}
	}
	out.close();

	// Save messages
	out.open("messages.txt", ios::binary | ios::trunc);
	if (!out) return;
	int messageCounter = chati::Message::getMessageCounter();
	out.write(reinterpret_cast<char*>(&messageCounter), sizeof(messageCounter));
	int messageCount = messages.size();
	out.write(reinterpret_cast<char*>(&messageCount), sizeof(messageCount));

	for (const auto& pair : messages) {
		const chati::Message m = pair.second;
		int x;

		x = m.getMessageID();
		cout << "Message ID to write: " << x << endl;
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getChatID();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		writeString(out, m.getSenderPhone());
		writeString(out, m.getText());
		writeString(out, m.getDateSent());
		x = m.getHourSent();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getMinuteSent();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getSecondSent();
		out.write(reinterpret_cast<const char*>(&x), sizeof(x));
		x = m.getIsRead();
		out.write(reinterpret_cast<const char*>(&x), sizeof(&x));
	}
	out.close();

	// Save stories
	out.open("stories.txt", ios::binary | ios::trunc);
	if (!out) return;
	int storyCount = stories.size();
	out.write(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));

	for (const auto& pair : stories) {
		const Story& s = pair.second;

		int id = s.getStoryID();
		out.write(reinterpret_cast<const char*>(&id), sizeof(id));

		time_t publishTime = s.getPublishTime();
		out.write(reinterpret_cast<const char*>(&publishTime), sizeof(publishTime));

		writeString(out, s.getStoryPhoto());
		writeString(out, s.getStoryText());
		writeString(out, s.getFontName());

		float fontSize = s.getFontSize();
		out.write(reinterpret_cast<const char*>(&fontSize), sizeof(fontSize));

		int fontStyle = s.getFontStyle();
		out.write(reinterpret_cast<const char*>(&fontStyle), sizeof(fontStyle));

		writeString(out, s.getColorHex());
	}
	out.close();

	// Save contacts
	out.open("contacts.txt", ios::binary | ios::trunc);
	if (!out) return;
	int contactCount = contacts.size();
	out.write(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));

	for (const auto& pair : contacts) {
		const Contact& c = pair.second;
		int id = c.getContactID();
		out.write(reinterpret_cast<const char*>(&id), sizeof(id));
		writeString(out, c.getContactName());
		writeString(out, c.getContactNumber());
	}
	out.close();
}


static void loadFromFile(
	unordered_map<string, User>& users,
	unordered_map<int, ChatRoom>& chatRooms,
	unordered_map<int, chati::Message>& messages,
	unordered_map<int, Story>& stories,
	unordered_map<int, Contact>& contacts) {

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	// ---------------- Load Users ----------------
	ifstream in("users.txt", ios::binary);
	if (!in) {
		cout << "Could not open users file for reading." << endl;
		return;
	}

	users.clear();
	int userCount = 0;
	try {
		in.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));
	}
	catch (const std::exception& e) {
		cout << "Error reading user count: " << e.what() << endl;
	}

	for (int i = 0; i < userCount; ++i) {
		User u;

		u.setFirstName(readString(in));
		u.setLastName(readString(in));
		u.setMobileNumber(readString(in));
		u.setPassword(readString(in));
		u.setProfilePhoto(readString(in));
		u.setContactsPhones(readMap(in));
		u.setStoriesID(readSet(in));
		u.setChatRoomsID(readSet(in));

		users[u.getMobileNumber()] = u;
	}
	in.close();

	// ---------------- Load ChatRooms ----------------
	in.open("chatRooms.txt", ios::binary);
	if (!in) {
		cout << "Could not open chatRooms file for reading." << endl;
		return;
	}

	chatRooms.clear();
	int chatRoomsCounter = 0;
	in.read(reinterpret_cast<char*>(&chatRoomsCounter), sizeof(chatRoomsCounter));
	ChatRoom::setChatRoomsCounter(chatRoomsCounter);
	int chatRoomCount = 0;
	in.read(reinterpret_cast<char*>(&chatRoomCount), sizeof(chatRoomCount));

	for (int i = 0; i < chatRoomCount; ++i) {
		ChatRoom c;
		int x;

		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		c.setChatRoomID(x);

		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		c.setIsDual(x);

		c.setUsersID(readStringVector(in));
		c.setGroupPhoto(readString(in));
		c.setGroupName(readString(in));
		c.setAdminID(readString(in));

		int messagedCount;
		in.read(reinterpret_cast<char*>(&messagedCount), sizeof(messagedCount));
		for (int j = 0; j < messagedCount; ++j) {
			int messageID;
			in.read(reinterpret_cast<char*>(&messageID), sizeof(messageID));
			c.addMessageIDInFiles(messageID);
		}

		chatRooms[c.getChatRoomID()] = c;
	}
	in.close();

	// ---------------- Load Messages ----------------
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
		int x;

		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		cout << "Message ID From Read: " << x << endl;
		m.setMessageID(x);
		in.read(reinterpret_cast<char*>(&x), sizeof(x));
		m.setChatID(x);

		m.setSenderPhone(readString(in));
		m.setText(readString(in));
		m.setDateSent(readString(in));
		in.read(reinterpret_cast<char*>(&x), sizeof(x)); m.setHourSent(x);
		in.read(reinterpret_cast<char*>(&x), sizeof(x)); m.setMinuteSent(x);
		in.read(reinterpret_cast<char*>(&x), sizeof(x)); m.setSecondSent(x);
		bool isRead;
		in.read(reinterpret_cast<char*>(&isRead), sizeof(&isRead));
		m.setIsRead(isRead);

		messages[m.getMessageID()] = m;
	}
	in.close();

	// ---------------- Load Stories ----------------
	in.open("stories.txt", ios::binary);
	if (!in) {
		cout << "Could not open stories file for reading." << endl;
		return;
	}

	stories.clear();
	int storyCount = 0;
	in.read(reinterpret_cast<char*>(&storyCount), sizeof(storyCount));

	for (int i = 0; i < storyCount; ++i) {
		Story s;
		int id;
		time_t publishTime;
		float fontSize;
		int fontStyle;

		in.read(reinterpret_cast<char*>(&id), sizeof(id));
		s.setStoryID(id);

		in.read(reinterpret_cast<char*>(&publishTime), sizeof(publishTime));
		s.setPublishTime(publishTime);

		s.setStoryPhoto(readString(in));
		s.setStoryText(readString(in));
		s.setFontName(readString(in));

		in.read(reinterpret_cast<char*>(&fontSize), sizeof(fontSize));
		s.setFontSize(fontSize);

		in.read(reinterpret_cast<char*>(&fontStyle), sizeof(fontStyle));
		s.setFontStyle(fontStyle);

		s.setColorHex(readString(in));

		stories[s.getStoryID()] = s;
	}
	in.close();

	// ---------------- Load Contacts ----------------
	in.open("contacts.txt", ios::binary);
	if (!in) {
		cout << "Could not open contacts file for reading." << endl;
		return;
	}

	contacts.clear();
	int contactCount = 0;
	in.read(reinterpret_cast<char*>(&contactCount), sizeof(contactCount));

	for (int i = 0; i < contactCount; ++i) {
		Contact c;
		int id;

		in.read(reinterpret_cast<char*>(&id), sizeof(id));
		c.setContactID(id);

		c.setContactName(readString(in));
		c.setContactNumber(readString(in));

		contacts[c.getContactID()] = c;
	}
	in.close();
}
