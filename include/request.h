#ifndef REQUEST_H
#define REQUEST_H
/*---------------*/
#include "customer.h"
#include "tariff.h"
/*---------------*/


enum REQUEST_ACTION { DENIED = 0, ACCEPTED = 1 };


/*--------------request_details.cpp---------------*/

class RequestType {
private:
	string type = "Tariff Change";
public:
	const string getType()const;
	void setType(string);
};
//-----------------------------------------------//
class RequestStatus {
private:
	string status = "In Progress";
public:
	const string getStatus()const;
	void setStatus(const string);
};

/*----------------------------------------*/
////////////////////////////////////////////
/*-------------Request.cpp---------------*/

class Request {
private:
	RequestType reqType;
	RequestStatus reqStatus;
	Customer* reqSender = nullptr;
	Tariff* newTariff = nullptr;
	int reqID = 0;
	static int id;
public:
	Request(Customer&, Tariff&);
	Request() = default;
	Customer& getCustomer()const;
	Tariff& getNewTarif()const;
	RequestType getRequestType()const;
	RequestStatus getRequestStatus()const;
	int getReqId()const;
	void updateRequestStatus(string);
	Request& operator=(const Request&);
	friend ostream& operator<<(ostream& os, const Request& req);
};

/*----------------------------------------*/
////////////////////////////////////////////
/*--------------request_containers.cpp-----------------*/

class RequestInProgress {
private:
	static Request* inProgress;
	static int arrsize;
	static bool status;
public:
	Request& getRequest(int)const;
	static void addInProgressRequest(const Request&);
	static void manageRequest(const REQUEST_ACTION, const int);
	static bool printRequest(bool all = true, int id = 0);
	static int getSize();
	static bool getStatus();
  friend int searchIndex(int); 
	~RequestInProgress();
};

class RequestHistory {
private:
	static Request* reqHistory;
	static int arrsize;
	static bool status;
public:
	Request& getRequest(int)const;
	static void addRequestHistory(const Request&);
	static void printRequest(bool, int);
	static int getSize();
	~RequestHistory();
};

/*----------------------------------------*/
////////////////////////////////////////////
/*---------------request_manager.cpp----------------*/

struct RequestManager {
	void sendRequest(Customer&, Tariff&);
	bool getStatus()const;
	void manageRequest(const REQUEST_ACTION, const int)const;
	void printInProgressRequest(bool all = true, int id = 0)const;
	void printRequestHistory(bool all = true, int id = 0)const;
};

/*----------------------------------------*/

#endif
