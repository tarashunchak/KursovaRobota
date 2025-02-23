#include <iomanip>
#include <string>
#include <iostream>
/*---------------*/
#include "./../include/chat.h"
/*---------------*/

using namespace std;

////////////ChatDB////////////

bool ChatDB::getStatus() const {
    return status;
}

int ChatDB::getSize() const {
    return arrsize;
}

Chat& ChatDB::getChat(int index) const {
    return chat[index];
}

void ChatDB::startChat(const Chat& newChat) {
    bool not_exist = true;
    for (int i = 0; i < arrsize; i++) {
        if (!(newChat != chat[i])) {
            not_exist = false;
            break;
        }
    }
    if (not_exist) {
        Chat* temp = new Chat[arrsize + 1];
        for (int i = 0; i < arrsize; i++) {
            temp[i] = chat[i];
        }
        temp[arrsize] = newChat;
        delete[] chat;
        chat = temp;
        arrsize++;
        status = true;
    }
}

void ChatDB::removeChat(int index) {
    Chat* temp = new Chat[arrsize - 1];
    for (int i = 0, j = 0; i < arrsize; i++) {
        if (i != index) {
            temp[j] = chat[i];
            j++;
        }
    }
    delete[] chat;
    chat = temp;
    arrsize--;
}

void ChatDB::printChats()const {
    for (int i = 0; i < arrsize; i++) {
        if (chat[i].getStatus() == true) {
            cout << chat[i];
        }
    }
}

void ChatDB::printMassages(int index)const {
    for (int i = 0; i < chat[index].getSize(); i++) {
        cout << chat[index].getMassage(i);
    }
}

ChatDB::~ChatDB() {
    delete[] chat;
}

//////////////////////////////
