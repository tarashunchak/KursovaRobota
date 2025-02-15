#ifndef TARIFF_H
#define TARIFF_H
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Tariff {
private:
	string name = "Standart";
	float price = 1000.0f;
	float callprice = 10.0f;
public:
	Tariff() = default;
	Tariff(string name, float price, float callprice);
	string getTariffName()const;
	void setTariffName(const string newName);
	float getTariffPrice()const;
	void setTariffPrice(const float newPrice);
	float getCallPrice()const;
	void setCallPrice(const float newCallPrice);
	friend ostream& operator<<(ostream& os, const Tariff& obj);
	Tariff& operator=(const Tariff& other);
};

class TariffDB {
private:
	static Tariff** tariffs;
	static int arrsize;
	static bool status;
public:
	static Tariff& getTariff(const int index);
	static bool getStatus();
	static int getSize();
	static void addTariff(const Tariff& newTariff);
	static void removeTariff(int index);
	static void printTariff();
	~TariffDB();
};

struct TariffManager {
	void addTariff(string name, float price, float callprice);
	void addTariff(const Tariff& newTariff);
	void deleteTariff(const int ID);
	void printTariff(bool all = true, int index = 0)const;
	Tariff& getTariff(int ID = 0)const;
	int getSize()const;
};

#endif