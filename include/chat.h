#ifndef CHAT_H
#define CHAT_H
/*---------------*/
#include "person.h"
/*---------------*/

using std::string;
using std::ostream;

class Massage {
private:
	string sender_name;
	string massage;
	string receiver_name;
public:
	Massage(string sender, string massages, string receiver);
	Massage();
	string getMassage()const;
	string getSender()const;
	string getReceiver()const;
	friend ostream& operator<<(ostream& os, const Massage& obj);
};

class Chat {
private:
	Person* person1 = nullptr;
	Person* person2 = nullptr;
	Massage* massages = nullptr;
	int arrsize = 0;
	bool status = false;
	static int ID;
	int chatID = 0;
public:
	Chat() = default;
	Chat(Person& person1, Person& person2);
	int getSize()const;
	bool getStatus()const;
	Massage& getMassage(int index = 0)const;
	Person& getPerson(bool index)const;
	void sendMassage(const Massage& newMassage);
	friend ostream& operator<<(ostream& os, const Chat& obj);;
	friend bool operator!=(const Chat& obj1, const Chat& obj2);
	~Chat();
};

class ChatDB {
private:
	Chat* chat = nullptr;
	int arrsize = 0;
	bool status = false;
public:
	bool getStatus()const;
	int getSize()const;
	void startChat(const Chat& newChat);
	Chat& getChat(int index = 0)const;
	void removeChat(int index);
	void printChats()const;
	void printMassages(int index = 0)const;
	~ChatDB();
};

class ChatManager {
private:
	ChatDB chatDB;
public:
	void startChat(Person& person1, Person& person2);
	void deleteChat(int ID);
	void sendMassage(const Massage& newMassage)const;
	void printChats()const;
	void printMassages(int index = 0)const;
};

#endif