/*---------------*/
#include "./../include/tariff.h"
/*---------------*/

void TariffManager::addTariff(string name, float price, float callprice) {
	TariffDB::addTariff(Tariff(name, price, callprice));
}

void TariffManager::addTariff(const Tariff& newTariff) {
	TariffDB::addTariff(newTariff);
}

void TariffManager::deleteTariff(const int ID) {
	TariffDB::removeTariff(ID);
}

void TariffManager::printTariff(bool all, int index)const {
	TariffDB::printTariff();
}

//void TariffManager::setTariffName(const int ID, const string newName)const {
//	TariffDB::getTariff(ID).setTariffName(newName);
//}
//
//void TariffManager::setTariffPrice(const int ID, const float newPrice)const {
//	TariffDB::getTariff(ID).setTariffPrice(newPrice);
//}
//
//string TariffManager::getTariffName(const int ID)const {
//	return TariffDB::getTariff(ID).getTariffName();
//}
//
//float TariffManager::getTariffPrice(const int ID)const {
//	return TariffDB::getTariff(ID).getTariffPrice();
//}
//
int TariffManager::getSize()const {
	return TariffDB::getSize();
}

Tariff& TariffManager::getTariff(int ID)const {
	return TariffDB::getTariff(ID);
}
