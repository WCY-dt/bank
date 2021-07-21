#ifndef BANKSERVER_H
#define BANKSERVER_H

#include "bankdb.h"
#include <string>

using namespace std;

class bankServer
{
public:
    bankServer();
    bool AccountExist(string);

    bool AccountAdd(string, string, string, string, int, double, string);
    bool AccountEdit(string, string, int, double);
    bool PasswdEdit(string, string);

    bool Login(string, string);

    void ReportLost(time_t);

    void Deposit(double, string);
    bool Withdraw(double, string);

    string GetName();
    string GetAddress();
    int GetType();
    double GetInterest();
    bool GetLost();
    time_t GetLostTime();
    string GetOperator();

    string GetNumber(int);
    string GetName(int);
    string GetAddress(int);
    int GetType(int);
    double GetInterest(int);
    bool GetLost(int);
    time_t GetLostTime(int);
    string GetOperator(int);

    int GetNumberOfAccounts();
    int GetNumberOfFlows();

    time_t GetTime(int);
    double GetMoney(int);
    int GetOperationType(int);
    string GetFlowOperator(int);

    double GetTotal();
    double GetPrepare(time_t);

    void ExportAccountFile(string);
    void ExportFlowFile(string);

private:
    bankdb db;
    string strCurrentNumber;
};

#endif // BANKSERVER_H
