#include <iostream>
#include <fstream>
#include <iomanip>
/*---------------*/
#include "request.h"
/*---------------*/

using namespace std;

/*--------------------------------------------------*/

Request* RequestInProgress::inProgress = nullptr;
int RequestInProgress::arrsize = 0;
bool RequestInProgress::status = false;

int searchIndex(int ID) {
	for (int i = 0; i < RequestInProgress::arrsize; i++) {
		if (ID == RequestInProgress::inProgress[i].getReqId()) {
			return i;
		}
	}
	return -1;
}

Request& RequestInProgress::getRequest(int ID)const {
	return inProgress[searchIndex(ID)];
}

int RequestInProgress::getSize() {
	return arrsize;
}

bool RequestInProgress::getStatus() {
	return status;
}

void RequestInProgress::addInProgressRequest(const Request& newRequest) {

	Request* temp = new Request[arrsize + 1];
	for (int i = 0; i < arrsize; i++) {
		temp[i] = inProgress[i];
	}
	temp[arrsize] = newRequest;
	delete[] inProgress;
	inProgress = temp;
	/*---------------*/
	ofstream fout("RequestHistory.txt", ios::app);
	fout << inProgress[arrsize];
	fout.close();

	RequestHistory::addRequestHistory(newRequest);
	/*---------------*/
	arrsize++;
	status = true;
}

void RequestInProgress::manageRequest(const REQUEST_ACTION accept, const int ID) {
	int index = searchIndex(ID);

	if (index >= arrsize || index < 0)
		return;

	if (accept){
		if (inProgress[index].getRequestType().getType() == "Tariff Change") {

			inProgress[index].updateRequestStatus("Accept");
			RequestHistory::addRequestHistory(inProgress[index]);
			inProgress[index].getCustomer().getMobile()->getMyPhone()->getMySIM().getTariff() = inProgress[index].getNewTarif();
		}
	}	
	else {
		inProgress[index].updateRequestStatus("Denied");
	}
	/*------------------*/
	ofstream fout("RequestHistory.txt", ios::app);

	fout << inProgress[index];
	fout.close();

	/*------------------*/
	Request* temp = new Request[arrsize - 1];
	for (int i = 0, j = 0; i < arrsize; i++) {
		if (i != index) {
			temp[j] = inProgress[i];
			j++;
		}
	}
	delete[] inProgress;
	inProgress = temp;
	arrsize--;
	if (arrsize == 0) status = false;
}

bool RequestInProgress::printRequest(bool all, int id) {

	if (all) {
		for (int i = 0; i < arrsize; i++) {
			cout << inProgress[i];
			return true;
		}
	}
	else {
		if (searchIndex(id) != -1) {
			cout << inProgress[searchIndex(id)];
			return true;
		}
	}
		return false;
}


RequestInProgress::~RequestInProgress() {
	delete[] inProgress;
	inProgress = nullptr;
}


/*--------------------------------------------------*/
////////////////////////////////////////////////////
/*---------------RequestHistory--------------------*/


Request* RequestHistory::reqHistory = nullptr;
int RequestHistory::arrsize = 0;
bool RequestHistory::status = false;


Request& RequestHistory::getRequest(int ID)const {
	return reqHistory[ID];
}

int RequestHistory::getSize() {
	return arrsize;
}

void RequestHistory::addRequestHistory(const Request& newRequest) {
	Request* temp = new Request[arrsize + 1];
	for (int i = 0; i < arrsize; i++) {
		temp[i] = reqHistory[i];
	}
	temp[arrsize] = newRequest;
	delete[] reqHistory;
	reqHistory = temp;
	arrsize++;
	status = true;
}

void RequestHistory::printRequest(bool all, int id) {
	if (all) {
		for (int i = 0; i < arrsize; i++) {
			cout << reqHistory[i];
		}
	}
	else {
		cout << reqHistory[id-1];
	}
}

RequestHistory::~RequestHistory() {
	delete[] reqHistory;
	reqHistory = nullptr;
}

/*--------------------------------------------------*/