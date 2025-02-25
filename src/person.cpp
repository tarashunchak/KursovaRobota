/*---------------*/
#include "./../include/person.h"
/*---------------*/

using namespace std;

Person::Person(string fname, string lname, string date, Gender gender) :fname(fname), lname(lname), birthday(date), gender(gender) {}

Person::Person()
	: fname("no info"), lname("no info"), birthday("no info"), gender(MALE) {}

string Person::getFirstName()const {
	return fname;
}

string Person::getLastName()const {
	return lname;
}

string Person::getDate()const {
	return birthday;
}

Gender Person::getGender()const {
	return gender;
}

void Person::setF_Name(string newName) {
	fname = newName;
}

bool operator==(const Person& obj1, const Person& obj2) {
	return obj1.fname == obj2.fname &&
		obj1.lname == obj2.lname &&
		obj1.birthday == obj2.birthday &&
		obj1.gender == obj2.gender;
}

bool operator!=(const Person& obj1, const Person& obj2) {
	return !(obj1 == obj2);
}

