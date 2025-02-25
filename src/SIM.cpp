#include "./../include/SIM.h"

using std::string;


Balance::Balance(float balance) :balance(balance) {}

float Balance::getBalanceValue()const {
	return balance;
}

void Balance::addBalanceValue(const float amount) {
	balance += amount;
}






SIM::SIM(string num):number(num){}

SIM::SIM(string num, Balance b) :SIM(num) {
	balance = b;
}

SIM::SIM(string num, Balance b, Tariff& tariff) : SIM(num, b){
	this->tariff = &tariff;
}

SIM::SIM(const SIM& other) {
	this->number = other.number;
	this->balance = other.balance;
	this->tariff = other.tariff;
}

string SIM::getNumber()const {
	return number;
}

Balance SIM::getBalance()const {
	return balance;
}

Tariff& SIM::getTariff() {
	if (!tariff)
		tariff = &TariffDB::getTariff(1);

	return *tariff;
}

SIM& SIM::operator=(const SIM& other) {
	if (this != &other) {
		this->number = other.number;
		this->balance = other.balance;
		this->tariff = other.tariff;
	}
	return *this;
}

//SIM::~SIM() {
//	delete balance;
//}
