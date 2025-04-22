#pragma once
#include <string>
using namespace std;

class Contact {
    int contactID;
    string contactName;
    string contactNumber;

public:
    Contact() = default;
    Contact(int id, string name, string number)
        : contactID(id), contactName(name), contactNumber(number) {
    }

    Contact(int id, string name)
        : contactID(id), contactName(name), contactNumber("") {
    }

    int getContactID() const { return contactID; }
    string getContactName() const { return contactName; }
    string getContactNumber() const { return contactNumber; }

    void setContactID(int id) { contactID = id; }
    void setContactName(string name) { contactName = name; }
    void setContactNumber(string number) { contactNumber = number; }
};
