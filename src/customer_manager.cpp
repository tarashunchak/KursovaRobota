/*---------------*/
#include "./../include/customer.h"
/*---------------*/

Customer& CustomerManager::getCustomer(string UID)const {
	return *CustomerDB::getCustomer(UID);
}

MobileManager& CustomerManager::getMobile(const string UID)const {
	return *CustomerDB::getCustomer(UID)->getMobile();
}

//void CustomerManager::sendMassage(const int senderID , const string massages, const string receiver)const {
//	getChat().sendMassage(Massage(CustomerDB::getCustomer(senderID)->getPerson().getFirstName(), massage, reseiver));
//}

void CustomerManager::addCustomer(const Customer& newCust)const {
	CustomerDB::addCustomer(newCust);
}

void CustomerManager::deleteCustomer(int UID)const {
	CustomerDB::removeCustomer(UID);
}

void CustomerManager::printCustomers(bool all, string UID)const {
	CustomerDB::printCustomer(all, UID);
}

///////////////////////////////////////////
