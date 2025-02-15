/*---------------*/
#include "manager.h"
#include "user.h"
/*---------------*/

using namespace std;

/////////////ManagerDB//////////////

//int ManagerDB::searchIndex(int ID) {
//	for (int i = 0; i < ManagerDB::arrsize; i++) {
//		if (ManagerDB::mgList[i]->getID() == ID) {
//			return i;
//		}
//	}
//	return -1;
//}


Manager** ManagerDB::mgList = nullptr;
int ManagerDB::arrsize = 0;
bool ManagerDB::status = false;


Manager* ManagerDB::getManager(int index) {
	return ManagerDB::mgList[index];
}

const int ManagerDB::getSize() {
	return ManagerDB::arrsize;
}

bool ManagerDB::getStatus() {
	return ManagerDB::status;
}

void ManagerDB::addManager(const Manager& newMgr) {
	Manager** temp = new Manager * [arrsize + 1];
	for (int i = 0; i < arrsize; i++) {
		temp[i] = mgList[i];
	}
	temp[arrsize] = new Manager(newMgr);
	delete[] mgList;
	mgList = temp;

	arrsize++;
	status = true;

}

void ManagerDB::removeEmployee(int ID) {
	Manager** temp = new Manager * [arrsize - 1];
	for (int i = 0, j = 0; i < arrsize; i++) {
		if (i != ID) {
			temp[j] = mgList[i];
			j++;
		}
	}
	delete[] mgList;
	mgList = temp;
	arrsize--;
	if (arrsize == 0) status = false;
}

bool ManagerDB::printEmployee(bool all, int UID) {
	if (all) {
		for (int i = 0; i < arrsize; i++) {
			if(mgList[i] != nullptr)
				cout << *mgList[i];
		}
		return true;
	}
	else {
		if ((UID) != -1) {
			cout << *mgList[UID];
			return true;
		}
	}
	return false;
}

ManagerDB::~ManagerDB() {
	delete[] mgList;
	mgList = nullptr;
}

/////////////ManagerDB//////////////