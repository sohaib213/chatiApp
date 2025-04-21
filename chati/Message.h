#pragma once
#include <string>
using namespace std;

namespace chati {
    class Message {
    public:

        int messageID;
        int senderID;
        int chatID;
        string text;
        string dateSent;
        string timeSent;
        bool isRead = false;

        // constructors
        Message();
        Message(string text, int messageID, int userID, int chatID, string dateSent, string timeSent, bool isRead);

        // Getters
        int getMessageID() const;
        int getSenderID() const;
        int getChatID() const;
        string getText() const;
        string getDateSent() const;
        string getTimeSent() const;
        bool getIsRead() const;

        // Setters
        void setMessageID(int id);
        void setSenderID(int id);
        void setChatID(int id);
        void setText(const string& txt);
        void setDateSent(const string& date);
        void setTimeSent(const string& time);
        void setIsRead(bool read);
    };

    //~Message();
}

