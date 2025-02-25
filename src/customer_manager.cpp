/*---------------*/
#include "./../include/customer.h"
#include "./../include/person.h"
#include "./../include/phone.h"
#include "./../include/user.h"
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
