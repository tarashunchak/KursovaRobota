/*---------------*/
#include "auth.h"
#include "user.h"
/*---------------*/

using namespace std;

string Auth::ID = "";

string Auth::checkAuth(const string login, const string password) {
	/*-------------------------------------------------*/
	if (AdminManager::getLogin() == login && AdminManager::getPass() == password) {
		ID = AdminManager::getAdmin()->getID();
		return "Admin";
	}
	for (int i = 0; i < ManagerDB::getSize(); i++) {
		if (ManagerDB::getManager(i)->getPass() == password && ManagerDB::getManager(i)->getLogin() == login) {
			ID = ManagerDB::getManager(i)->getID();
			return ManagerDB::getManager(i)->role;
		}
	}
	for (int i = 0; i < CustomerDB::getSize(); i++) {
		if (CustomerDB::getCustomer(i)->getPass() == password && CustomerDB::getCustomer(i)->getLogin() == login) {
			ID = CustomerDB::getCustomer(i)->getID();
			return CustomerDB::getCustomer(i)->role;
		}
	}
	/*-------------------------------------------------*/
	return "";
}

string Auth::getUserID() {
	return ID;
}