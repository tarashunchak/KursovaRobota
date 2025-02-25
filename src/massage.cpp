#include <iostream>
#include <iomanip>
/*---------------*/
#include "./../include/chat.h"
/*---------------*/

using namespace std;

///////////Massage////////////

Massage::Massage(string sender, string massages, string receiver)
	: sender_name(sender), massage(massages), receiver_name(receiver) {}

Massage::Massage() {}

string Massage::getMassage()const {
	return massage;
}

string Massage::getSender()const {
	return sender_name;
}

string Massage::getReceiver()const {
	return receiver_name;
}

ostream& operator<<(ostream& os, const Massage& obj) {
	os << "|Sender:" << obj.sender_name << setw(52 - (obj.sender_name.length() + 8)) << "|" << endl
	  << "|Massage:" << obj.massage << setw(52 - (obj.massage.length() + 9)) << "|" << endl
	<< "|Receiver:" << obj.receiver_name << setw(52 - (obj.receiver_name.length() + 10)) << "|" << endl
	<< "|----------------------------------------|" << endl;

	return os;
}

//////////////////////////////


