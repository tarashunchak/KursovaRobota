#ifndef AUTH_H
#define AUTH_H
/*---------------*/
#include "manager.h"
#include "customer.h"
#include "admin.h"
/*---------------*/

//////////////////////

class Auth {
private:
	static string ID;
public:
	static string checkAuth(const string password, const string login);
	static string getUserID();
};

#endif