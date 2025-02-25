#include <string>
#include <iostream>
#include <iomanip>
/*----------------*/
#include "./../include/manager.h"
#include "./../include/person.h"
#include "./../include/user.h"
/*----------------*/

using namespace std;

void checkStringLength(size_t l);

/////////////Manager////////////////

int Manager::ID = 1;

Manager::Manager(Person& me, string login, string pass, float salary)
		:me(&me), login(login), pass(pass), salary(salary){

	myID += to_string(ID++);
	UserDB::addUser(User(this));
}

Manager::Manager(Person& me, float salary)
		: me(new Person(me)), salary(salary) {

	myID += to_string(ID++);
	UserDB::addUser(User(this));
}

Person& Manager::getPerson()const {
	return *me;
}

string Manager::getLogin()const{
	return login;
}

string Manager::getPass()const {
	return pass;
}

float Manager::getSalary()const {
	return salary;
}

string Manager::getID()const {
	return myID;
}

Manager::~Manager() {}

ostream& operator<<(ostream& os, const Manager& mgr) {
	os << "|ID: " << mgr.myID;
	checkStringLength((mgr.myID).length() + 5);
	os << "|F_Name: " << mgr.me->getFirstName();
	checkStringLength(mgr.me->getFirstName().length() + 9);
	os << "|L_Name: " << mgr.me->getLastName();
	checkStringLength(mgr.me->getLastName().length() + 9);
	os << "|Date_of_B: " << mgr.me->getDate();
	checkStringLength(mgr.me->getDate().length() + 12);
	os << "|Gender(0-m/1-f): " << mgr.me->getGender();
	checkStringLength(to_string(mgr.me->getGender()).length() + 18);
	os << "|Salary: " << std::fixed << std::setprecision(2) << mgr.salary << "$";
	checkStringLength(to_string(mgr.salary).length() + 6);
	os << "|--------------------------------------------------|" << endl;
	return os;
}
////////////////////////////////////
