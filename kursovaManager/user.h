#ifndef USER_H
#define USER_H
/*---------------*/
#include "customer.h"
#include "admin.h"
#include "manager.h"
/*---------------*/


/*--------------user.cpp---------------*/

class User {
private:
	const Admin* admin = nullptr;
	const Manager* manager = nullptr;
	const Customer* customer = nullptr;
	static int id;
	int UID;
public:
	User() = default;
	explicit User(const Admin* admin);
	explicit User(const Manager* manager);
	explicit User(const Customer* customer);
	string getPass()const;
	string getLogin()const;
	string getRole()const;
	int getUID()const;
	string getUIDs()const;
	string getID()const;
};


class UserDB {
private:
	static User** userList;
	static int arrsize;
	static bool status;
public:
	static User* getUser(int UID = 0, bool byIndex = false);
	//static User* getUser(const User&);
	static void addUser(const User& newUser);
	static void deleteUser(const User& delUser);
	static int getSize();
	static bool getStatus();
	friend int searchIndex(int UID);
	static string searchID(int UID);

};


//struct UserManager {
//	void addUser(const User& newUser);
//	void deleteUser(const User& delUser);
//};


#endif