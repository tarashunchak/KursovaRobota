#include <string>
#include <iostream>
#include <iomanip>
/*---------------*/
#include "customer.h"
#include "user.h"
/*---------------*/

using namespace std;

void checkStringLength(size_t l);

int Customer::ID = 1;

Customer::Customer(Person& me, MobileManager& phone, string login, string pass)
		:me(new Person(me)), myPhone(&phone), login(login), pass(pass) {

	custID += to_string(ID++);
	UserDB::addUser(User(this));
}

Customer::Customer(Person& me,SIM phone) 
		:me(new Person(me)), phone(new SIM(phone)) {

	custID += to_string(ID++);
	UserDB::addUser(User(this));
}

Person& Customer::getPerson()const{
	return *me;
}

MobileManager* Customer::getMobile()const{
	return myPhone;
}

string Customer::getLogin()const {
	return login;
}

string Customer::getPass()const {
	return pass;
}

string Customer::getID()const {
	return custID;
}

Customer& Customer::operator=(const Customer& other) {
	if (this != &other) {
		this->me = other.me;
		this->myPhone = other.myPhone;
		this->pass = other.pass;
		this->login = other.login;
		this->phone = other.phone;
		this->custID = other.custID;
	}
	return *this;
}

ostream& operator<<(ostream& os, const Customer& obj) {
	os << "|--------------------------------------------------|" << endl;
	os << "|ID: " << obj.custID; // //
	checkStringLength(obj.custID.length() + 5); // // 
	os << "|F_Name: " << obj.me->getFirstName();
	checkStringLength(obj.me->getFirstName().length() + 9);
	os << "|L_Name: " << obj.me->getLastName();
	checkStringLength(obj.me->getLastName().length() + 9);
	if(!obj.myPhone) {
		os << "|Phone_Num: " << obj.phone->getNumber();
		checkStringLength(obj.phone->getNumber().length() + 12);
		os << "|Tarif: " << obj.phone->getTariff().getTariffName();
		checkStringLength(obj.phone->getTariff().getTariffName().length() + 8);
		os << "|Monthly payment: " << obj.phone->getTariff().getTariffPrice() << "$";
		checkStringLength(to_string(obj.phone->getTariff().getTariffPrice()).length() + 12);
	}
	else if (obj.myPhone) {
		os << "|Phone_Num: " << obj.myPhone->getMyPhoneNum();
		checkStringLength(obj.myPhone->getMyPhoneNum().length() + 12);
		os << "|Tarif: " << obj.myPhone->getMyPhone()->getMySIM().getTariff().getTariffName();
		checkStringLength(obj.myPhone->getMyPhone()->getMySIM().getTariff().getTariffName().length() + 8);
		os << "|Monthly payment: " << obj.myPhone->getMyPhone()->getMySIM().getTariff().getTariffPrice() << "$";
		checkStringLength(to_string(obj.myPhone->getMyPhone()->getMySIM().getTariff().getTariffPrice()).length() + 12);
	}

		os << "|--------------------------------------------------|" << endl;
		return os;
}