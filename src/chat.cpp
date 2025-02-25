#include <iostream>
#include <iomanip>
/*---------------*/
#include "./../include/chat.h"
/*---------------*/

using namespace std;

int Chat::ID = 0;

Chat::Chat(Person& person1, Person& person2) : person1(&person1), person2(&person2) {
    ID++;
    chatID = ID;
}

Massage& Chat::getMassage(int index) const {
    return massages[index];
}

int Chat::getSize() const {
    return arrsize;
}

bool Chat::getStatus() const {
    return status;
}

Person& Chat::getPerson(bool index) const {
    if (index) return *person1;
    else return *person2;
}

void Chat::sendMassage(const Massage& newMass) {
    Massage* temp = new Massage[arrsize + 1];
    for (int i = 0; i < arrsize; i++) {
        temp[i] = massages[i];
    }
    delete[] massages;
    temp[arrsize] = newMass;
    massages = temp;
    arrsize++;
    status = true;
}

ostream& operator<<(ostream& os, const Chat& obj) {
    os << "|ID:" << obj.chatID << setw(52 - (std::to_string(obj.chatID).length() + 4)) << "|" << endl
        << "|" << obj.getMassage(0).getSender() << setw(52 - (obj.getMassage(0).getSender().length() + 1)) << "|" << endl
        << "|------------------------------|" << endl;

    return os;
}

Chat::~Chat() {
    delete[] massages;
}

bool operator!=(const Chat& obj1, const Chat& obj2) {
    return !(obj1.getPerson(0) == obj2.getPerson(0) && obj1.getPerson(1) == obj2.getPerson(1)) &&
        !(obj1.getPerson(0) == obj2.getPerson(1) && obj1.getPerson(1) == obj2.getPerson(0));
}

/////////////////////////////
