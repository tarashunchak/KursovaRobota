/*---------------*/
#include "./../include/chat.h"
/*---------------*/

using namespace std;

void ChatManager::startChat(Person& person1, Person& person2) {
	chatDB.startChat(Chat(person1,person2));
}

void ChatManager::deleteChat(int ID) {
	chatDB.removeChat(ID);
}

void ChatManager::sendMassage(const Massage& newMassage)const {
	chatDB.getChat().sendMassage(newMassage);
}

void ChatManager::printChats()const {
	chatDB.printChats();
}

void ChatManager::printMassages(int index)const {
	chatDB.printMassages(index);
}
