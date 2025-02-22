/*---------------*/
#include "user.h"
/*---------------*/

/*---------------User----------------*/

int User::id = 1;

User::User(const Admin* admin) : admin(admin) {
	UID = id++;
}


User::User(const Manager* manager) : manager(manager){
	//UID = manager.getID();
	UID = id++;
}


User::User(const Customer* customer) : customer(customer){
	//UID = customer.getID();
	UID = id++;
}


string User::getLogin() const {
	if (admin != nullptr) 
		return admin->getLogin();
	else if (manager != nullptr)
		return manager->getLogin();
	else if (customer != nullptr)
		return customer->getLogin();

	return "";
}

string User::getPass()const {
	if (admin != nullptr)
		return admin->getPass();
	else if (manager != nullptr)
		return manager->getPass();
	else if (customer != nullptr)
		return customer->getPass();

	return "";
}

string User::getRole()const {
	if (admin != nullptr)
		return admin->role;
	else if (manager != nullptr)
		return manager->role;
	else if(customer != nullptr)
		return customer->role;

	return "";
}

int User::getUID()const {
	return UID;
}

string User::getUIDs()const {
	if (admin != nullptr)
		return admin->getID();
	else if (manager != nullptr)
		return manager->getID();
	else if (customer != nullptr)
		return customer->getID();

	return "";
}

string User::getID()const {
	if (admin != nullptr)
		return admin->getID();
	else if (manager != nullptr)
		return manager->getID();
	else if (customer != nullptr)
		return customer->getID();

	return "";
}

/*--------------UserDB---------------*/


int searchIndex2(int UID) {
	for (int i = 0; i < UserDB::getSize(); i++) {
		if (UserDB::userList[i]->getUID() == UID) {
			return i;
		}
	}
	return -1;
}

string UserDB::searchID(int UID) {
	for (int i = 0; i < UserDB::getSize(); i++) {
		if (UserDB::userList[i]->getUID() == UID) {
			return UserDB::userList[i]->getID();
		}
	}
	return "";
}


User** UserDB::userList = nullptr;
int UserDB::arrsize = 0;
bool UserDB::status = false;

void UserDB::addUser(const User& newUser) {
	User** temp = new User * [arrsize + 1];
	for (int i = 0; i < arrsize; i++) {
		temp[i] = userList[i];
	}
	delete[] userList;
	temp[arrsize] = new User(newUser);
	userList = temp;
	arrsize++;
	status = true;
}

void UserDB::deleteUser(const User& delUser) {
	User** temp = new User * [arrsize - 1];
	for (int i = 0, j = 0; i < arrsize; i++) {
		if (userList[i]->getUID() != delUser.getUID()) {
			temp[j] = userList[i];
			j++;
		}
	}
	delete[] userList;
	userList = temp;
	arrsize--;
	if (arrsize == 0) {
		status = false;
	}
}

int UserDB::getSize() {
	return arrsize;
}

bool UserDB::getStatus(){
	return status;
}

User* UserDB::getUser(int UID, bool byIndex) {
	if (byIndex)
		return userList[UID];

	return userList[searchIndex2(UID)]; 
}


//User* UserDB::getUser(const User& user) {
//	for (int i = 0; i < arrsize; i++) {
//		if (userList[i] == &user) {
//			return userList[i];
//		}
//	}
//}
