/*---------------*/
#include "./../include/manager.h"
/*---------------*/

using namespace std;

void ManagerController::addManager(Person& person, float salary) {
	ManagerDB::addManager(Manager(person, salary));
}

void ManagerController::addManager(const Manager& newManager) {
	ManagerDB::addManager(newManager);
}

void ManagerController::deleteManager(int ID) {
	ManagerDB::removeEmployee(ID);
}

void ManagerController::printManager(bool all, string ID)const {
  //ID.erase(0, 1);
	//ManagerDB::printEmployee(all, stoi(ID));
}

Manager& ManagerController::getManager(int ManagerID)const {
	return *ManagerDB::getManager(ManagerID);
}
