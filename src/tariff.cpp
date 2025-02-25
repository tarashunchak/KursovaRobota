#include <fstream>
/*---------------*/
#include "./../include/tariff.h"
/*---------------*/

using namespace std;

void checkStringLength(size_t l);

/*--------------------------------------------*/
/////////////////////TARIF/////////////////////
Tariff::Tariff(string name, float price, float callprice)
	:name(name), price(price), callprice(callprice) {
}

string Tariff::getTariffName()const {
	return name;
}

void Tariff::setTariffName(const string newName) {
	name = newName;
}

float Tariff::getTariffPrice()const {
	return price;
}

void Tariff::setTariffPrice(const float newPrice) {
	price = newPrice;
}

float Tariff::getCallPrice()const {
	return callprice;
}

void Tariff::setCallPrice(const float newCallPrice) {
	callprice = newCallPrice;
}

Tariff& Tariff::operator=(const Tariff& other) {
	if (this != &other) {
		this->name = other.name;
		this->price = other.price;
		this->callprice = other.callprice;
	}
	return *this;
}

ostream& operator<<(ostream& os, const Tariff& obj) {
	os << "|Tarif_Name:" << obj.name;
	checkStringLength(obj.name.length() + 12);
	os << "|Price:" << obj.price << "$";
	checkStringLength(to_string(obj.price).length() + 1);
	os << "|Call_Price:" << obj.callprice << "$";
	checkStringLength(to_string(obj.callprice).length() + 6);
	os << "|--------------------------------------------------|" << endl;

	return os;
}

///////////////////////////////////////////////
/*--------------------------------------------*/
