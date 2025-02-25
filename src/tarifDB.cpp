#include <iostream>
#include <iomanip>
/*---------------*/
#include "./../include/tariff.h"
/*---------------*/

using namespace std;

/*--------------------------------------------*/
/////////////////////TARIF_DB/////////////////////

Tariff** TariffDB::tariffs = nullptr;
int TariffDB::arrsize = 0;
bool TariffDB::status = false;


bool TariffDB::getStatus() {
	return status;
}

Tariff& TariffDB::getTariff(const int index) {
	return *tariffs[(index-1)];
}

int TariffDB::getSize() {
	return arrsize;
}

void TariffDB::addTariff(const Tariff& newTariff) {
	Tariff** temp = new Tariff * [arrsize + 1];
	for (int i = 0; i < arrsize; i++) {
		temp[i] = tariffs[i];
	}
	temp[arrsize] = new Tariff(newTariff);
	delete[] tariffs;
	tariffs = temp;
	arrsize++;
	status = true;
}

void TariffDB::removeTariff(int index) {
	Tariff** temp = new Tariff * [arrsize - 1];
	for (int i = 0, j = 0; i < arrsize; i++) {
		if (i != index-1) {
			temp[j] = tariffs[i];
			j++;
		}
	}
	delete[] tariffs;
	tariffs = temp;
	arrsize--;
	if (arrsize == 0) {
		status = false;
	}
}

void TariffDB::printTariff() {
	for (int i = 0; i < arrsize; i++) {
		cout << "|ID:" << i + 1 << setw(47) << "|" << endl;
		cout << *tariffs[i];
	}
}

TariffDB::~TariffDB() {
	for (int i = 0; i < arrsize; i++) {
		delete tariffs[i];
	}
	delete[] tariffs;
	tariffs = nullptr;
}


//////////////////////////////////////////////////
