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

        Message();  
        Message(string text, int messageID, int userID, int chatID, string dateSent, string timeSent, bool isRead);
    };  
}
