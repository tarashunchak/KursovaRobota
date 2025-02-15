#include "ConsoleUI.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
/*---------------*/
#include "all_headers.h"
/*---------------*/

using namespace std;

///////////////////////////////////

/*/////////////////////////////////*/string UserID;///////////////////////////////////

///////////////////////////////////
Person person[3]{
    Person("Taras", "Hunchak", "20.04.2007", MALE),
    Person("Joe", "Biden","10.03.2001",MALE),
    Person("Ilona" ,"Musk","11.09.2001",FEMALE)
};

Person cust[3]{
    Person("Olga", "Ivanova", "15.06.1995", FEMALE),
    Person("John", "Smith", "22.08.1988", MALE),
    Person("Emily", "Davis", "05.02.1992", FEMALE)
};

Customer customers[3]{
    Customer(cust[0], SIM("+380991234567", Balance(100))),
    Customer(cust[1], SIM("+380996543210", Balance(240))),
    Customer(cust[2], SIM("+380993456789", Balance(400)))
};

Tariff tariff[3]{
    Tariff("JoicePro",1500,265),
    Tariff("SuperNet",2500,463),
    Tariff("Standart",2000,300)
};

SIM sim[4]{
    SIM("+380992210001", Balance(200)),
    SIM("+380654321023", Balance(250)),
    SIM("+380604556645", Balance(120)),
    SIM("+380933344553", Balance(493))
};

//////////////////////////////

void PrintMenu(string);

string LogInFunc();

string AuthFunc(string, string);

void moveLeft(int);

void printEmptyMenu();

void checkStringLength(size_t);

//////////////////////////////


