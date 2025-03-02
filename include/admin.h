#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
/*---------------*/
#include "person.h"
/*---------------*/

using std::string;
using std::ostream;

class Admin {
private:
	Person* me = nullptr;
	string login;
	string pass;
	float salary;
	static int id;
	string aID = "a";
public:
  Admin(Person&, string, string, float);
	const string role = "Admin";
	Person& getPerson()const;
	string getPass()const;
	string getLogin()const;
	string getID()const;
	float getSalary()const;
	friend ostream& operator<<(ostream& os, const Admin& obj);
};

class AdminManager {
private:
	static Admin* admin;
public:
	AdminManager(Admin& admin);
	static void printAdmin();
	static string getPass();
	static string getLogin();
	static Admin* getAdmin();
};

#endif
