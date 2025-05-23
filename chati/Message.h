#pragma once
#include <string>
using namespace std;

namespace chati {
    class Message {
        static int messagesCounter; // Static variable to keep track of message IDs
        int messageID;
        string senderPhone;
        int chatID;
        string text;
        string dateSent;
        int hour;
		int minute;
        int second;
        bool isRead = false;

    public:

        // constructors
        Message();
        Message(string text, string senderPhone, int chatID, string dateSent, int hour, int minute, int second, bool isRead);

        // Getters
		static int getMessageCounter();
        int getMessageID() const;
        string getSenderPhone() const;
        int getChatID() const;
        string getText() const;
        string getDateSent() const;
        int getHourSent() const;
        int getMinuteSent() const;
		int getSecondSent() const;
        bool getIsRead() const;
      

        // Setters
		static void setMessageCounter(int count);
        void setMessageID(int id);
        void setSenderPhone(string senderPhone);
        void setChatID(int id);
        void setText(const string& txt);
        void setDateSent(const string& date);
        void setHourSent(int hour);
        void setMinuteSent(int minute);
		void setSecondSent(int second);
        void setIsRead(bool read);

        static void incrementMessageCounter();
    };

    //~Message();
}

