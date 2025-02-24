#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
/*---------------*/
#include "person.h"
/*---------------*/

using std::string;
using std::ostream;

class Manager {
private:
	Person* me = nullptr;
	string login = "";
  string pass = "";
	float salary;
	static int ID;
	string myID = "m";
public:
	string role = "Manager";
	Manager(Person&, string, string, float);
	Manager(Person& , float );
	Person& getPerson()const;
	string getPass()const;
	string getLogin()const;
	float getSalary()const;
	string getID()const;
	friend ostream& operator<<(ostream& os, const Manager& mgr);
	~Manager();
};

class ManagerDB {
private:
	static Manager** mgList;
	static int arrsize;
	static bool status;
public:
	static Manager* getManager(int);
	static int getSize();
	static bool getStatus();
	static void addManager(const Manager&);
	static void removeEmployee(int ID);
	static bool printEmployee(bool all, int ID);
	~ManagerDB();
	//static int searchIndex(int ID);
};

struct ManagerController {
	Manager& getManager(int)const;
	void addManager(Person&, float);
	void addManager(const Manager&);
	void deleteManager(int);
	void printManager(bool all = true, string ID = "")const;
};


#endif
