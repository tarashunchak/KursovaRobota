#ifndef SIM_H
#define SIM_H
/*---------------*/
#include "tariff.h"
/*---------------*/

class Balance {
private:
	float balance = 0;
public:
	Balance() = default;
	explicit Balance(float balance);
	float getBalanceValue()const;
	void addBalanceValue(const float amount);
};

class SIM {
private:
	string number = "";
	Balance balance;
	Tariff* tariff = nullptr;
public:
	SIM() = default;
	explicit SIM(string num);
	SIM(string num, Balance b);
	SIM(string num, Balance b, Tariff& tariff);
	SIM(const SIM& other);
	string getNumber()const;
	Balance getBalance()const;
	Tariff& getTariff();
	SIM& operator=(const SIM& other);
	//~SIM();
};


#endif
