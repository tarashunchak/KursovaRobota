#include <iostream>
#include <iomanip>
/*---------------*/
#include "./../include/request.h"
/*---------------*/

using namespace std;

/////////////REQUEST/////////////

int Request::id = 1;

Request::Request(Customer& cust, Tariff& newTariff)
		: reqSender(&cust), newTariff(&newTariff), reqID(id++) {}


Customer& Request::getCustomer()const {
	return *reqSender;
}

Tariff& Request::getNewTarif()const {
	return *newTariff;
}

RequestType Request::getRequestType()const {
	return reqType;
}

int Request::getReqId()const {
	return reqID;
}

void Request::updateRequestStatus(string newStatus) {
	reqStatus.setStatus(newStatus);
}

RequestStatus Request::getRequestStatus()const {
	return reqStatus;
}

Request& Request::operator=(const Request& other) {
	if (this != &other) {
		this->id = other.id;
		this->reqID = other.reqID;
		this->newTariff = other.newTariff;
		this->reqSender = other.reqSender;
		this->reqType = other.reqType;
		this->reqStatus = other.reqStatus;
	}
	return *this;
}

ostream& operator<<(ostream& os, const Request& req) {
	os << "|ID: " << req.reqID << setw(52 - (to_string(req.reqID).length() + 4)) << "|\n";
	os << "|Cust_Num: " << req.reqSender->getMobile()->getMyPhoneNum()
		<< setw(52 - (req.reqSender->getMobile()->getMyPhoneNum().length() + 10)) << "|\n";
	os << "|Request_type: " << req.reqType.getType()
		<< setw(52 - (req.reqType.getType().length() + 14)) << "|\n";
	os << "|Old_Value: " << req.getCustomer().getMobile()->getMyPhone()->getMySIM().getTariff().getTariffName()
		<< setw(52 - (req.getCustomer().getMobile()->getMyPhone()->getMySIM().getTariff().getTariffName().length() + 11)) << "|\n";
	os << "|New_Value: " << req.getNewTarif().getTariffName()
		<< setw(52 - (req.getNewTarif().getTariffName().length() + 11)) << "|\n";
	os << "|Status: " << req.reqStatus.getStatus()
		<< setw(52 - (req.reqStatus.getStatus().length() + 8)) << "|\n";
	os << "|--------------------------------------------------|" << endl;
	return os;
}
////////////////////////////////

