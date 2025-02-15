/*---------------*/
#include "phone.h"
/*---------------*/

using std::string;

Mobile::Mobile(SIM& sim,Phonebook& phoneB):mySim(sim),phonebook(phoneB){}


SIM& Mobile::getMySIM()const {
	return mySim;
}

//float Mobile::getBalance()const {
//	return mySim.getBalance().getBalanceValue();
//}

void Mobile::makeCall(int UID) {
	if (UID>0&&UID<=phonebook.getSize()) {
		cHistory.addCall(Call(phonebook.getContact(UID-1)));
		this->getMySIM().getBalance().addBalanceValue(-this->getMySIM().getTariff().getCallPrice());
	}
}

Phonebook& Mobile::getPhoneBook()const{
	return phonebook;
}

CallHistory Mobile::getCallHistory()const {
	return cHistory;
}

bool Mobile::getCallHistoryStatus()const {
	return cHistory.getStatus();
}

//void Mobile::addContact(const SIM& newContact)const {
//	phonebook.addContact(newContact);
//}
//
//void Mobile::deleteContact(const int ID)const {
//	phonebook.deleteContact(ID);
//}
//
//void Mobile::sendMassage(const string receiver, const string newMassage)const {
//	chatmanager.sendMassage(Massage(this->mySim.getNumber(), newMassage, receiver));
//}
//
//bool Mobile::getCallHistoryStatus()const {
//	return cHistory.getCallHistoryStatus();
//}
//
void Mobile::printCalls(bool all, int UID)const {
	cHistory.printCalls(all, UID);
}

Mobile& Mobile::operator=(const Mobile& other) {
	if(this!=&other){
		this->mySim = other.mySim;
		this->phonebook = other.phonebook;
		this->cHistory = other.cHistory;
		this->chatmanager = other.chatmanager;
	}
	return *this;
}
