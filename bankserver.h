#ifndef BANKSERVER_H
#define BANKSERVER_H

#include<string>
#include "bankdb.h"

using namespace std;

class bankServer
{
public:
    bankServer();
    bool AccountExist(string);

    bool AccountAdd(string,string,string,string,int,double,string);
    bool AccountEdit(string,string,int,double);
    bool PasswdEdit(string,string);

    bool Login(string, string);

    void ReportLost(time_t);

    void Deposit(double,string);
    bool Withdraw(double,string);

    string GetName();
    string GetAddress();
    int GetType();
    double GetInterest();
    bool GetLost();
    time_t GetLostTime();
    string GetOperator();

private:
    bankdb db;
    string strCurrentNumber;
};

#endif // BANKSERVER_H
