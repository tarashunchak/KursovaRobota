#include "request.h"

using namespace std;

void checkStringLength(size_t l);

/*-----------------------------------------------*/

void RequestManager::sendRequest(Customer& customer, Tariff& tariff) {
	RequestInProgress::addInProgressRequest(Request(customer, tariff));
}

bool RequestManager::getStatus()const {
	return RequestInProgress::getStatus();
}

void RequestManager::manageRequest(const REQUEST_ACTION accept, const int id)const {
	RequestInProgress::manageRequest(accept, id);
}

void RequestManager::printInProgressRequest(bool all, int id)const {
	RequestInProgress::printRequest(all, id);
}

void RequestManager::printRequestHistory(bool all, int id)const {
	RequestHistory::printRequest(all, id);
}

///////////////////////////////////
