#include "Message.h"
#include <iostream>
namespace chati {

    int Message::messagesCounter = 0; // Definition with initialization

    Message::Message() : messageID(0), senderID(0), chatID(0), isRead(false) {}

    Message::Message(string text, int userID, int chatID, string dateSent, int hour, int minute, bool isRead)
        : text(text), messageID(messageID), senderID(userID), chatID(chatID), dateSent(dateSent), hour(hour), minute(minute), isRead(isRead) {
    }

    // Getters

    int Message::getMessageCounter() {
        return messagesCounter; // Increment and return the message counter
    }
    int Message::getMessageID() const { return messageID; }
    int Message::getSenderID() const { return senderID; }
    int Message::getChatID() const { return chatID; }
    string Message::getText() const { return text; }
    string Message::getDateSent() const { return dateSent; }
    int Message::getHourSent() const { return hour; }
	int Message::getMinuteSent() const { return minute; }
    bool Message::getIsRead() const { return isRead; }

    // Setters
    void Message::setMessageCounter(int messageCounter) {
        messagesCounter = messageCounter; // Set the message counter
    }
    void Message::setMessageID(int messageID) { this->messageID = messageID; }
    void Message::setSenderID(int senderID) { this->senderID = senderID; }
    void Message::setChatID(int chatID) { this->chatID = chatID; }
    void Message::setText(const string& text) { this->text = text; }
    void Message::setDateSent(const string& dateSent) { this->dateSent = dateSent; }
	void Message::setHourSent(int hour) { this->hour = hour; }
	void Message::setMinuteSent(int minute) { this->minute = minute; }
    void Message::setIsRead(bool isRead) { this->isRead = isRead; }

    void Message::incrementMessageCounter() {
        messagesCounter++; // Increment the message counter
    }
}