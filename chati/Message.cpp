#include "Message.h"
int chati::Message::messageCounter = 0; // Initialize the static message counter
namespace chati {

    Message::Message() : messageID(0), senderID(0), chatID(0), isRead(false) { messageID = ++messageCounter; }

    Message::Message(string text, int userID, int chatID, string dateSent, string timeSent, bool isRead)
        : text(text), messageID(messageID), senderID(userID), chatID(chatID), dateSent(dateSent), timeSent(timeSent), isRead(isRead) {
        messageID = ++messageCounter;
    }

    // Getters
    int Message::getMessageID() const { return messageID; }
    int Message::getSenderID() const { return senderID; }
    int Message::getChatID() const { return chatID; }
    string Message::getText() const { return text; }
    string Message::getDateSent() const { return dateSent; }
    string Message::getTimeSent() const { return timeSent; }
    bool Message::getIsRead() const { return isRead; }

    // Setters
    void Message::setMessageID(int messageID) { this->messageID = messageID; }
    void Message::setSenderID(int senderID) { this->senderID = senderID; }
    void Message::setChatID(int chatID) { this->chatID = chatID; }
    void Message::setText(const string& text) { this->text = text; }
    void Message::setDateSent(const string& dateSent) { this->dateSent = dateSent; }
    void Message::setTimeSent(const string& timeSent) { this->timeSent = timeSent; }
    void Message::setIsRead(bool isRead) { this->isRead = isRead; }
}
