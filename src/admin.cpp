#include <iomanip>

#include "./../include/admin.h"
#include "./../include/user.h"
 
void checkStringLength(size_t);

using namespace std;

int Admin::id = 1;

Admin::Admin(Person& me, string pass, string login, float salary) 
        :me(&me), pass(pass), login(login),  salary(salary) {

	aID = to_string(id++);
	UserDB::addUser(User(this));
}

Person& Admin::getPerson()const {
	return *me;
}

string Admin::getLogin()const {
	return login;
}

string Admin::getPass()const {
	return pass;
}

string Admin::getID()const {
	return aID;
}

float Admin::getSalary()const {
	return salary;
}

ostream& operator<<(ostream& os, const Admin& obj) {
	os << "|F_Name:" << obj.me->getFirstName();
  checkStringLength(obj.me->getFirstName().length());
  os << "|Date_of_B:" << obj.me->getDate();
  checkStringLength(obj.me->getDate().length()); 
	os << "|Gender(0-m/1-f):" << obj.me->getGender() << setw(52 - 18) << "|" << endl
		<< "|Salary:" << std::fixed << std::setprecision(2) << obj.salary << "$" << setw(52 - (std::to_string(obj.salary).length() + 5)) << "|" << endl
		<< "|--------------------------------------------------|" << endl;
	return os;
}



Admin* AdminManager::admin = nullptr;

AdminManager::AdminManager(Admin& newAdmin){
	admin = &newAdmin;
}

string AdminManager::getPass() {
	return admin->getPass();
}

string AdminManager::getLogin() {
	return admin->getLogin();
}

Admin* AdminManager::getAdmin() {
	return admin;
}

void AdminManager::printAdmin() {
	cout << *admin;
}

