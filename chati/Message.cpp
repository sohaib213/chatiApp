#include "Message.h"


chati::Message::Message() {
	this->text = "";
	this->dateSent = "";
	this->timeSent = "";
	this->isRead = false;
}

chati::Message::Message(string text, int messageID, int senderID, int chatID, string dateSent, string timeSent, bool isRead) {
	this->text = text;
	this->messageID = messageID;
	this->senderID = senderID;
	this->chatID = chatID;
	this->dateSent = dateSent;
	this->timeSent = timeSent;
	this->isRead = false;
}