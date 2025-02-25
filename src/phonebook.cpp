#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
/*---------------*/
#include "./../include/phone.h"
/*---------------*/

using namespace std;

void checkStringLength(size_t l);

Phonebook::Phonebook(){}

int Phonebook::getSize()const {
	return arrsize;
}

SIM& Phonebook::getContact(int index) const{
	return sim[index - 1];
}

void Phonebook::addContact(const SIM& newSIM) {
	SIM* temp = new SIM[arrsize + 1];
	if (sim) {
		for (int i = 0; i < arrsize; i++) {
			temp[i] = sim[i];
		}
		delete[] sim;
	}
	temp[arrsize] = newSIM;
	sim = temp;
	arrsize++;
}


void Phonebook::deleteContact(int index) {
	index--;
	if (index < 0||index>arrsize) return;
	SIM* temp = new SIM[arrsize - 1];
	for (int i = 0,j = 0; i < arrsize; i++) {
		if (i != index) {
			temp[j] = sim[i];
			j++;
		}
	}
	delete[] sim;
	sim = temp;
	arrsize--;
}

void Phonebook::printContacts()const {
	for (int i = 0; i < arrsize; i++) {
		cout << "|ID:" << i + 1;
		checkStringLength(to_string(i + 1).length() + 4);
		cout << "|P_num:" << sim[i].getNumber();
		checkStringLength(sim[i].getNumber().length()+7);
		cout << "|--------------------------------------------------|" << endl;
	}
}

Phonebook::~Phonebook(){
	delete[] sim;
}