void ConsoleUI::run()const {

    ///////////////////////
    /*Dlya customera*/Tariff myTarif("GigaChad", 10000, 300);
    Balance b(500000);
    SIM mySim("+380990000000", b, myTarif);/**/
    SIM sim2("+380990879320", b, tariff[0]);
    Phonebook myPb;
    ///////////////////////

    /**/Mobile mobile(mySim, myPb);/*Dlya customera*/

    /*Managers-----*/
    ChatManager chatManager;
    RequestManager requestManager;
    ManagerController managerController; //(class manager classa Manager)
    TariffManager tariffManager;
    CustomerManager customerManager;
    MobileManager myPhone(mobile);
    /*-----Managers*/
    Mobile mmm(sim2, myPb);
    MobileManager ppp(mmm);

    Customer meCust(person[0], myPhone, "taras", "ass");
    Customer meCust2(person[1], ppp, "newme", "pass");
    for (int i = 0; i < 4; i++) {
        myPhone.addContact(sim[i]);
    }

    customerManager.addCustomer(meCust);
    customerManager.addCustomer(meCust2);
    for (int i = 0; i < 3; i++) {
        tariffManager.addTariff(tariff[i]);
        customerManager.addCustomer(customers[i]);
        managerController.addManager(person[i], 2000.0);
    }

    Manager meManager(person[1], "manager", "qwerty", 1000.00f);
    Admin admin(person[2], "admin", "pass", 2000.04f);
    AdminManager a(admin);

    managerController.addManager(meManager);
    ofstream reportout("RequestHistory.txt");

    requestManager.sendRequest(meCust, tariffManager.getTariff(1));
    requestManager.sendRequest(meCust, tariffManager.getTariff(2));
    requestManager.sendRequest(meCust, tariffManager.getTariff(3));


    bool mainmenu = false;

    do {
        string role;
        int menu = 0, inputint = 0;

        /*LogIn*/ {
            string temp = LogInFunc();
            if (temp == "error")
                return;
            else {
                role = temp;
                mainmenu = true;
                menu = 1;
            }
        }/*LogIn*/

        do {
            system("cls");
            PrintMenu(role);
            if (role == meCust.role/*Customer*/) {
                cin >> menu;
                system("cls");
                switch (menu) {
                case 1: {

                    /*0*/reload_myprofile:

                    system("cls");
                    int choice;
                    cout << " __________________________________________________\n"
                        << "|" << setw(20) << "" << "My Profile" << setw(22) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    customerManager.printCustomers(false, UserID);
                    cout << "|--------------------------------------------------|\n"
                        << "|1)Change tarif" << setw(38) << "|\n"
                        << "|0)Exit" << setw(46) << "|\n"
                        << "|Enter option>>____________________________________|";
                    moveLeft(36);
                    cin >> inputint;
                    if (inputint == 0)
                        break;

                    else if (inputint == 1) {
                        system("cls");
                        cout << " __________________________________________________\n"
                            << "|" << setw(20) << "" << "Tariffs" << setw(25) << "|\n"
                            << "|--------------------------------------------------|" << endl;
                        tariffManager.printTariff();
                        cout << "|Enter ID:_________________________________________|";
                        moveLeft(42);
                        cin >> choice;

                        if (choice > tariffManager.getSize() || choice == 0) break;

                        requestManager.sendRequest(customerManager.getCustomer(UserID), tariffManager.getTariff(choice));
                    }

                    /*0*/goto reload_myprofile;

                }
                case 2: {
                    system("cls");
                    cout << " __________________________________________________\n"
                        << "|" << setw(20) << "" << "My Balance" << setw(23) << " | \n"
                        << "|--------------------------------------------------|" << endl;
                    cout << "|Balance:" << customerManager.getMobile(UserID).getBalanceValue() << "$";
                    checkStringLength(to_string(customerManager.getMobile(UserID).getBalanceValue()).length() + 3);
                    cin >> inputint;
                    break;
                }
                case 3: {

                    /*1*/reload_phonebook:

                    system("cls");
                    int contact_id;
                    cout << " __________________________________________________\n"
                        << "|" << setw(20) << "" << "Phonebook" << setw(23) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    customerManager.getMobile(UserID).printContacts();
                    cout << "|1)Add contact" << setw(39) << "|\n"
                        << "|2)Remove contact" << setw(36) << "|\n"
                        << "|3)Make a call" << setw(39) << "|\n"
                        << "|0)Exit" << setw(45) << "|" << endl;
                    cout << "|>>" << setw(49) << "|";
                    moveLeft(49);
                    cin >> inputint;
                    if (inputint == 0) {
                        break;
                    }
                    cout << "|--------------------------------------------------|" << endl;
                    switch (inputint) {
                    case 1: {
                        string pnumb;
                        cout << "|Enter contact num:" << setw(33) << "|" << endl;
                        cout << "|+380_________" << setw(38) << "|";
                        moveLeft(47);
                        cin >> pnumb;
                        customerManager.getMobile(UserID).addContact(SIM("+380" + pnumb, Balance(0)));

                        /*1*/goto reload_phonebook;

                    }
                    case 2: {
                        cout << "|Enter contact ID:" << setw(34) << "|";
                        moveLeft(34);
                        cin >> contact_id;
                        customerManager.getMobile(UserID).deleteContact(contact_id);

                        /*1*/goto reload_phonebook;

                    }
                    case 3: {
                        cout << "|Enter contact ID:" << setw(34) << "|";
                        moveLeft(34);
                        cin >> contact_id;
                        customerManager.getMobile(UserID).getMyPhone()->makeCall(contact_id);
                    }
                    default: {
                        break;
                    }

                    }
                    break;
                }
                case 4: {
                    cout << " __________________________________________________\n"
                        << "|" << setw(20) << "" << "Call History" << setw(21) << " | \n"
                        << "|--------------------------------------------------|" << endl;
                    if (!customerManager.getMobile(UserID).getMyPhone()->getCallHistoryStatus()) {
                        printEmptyMenu();
                    }
                    else {
                        customerManager.getMobile(UserID).getMyPhone()->printCalls();
                    }
                    cout << "|__________________________________________________|" << endl;
                    system("pause");
                    break;
                }
                case 5: {
                    string massages = "";
                    chatManager.startChat(customerManager.getCustomer(UserID).getPerson(), managerController.getManager(1).getPerson());
                    cout << " __________________________________________________\n"
                        << "|" << setw(15) << "" << "Chats" << setw(15) << " | \n"
                        << "|--------------------------------------------------|" << endl;
                    chatManager.printChats();
                    /*cout << "|" << chatManager.getSize() + 1 << ")Start chat" << setw(20) << "|\n"
                        << "|" << chatManager.getSize() + 2 << ")Delete chat" << setw(19) << "|\n"*/
                    cout << "|0)Exit" << setw(46) << "|\n"
                        << "|Enter ID:" << setw(42) << "|";
                    moveLeft(42);
                    cin >> inputint;
                    /**/
                    if (inputint == 0)
                        break;
                    /**/
                    if (inputint <= 2 && inputint >= 0) {

                        /*2*/reload_massage:

                    system("cls");
                    cout << " __________________________________________________\n"
                        << "|\t         Massages" << setw(18) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    //chatManager.printMassages(inputint - 1);
                    cout << "|1)Send massage" << setw(28) << "|\n"
                        << "|0)Exit" << setw(36) << "|\n"
                        << "|Enter:____________________________________________|";
                    moveLeft(45);
                    cin >> inputint;
                    if (inputint == 0) break;
                    else if (inputint == 1) {
                        cout << "Massage:";
                        cin.ignore();
                        getline(cin, massages);

                        //chatManager.sendMassage(Massage(meCust.getPerson().getF_Name(), massages, managerController));

                        /*2*/goto reload_massage;

                    }
                    else {
                        cout << "Wrong option!" << endl;
                        system("pause");
                    }
                    }
                    /*else if (inputint == chatManager.getSize() + 1) {

                    }
                    else if (inputint == chatManager.getSize() + 2) {
                        cin >> inputint;
                        chatManager.removeChat(inputint - 1);
                    }*/

                    break;
                }
                }
            }
            else if (role == "Manager"/*Manager*/) {
                cin >> menu;
                system("cls");
                int request_id = 0;
                switch (menu) {
                case 1: {
                    cout << " __________________________________________________\n"
                        << "|" << setw(20) << "" << "My Profile" << setw(22) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    //managerController.printManager(false, UserID);
                    cout << "|--------------------------------------------------|\n"
                        << "|0)Exit" << setw(46) << "|\n"
                        << "|__________________________________________________|\n"
                        << ">>";
                    cin >> inputint;
                    break;
                }
                case 2: {
                    /*2*/reload_customer:
                    system("cls");
                    cout << " __________________________________________________\n"
                        << "|" << setw(20) << "" << "Subscribers" << setw(22) << " | \n"
                        << "|--------------------------------------------------|" << endl;
                    customerManager.printCustomers();
                    cout << "|--------------------------------------------------|\n"
                        << "|1)Add Sub" << setw(43) << "|\n"
                        << "|2)Remove Sub" << setw(40) << "|\n"
                        << "|0)Exit" << setw(46) << "|\n"
                        << "|__________________________________________________|\n"
                        << ">>";
                    cin >> inputint;
                    if (inputint == 0) break;
                    else if (inputint == 2) {

                        cout << "|Enter ID:" << setw(42) << "|";
                        moveLeft(42);
                        cin >> inputint;
                        customerManager.deleteCustomer(inputint);
                        /*2*/goto reload_customer;
                    }
                    else if (inputint == 1) {
                        system("cls");
                        string fname, lname, dateofB, phonenum;
                        bool gender;
                        cout << " __________________________________________________\n"
                            << "|" << setw(18) << "" << "Add Subscriber" << setw(19) << "|" << endl;
                        cout << "|--------------------------------------------------|" << endl;
                        cin.ignore();
                        cout << "|Name:" << setw(46) << "|";
                        moveLeft(46);
                        cin >> fname;
                        cout << "|LastName:" << setw(42) << "|";
                        moveLeft(42);
                        cin >> lname;
                        cout << "|Date_of_b:" << setw(41) << "|";
                        moveLeft(41);
                        cin >> dateofB;
                        cout << "|Gender(0-m/1-f):" << setw(35) << "|";
                        moveLeft(35);
                        cin >> gender;
                        cout << "|Phone:" << setw(45) << "|";
                        moveLeft(45);
                        cin >> phonenum;
                        Person p(fname, lname, dateofB, (Gender)gender);
                        SIM s(phonenum, Balance(0));
                        Customer c(p, s);
                        customerManager.addCustomer(c);
                    }
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
                    /*3*/reload_requests:
                    system("cls");
                    cout << " __________________________________________________\n"
                        << "|" << setw(16) << "" << "Incoming requests" << setw(19) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    if (!RequestInProgress::getStatus()) {
                        printEmptyMenu();
                    }
                    else {
                        requestManager.printInProgressRequest(true, 0);
                    }
                    cout << "|--------------------------------------------------|\n"
                        << "|0)Exit" << setw(46) << "|\n";
                    cout << "|Enter ID:" << setw(42) << "|";
                    moveLeft(42);
                    cin >> request_id;

                    if (request_id == 0) break;

                    else {
                        int choice;
                        system("cls");
                        cout << " __________________________________________________\n"
                            << "|" << setw(16) << "" << "Incoming requests" << setw(19) << "|\n"
                            << "|--------------------------------------------------|" << endl;

                        cout << "|Action (1-accept/0-reject):" << setw(24) << "|";
                        moveLeft(24);
                        cin >> choice;
                        if (choice > 1 || choice < 0) {
                            cout << "|__________________________________________________|\n";
                            cout << "\t\t\t  Wrong option!" << endl;
                            system("pause");

                            /*3*/goto reload_requests;
                        }

                        requestManager.manageRequest((REQUEST_ACTION)choice, request_id);
                    }
                    /*3*/goto reload_requests;
                }
                case 5: {
                    break;
                }
                case 6: {

                    break;
                }
                case 7: {
                    break;
                }
                }
            }
            else if (role == "Admin"/*Admin*/) {
                cin >> menu;
                system("cls");
                switch (menu) {
                case 1: {
                    cout << " __________________________________________________\n"
                        << "|" << setw(20) << "" << "My Account" << setw(22) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    AdminManager::printAdmin();
                    cout << "|__________________________________________________|\n";
                    system("pause");
                    break;
                }
                case 2: {
                    /**/reload_tariffs:
                    system("cls");
                    cout << " __________________________________________________\n"
                        << "|" << setw(21) << "" << "Tariffs" << setw(24) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    if (!TariffDB::getStatus()) {
                        printEmptyMenu();
                    }
                    else {
                        tariffManager.printTariff();
                    }
                    cout << "|--------------------------------------------------|" << endl
                        << "|1)Add Tariff" << setw(40) << "|\n"
                        << "|2)Remove Tariff" << setw(37) << "|\n"
                        << "|0)Exit" << setw(46) << "|\n"
                        << "|Enter option>>____________________________________|";
                    moveLeft(36);
                    cin >> inputint;
                    /**/
                    if (inputint == 0)
                        break;
                    /**/
                    switch (inputint) {
                    case 1: {
                        system("cls");
                        string name = "";
                        float price = 0.0f, callprice = 0.0f;
                        cout << " __________________________________________________\n"
                            << "|" << setw(19) << "" << "Add Tariff" << setw(22) << "|" << endl;
                        cout << "|--------------------------------------------------|" << endl;
                        cin.ignore();
                        cout << "|Tariff_Name:" << setw(39) << "|";
                        moveLeft(39);
                        getline(cin, name);
                        cout << "|Monthly_Price:" << setw(37) << "|";
                        moveLeft(37);
                        cin >> price;
                        cout << "|Call_Price:" << setw(40) << "|";
                        moveLeft(40);
                        cin >> callprice;

                        tariffManager.addTariff(name, price, callprice);

                        /**/goto reload_tariffs;

                    }
                    case 2: {
                        cout << "Enter ID:";
                        cin >> inputint;
                        tariffManager.deleteTariff(inputint);

                        /**/goto reload_tariffs;

                    }
                    default: {
                        break;
                    }
                    }
                    break;

                }
                case 3: {

                    /*2*/reload_employee:

                    system("cls");
                    cout << " __________________________________________________\n"
                        << "|" << setw(21) << "" << "Employees" << setw(22) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    if (!ManagerDB::getStatus()) {
                        printEmptyMenu();
                    }
                    else {
                        managerController.printManager();
                    }
                    cout << "|--------------------------------------------------|" << endl
                        << "|1)Add Empl" << setw(42) << "|\n"
                        << "|2)Remove Empl" << setw(39) << "|\n"
                        << "|0)Exit" << setw(46) << "|\n"
                        << "|Enter option>>____________________________________|";
                    moveLeft(36);
                    cin >> inputint;
                    /**/
                    if (inputint == 0)
                        break;
                    /**/
                    switch (inputint) {
                    case 1: {
                        system("cls");
                        string fname, lname, dateofB;
                        bool gender;
                        float salary;
                        cout << " __________________________________________________\n"
                            << "|" << setw(18) << "" << "Add Employee" << setw(21) << "|" << endl;
                        cout << "|--------------------------------------------------|" << endl;
                        cin.ignore();
                        cout << "|Name:" << setw(46) << "|";
                        moveLeft(46);
                        cin >> fname;
                        cout << "|LastName:" << setw(42) << "|";
                        moveLeft(42);
                        cin >> lname;
                        cout << "|Date_of_b:" << setw(41) << "|";
                        moveLeft(41);
                        cin >> dateofB;
                        cout << "|Gender(0-m/1-f):" << setw(35) << "|";
                        moveLeft(35);
                        cin >> gender;
                        cout << "|Salary:" << setw(44) << "|";
                        moveLeft(44);
                        cin >> salary;
                        Person p(fname, lname, dateofB, (Gender)gender);
                        Manager m(p, salary);
                        managerController.addManager(m);

                        /*2*/goto reload_employee;

                    };
                    case 2: {
                        cout << "Enter ID:";
                        cin >> inputint;
                        managerController.deleteManager(inputint);

                        /*2*/goto reload_employee;

                    }
                    case 0: {

                    }
                    default: {

                    }
                    }
                    break;
                }
                case 4: {
                    string rep = "ReportHistory.txt";
                    cout << " __________________________________________________\n"
                        << "|" << setw(7) << "" << "Incoming reports" << setw(9) << "|\n"
                        << "|--------------------------------------------------|" << endl;
                    ifstream reportnin("RequestHistory.txt");
                    if (!reportnin.is_open()) break;
                    while (getline(reportnin, rep)) {
                        cout << rep << endl;
                    }
                    cout << "|--------------------------------------------------|" << endl
                        << "|0)Exit" << setw(26) << "|\n"
                        << "|__________________________________________________|\n"
                        << ">>";
                    cin >> inputint;
                }
                }
            }

        } while (menu != 0);

    } while (mainmenu);

    reportout.close();
    return;
}

