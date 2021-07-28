/************************************************************************
 * Copyright (C) 2021 Chenyang https://wcy-dt.github.io                 *
 *                                                                      *
 * @file     bankserver.h                                               *
 * @brief    Bankserver is a layer upon bankdb and beneath ui layer.    *
 *           it is designed for muti-users. however,                    *
 *           i do not have enough time complete it.                     *
 * @author   Chenyang                                                   *
 * @date     2021 - 07                                                  *
 ************************************************************************/

#ifndef BANKSERVER_H
#define BANKSERVER_H

#include "bankdb.h"
#include <string>

using namespace std;

class bankServer
{
public:
    bankServer();

    /**
     * @defgroup account operations
     */
    bool AccountExist(string);
    bool AccountAdd(string, string, string, string, int, double, string);
    bool AccountEdit(string, string, int, double);
    bool PasswdEdit(string, string);
    bool Login(string, string);
    void ReportLost(time_t);
    void RidLost();

    /**
     * @defgroup deposit and withdraw money
     */
    void Deposit(double, string);
    bool Withdraw(double, string);

    /**
     * @defgroup get information of temporary account
     */
    string GetName();
    string GetAddress();
    int GetType();
    double GetInterest();
    bool GetLost();
    time_t GetLostTime();
    string GetOperator();

    /**
     * @defgroup get information by the index in vAccount
     */
    string GetNumber(int);
    string GetName(int);
    string GetAddress(int);
    int GetType(int);
    double GetInterest(int);
    bool GetLost(int);
    time_t GetLostTime(int);
    string GetOperator(int);

    /**
     * @defgroup get number
     */
    int GetNumberOfAccounts();
    int GetNumberOfFlows();

    time_t GetTime(int);
    double GetMoney(int);
    int GetOperationType(int);
    string GetFlowOperator(int);

    /**
     * @defgroup get information of the flow by index of the flow
     */
    double GetTotal();
    double GetPrepare(time_t);

    /**
     * @defgroup export the list
     */
    void ExportAccountFile(string);
    void ExportFlowFile(string);

private:
    bankdb db; /// as for we only have one server now, we can define a database here

    string strCurrentNumber; // the account login now
};

#endif // BANKSERVER_H
