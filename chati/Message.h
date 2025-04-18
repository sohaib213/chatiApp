#pragma once
#include <string>
using namespace std;

class Message {
public:
    string messageID;
    string userID;
    string text;

    Message(string messageID, string userID, string text, string dateSent, string timeSent);


};