/*-------------------------------------------------------*/
///////////////////////////////////////////////////////////
/*-------------------------------------------------------*/


void PrintMenu(string role)
{
    if (role == "Manager")
    {
        cout << " __________________________________________________\n"
            << "|" << setw(19) << "" << "Manager menu" << setw(21) << "|\n"
            << "|" << setw(16) << "" << "Select an option" << setw(20) << "|\n"
            << "|--------------------------------------------------|\n"
            << "|1)My Account" << setw(40) << "|\n"
            << "|2)Subscribers" << setw(39) << "|\n"
            << "|3)Payments" << setw(42) << "|\n"
            << "|4)Requests" << setw(42) << "|\n"
            << "|5)Statistics" << setw(40) << "|\n"
            << "|6)Send massage" << setw(38) << "|\n"
            << "|7)Send report to admin" << setw(30) << "|\n"
            << "|--------------------------------------------------|\n"
            << "|0)Exit" << setw(46) << "|\n"
            << "|__________________________________________________|\n"
            << ">>";
    }
    else if (role == "Admin")
    {
        cout << " __________________________________________________\n"
            << "|" << setw(20) << "" << "Admin menu" << setw(22) << "|\n"
            << "|" << setw(16) << "" << "Select an option" << setw(20) << "|\n"
            << "|--------------------------------------------------|\n"
            << "|1)My Account" << setw(40) << "|\n"
            << "|2)Tariffs" << setw(43) << "|\n"
            << "|3)Employers" << setw(41) << "|\n"
            << "|4)View manager reports" << setw(30) << "|\n"
            << "|--------------------------------------------------|\n"
            << "|0)Exit" << setw(46) << "|\n"
            << "|__________________________________________________|\n"
            << ">>";
    }
    else if (role == "Customer") {
        cout << " __________________________________________________\n"
            << "|" << setw(20) << "" << "User menu" << setw(23) << "|\n"
            << "|" << setw(16) << "" << "Select an option" << setw(20) << "|\n"
            << "|--------------------------------------------------|\n"
            << "|1)My Profile" << setw(40) << "|\n"
            << "|2)My Balance" << setw(40) << "|\n"
            << "|3)Phone book" << setw(40) << "|\n"
            << "|4)Calls history" << setw(37) << "|\n"
            << "|5)Send massage" << setw(38) << "|\n"
            << "|--------------------------------------------------|\n"
            << "|0)Exit" << setw(46) << "|\n"
            << "|__________________________________________________|\n"
            << ">>";
    }
    return;
}

