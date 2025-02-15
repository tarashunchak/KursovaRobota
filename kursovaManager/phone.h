#ifndef PHONE_H
#define PHONE_H
/*---------------*/
#include "chat.h"
#include "SIM.h"
/*---------------*/
#include <iostream>

class Phonebook {
private:
	SIM* sim = nullptr;
	int arrsize = 0;
public:
	Phonebook();
	int getSize()const;
	SIM& getContact(int index)const;
	void addContact(const SIM& newContact);
	void deleteContact(int index);
	void printContacts()const;
	~Phonebook();
};

class Call {
private:
	SIM* sim = nullptr;
public:
	Call() = default;
	Call(SIM& sim);
	string getContactNumber()const;
	friend ostream& operator<<(ostream& os, const Call& obj);
};

class CallHistory {
private:
	Call* call = nullptr;
	int arrsize = 0;
	bool status = false;
public:
	bool getStatus()const;
	Call &getCall(int index)const;
	void addCall(const Call &newCall);
	void printCalls(bool all = true, int ID = 0)const;
	~CallHistory();
};

class Mobile {
private:
	SIM& mySim;
	Phonebook& phonebook;
	CallHistory cHistory;
	ChatManager chatmanager;
public:
	Mobile(SIM& sim, Phonebook& phoneB);
	CallHistory getCallHistory()const;
	bool getCallHistoryStatus()const;
	void makeCall(int UID);
	SIM& getMySIM()const;
	void printCalls(bool all = true, int ID = 0)const;
	Phonebook& getPhoneBook()const;
	Mobile& operator=(const Mobile& other);
};

class MobileManager {
private:
	Mobile* myMobile = nullptr;
public:
	MobileManager(Mobile& myPhone);
	Mobile* getMyPhone()const;
	string getMyPhoneNum()const;
	bool getCallHistoryStatus()const;
	void addContact(const SIM& newContact)const;
	void deleteContact(const int ID)const;
	void sendMassage(const string receiver, const string newMassage)const;
	//void printCalls(bool all = true, int ID = 0)const;
	void printContacts()const;
	float getBalanceValue()const;
};

#endif