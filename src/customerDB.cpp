#include <iostream>
#include <iomanip>
/*---------------*/
#include "customer.h"
#include "user.h"
/*---------------*/

using namespace std;

void checkStringLength(size_t l);

int searchIndex3(int ID) {
	for (int i = 0; i < CustomerDB::getSize(); i++) {
		if (CustomerDB::custlist[i]->getID() == UserDB::getUser(ID)->getID()) {
			return i;
		}
	}
	return 0;
}

int searchIndex2(string cID) {
	for (int i = 0; i < CustomerDB::getSize(); i++) {
		if (CustomerDB::custlist[i]->getID() == cID)
			return i;
	}
	return 0;
}

/*-----------------------------------*/

Customer** CustomerDB::custlist = nullptr;
int CustomerDB::arrsize = 0;
bool CustomerDB::status = false;

int CustomerDB::getSize() {
	return arrsize;
}

bool CustomerDB::getStatus() {
	return status;
}

Customer* CustomerDB::getCustomer(string UID) {
	return custlist[searchIndex2(UID)];
}

Customer* CustomerDB::getCustomer(int index) {
	return custlist[index];
}

void CustomerDB::addCustomer(const Customer& newCust) {
	Customer** temp = new Customer * [arrsize + 1];
	for (int i = 0; i < arrsize; i++) {
		temp[i] = custlist[i];
	}
	temp[arrsize] = new Customer(newCust);
	delete[] custlist;
	custlist = temp;

	arrsize++;
	status = true;

}

void CustomerDB::removeCustomer(int ID) {
	int index = searchIndex3(ID);
	Customer** temp = new Customer*[arrsize - 1];
	for (int i = 0, j = 0; i < arrsize; i++) {
		if (i != index) {
			temp[j] = custlist[i];
			j++;
		}
	}
	delete[] custlist;
	custlist = temp;
	arrsize--;
	if (arrsize == 0) {
		status = false;
	}
}

void CustomerDB::printCustomer(bool all, string cID) {
	if (all) {
		for (int i = 0; i < arrsize; i++) {
			cout << *custlist[i];
		}
	}
	else {
		cout << *custlist[searchIndex2(cID)];
	}

}

CustomerDB::~CustomerDB() {
	delete[] custlist;
	custlist = nullptr;
}
