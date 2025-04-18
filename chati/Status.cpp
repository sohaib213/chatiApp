#include "Status.h"

Status::Status(string dateSent, string timeSent, StatusType statusType)
    : dateSent(dateSent), timeSent(timeSent), statusType(statusType) {
}
Status::Status() {
	dateSent = "";
	timeSent = "";
	statusType = StatusType::Unseen;
}
