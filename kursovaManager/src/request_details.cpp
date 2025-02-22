/*---------------*/
#include "request.h"
/*---------------*/

using std::string;

const string RequestType::getType()const {
	return type;
}

void RequestType::setType(string newType) {
	type = newType;
}

const string RequestStatus::getStatus()const {
	return status;
}

void RequestStatus::setStatus(string newStatus) {
	status = newStatus;
}