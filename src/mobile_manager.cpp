#include "phone.h"

using namespace std;


MobileManager::MobileManager(Mobile& myPhone):myMobile(&myPhone){}


Mobile* MobileManager::getMyPhone()const {
	return myMobile;
}

string MobileManager::getMyPhoneNum()const {
	return myMobile->getMySIM().getNumber();
}

void MobileManager::addContact(const SIM& newContact)const {
	myMobile->getPhoneBook().addContact(newContact);
}

void MobileManager::deleteContact(const int ID)const {
	myMobile->getPhoneBook().deleteContact(ID);
}

void MobileManager::sendMassage(const string receiver, const string newMassage)const {
	
}

//void MobileManager::printCalls(bool all, int ID)const {
//	myMobile->printCalls(all, ID);
//}

void MobileManager::printContacts()const {
	myMobile->getPhoneBook().printContacts();
}

float MobileManager::getBalanceValue()const {
	return myMobile->getMySIM().getBalance().getBalanceValue();
}

bool MobileManager::getCallHistoryStatus()const {
	return myMobile->getCallHistory().getStatus();
}