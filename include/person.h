#ifndef PERSON_H
#define PERSON_H
#include <string>

enum Gender { MALE = 0, FEMALE = 1 };

using std::string;

class Person {
private:
	string fname = "no info";
	string lname = "no info";
	string birthday = "no info";
	Gender gender = MALE;
public:
	Person() = default;
	Person(string, string, string, Gender);
	string getFirstName()const;
	string getLastName()const;
	string getDate()const;
	Gender getGender()const;
	void setF_Name(string);
	friend bool operator==(const Person&, const Person&);
	friend bool operator!=(const Person&, const Person&);
};


#endif
