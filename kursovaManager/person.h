#ifndef PERSON_H
#define PERSON_H
#include <string>

enum Gender { MALE = 0, FEMALE = 1 };

using std::string;

class Person {
private:
	string fname;
	string lname;
	string birthday;
	Gender gender;
public:
	Person();
	Person(string fname, string lname, string date, Gender gender);
	string getFirstName()const;
	string getLastName()const;
	string getDate()const;
	Gender getGender()const;
	void setF_Name(string newName);
	friend bool operator==(const Person& obj1, const Person& obj2);
	friend bool operator!=(const Person& obj1, const Person& obj2);
};


#endif
