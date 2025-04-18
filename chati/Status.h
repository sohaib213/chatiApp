#pragma once
#include <string>

using namespace std;

enum class StatusType { Seen, Unseen };

class Status {
public:
    string dateSent;
    string timeSent;
    StatusType statusType;

    Status(string dateSent, string timeSent, StatusType statusType);
    Status();
};
