#include <iomanip>
/*---------------*/
#include "./../include/phone.h"
/*---------------*/

using namespace std;

void checkStringLength(size_t l);



Call::Call(SIM &sim) : sim(&sim) {}


string Call::getContactNumber()const {
	return sim->getNumber();
}


ostream& operator<<(ostream& os, const Call& obj) {
	os << "|Contact_Num: " << obj.getContactNumber();
	checkStringLength(obj.getContactNumber().length() + 14);
	os << "|Call_Price: " << obj.sim->getTariff().getCallPrice() << "$";
	checkStringLength(to_string(obj.sim->getTariff().getCallPrice()).length() + 7);

	return os;
}


//////////////////////////////////////


////////////////////////////////////////////

bool CallHistory::getStatus()const {
	return status;
}

Call& CallHistory::getCall(int index)const {
	return call[index];
}

void CallHistory::addCall(const Call& newSIM) {
	Call* temp = new Call[arrsize + 1];
	for (int i = 0; i < arrsize; i++) {
		temp[i] = call[i];
	}
	temp[arrsize] = newSIM;
	delete[] call;
	call = temp;
	arrsize++;
	status = true;
}


void CallHistory::printCalls(bool all, int ID)const {
	if (all) {
		for (int i = 0; i < arrsize; i++) {
			cout << "|ID: " << i + 1 << setw(52 - /*(to_string((i + 1)).length() + 5))*/ 6) << "|" << endl;
			cout << call[i];
			cout << "|--------------------------------------------------|" << endl;
		}
	}
	else {
		cout << "|ID: " << ID << setw(52 - (to_string(ID).length() + 4)) << "|" << endl;
		cout << call[ID];
	}
}

CallHistory::~CallHistory() {
	if (call != nullptr) {
		delete[] call;
	}
	call = nullptr;
}
