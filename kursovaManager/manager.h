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
	string pass = "";
	string login = "";
	float salary;
	static int ID;
	string myID = "m";
public:
	string role = "Manager";
	Manager(Person& me, string login, string pass, float salary);
	Manager(Person& me, float salary);
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
	static Manager* getManager(int index);
	static int getSize();
	static bool getStatus();
	static void addManager(const Manager& newMgr);
	static void removeEmployee(int ID);
	static bool printEmployee(bool all, int ID);
	~ManagerDB();
	//static int searchIndex(int ID);
};

struct ManagerController {
	Manager& getManager(int ManagerID)const;
	void addManager(Person& person, float salary);
	void addManager(const Manager& newManager);
	void deleteManager(int ID);
	void printManager(bool all = true, int ID = 0)const;
};


#endif
