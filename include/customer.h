#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
/*---------------*/
#include "person.h"
#include "SIM.h"
#include "phone.h"
/*---------------*/

/*--------------customer.cpp---------------*/

class Customer {
private:
	Person* me = nullptr;
	MobileManager* myPhone = nullptr;
	string pass = "";
	string login = "";
	SIM* phone = nullptr;//Dlya ne osnovnoho customera
	static int ID;
	string custID = "c";
public:
	const string role = "Customer";
	Customer() = default;
	Customer(Person& me, MobileManager& phone, string login, string pass);
	Customer(Person& me, SIM phone);
	Person& getPerson()const;
	MobileManager* getMobile()const;
	string getLogin()const;
	string getPass()const;
	string getID()const;
	Customer& operator=(const Customer& other);
	friend ostream& operator<<(ostream& os, const Customer& obj);
};

/*------------------------------------------*/
//////////////////////////////////////////////
/*-------------customerDB.cpp---------------*/

class CustomerDB {
private:
	static Customer** custlist;
	static int arrsize;
	static bool status;
public:
	static int getSize();
	static bool getStatus();
	static Customer* getCustomer(string UID);
	static Customer* getCustomer(int index);
	static void addCustomer(const Customer& newCust);
	static void removeCustomer(int UID);
	static void printCustomer(bool all, string UID);
	friend int searchIndex2(string cID);
	friend int searchIndex3(int UID);
	~CustomerDB();
};

/*------------------------------------------------*/
////////////////////////////////////////////////////
/*-------------customer_manager.cpp---------------*/

struct CustomerManager {
	Customer& getCustomer(string UID)const;
	MobileManager& getMobile(const string ID)const;
	//void sendMassage(const int senderID, const string massages, const string receiver)const;
	void addCustomer(const Customer& newCust)const;
	void deleteCustomer(const int ID)const;
	void printCustomers(bool all = true, string ID = "")const;
	//static CustomerDB getCustomerDB()const;
};

#endif