void printEmptyMenu() {
    cout << "|--------------------------------------------------|\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "|" << setw(52) << "|\n";
    }
    cout << "|" << setw(16) << "" << "It's empty here..." << setw(19) << " | \n";
    for (int i = 0; i < 5; i++)
    {
        cout << "|" << setw(52) << "|\n";
    }
    cout << "|--------------------------------------------------|\n";
}

string LogInFunc() {
    while (1)
    {
        system("cls");
        string login = "", password = "";
        cout << ">\"quit\"- EXIT<\n\n\n\n\n\n\n\n\n"
            << setw(56) << "" << "LOG IN\n";
        cout << setw(43) << "" << " _______________________________\n"
            << setw(43) << "" << "(LogIn: " << setw(25) << ")";
        moveLeft(25);
        cin >> login;
        cout << setw(43) << "" << " -------------------------------\n";
        if (login == "quit") return "error";
        cout << setw(43) << "" << " _______________________________\n"
            << setw(43) << "" << "(Password: " << setw(22) << ")";
        moveLeft(23);
        cin >> password;
        cout << setw(43) << "" << " -------------------------------\n\n";
        if (password == "quit") return "error";
        ////
        if (login != "" || password != "") {
            if (Auth::checkAuth(login, password) != "") {
                UserID = Auth::getUserID();
                return Auth::checkAuth(login, password);
            }
        }
    }
    return "";
}

string AuthFunc(string login, string pass) {
    return "";
}

void moveLeft(int p)
{
    for (int i = 0; i < p; ++i)
    {
        cout << "\b";
    }
}

void checkStringLength(size_t l) {
    cout << "" << setw(52 - l) << "|" << endl;
}