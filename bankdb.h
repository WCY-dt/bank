/************************************************************************
 * Copyright (C) 2021 Chenyang https://wcy-dt.github.io                 *
 *                                                                      *
 * @file     bankdb.h                                                   *
 * @brief    Bankdb simulates a database for the project. The speed of  *
 *           this database is slow for that we must ensure the safety   *
 *           of every deal.                                             *
 * @author   Chenyang                                                   *
 * @date     2021 - 07                                                  *
 ************************************************************************/

#ifndef BANKDB_H
#define BANKDB_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class bankdb
{
public:
    bankdb();

    /**
     * @defgroup file operations
     */
    void GetFile();
    void WriteFile();

    /**
     * @defgroup account operations
     */
    void AddAccount(string, string, string, string, int, double, string);
    void EditAccount(string, string, string, int, double);
    void EditPasswd(string, string);
    void SetLost(string, time_t);
    void RidLost(string);
    bool ExistAccount(string);
    bool CheckAccount(string, string);

    /**
     * @defgroup get information by account number
     */
    string GetName(string);
    string GetAddress(string);
    int GetType(string);
    double GetInterest(string);
    bool GetLost(string);
    time_t GetLostTime(string);
    string GetOperator(string);

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
    int GetNumberOfFlows(string);

    /**
     * @defgroup get information of the flow by account number
     *           and index of the flow
     */
    time_t GetTime(string, int);
    double GetMoney(string, int);
    int GetOperationType(string, int);
    string GetOperator(string, int);

    /**
     * @defgroup deposit and withdraw money
     */
    void DepositMoney(string, time_t, double, string);
    bool WithdrawMoney(string, time_t, double, string);

private:
    /**
     * @brief This structure records the flow for every account. 
     */
    struct flowInfo
    {
        time_t tTime;       /// when the deal happens
        double dMoney;      /// how much money
        int iOperationType; /// the type of the operation,
                            /// -# 0:deposit
                            /// -# 1:withdraw
        string strOperator; /// the operator of the deal
    };

    /**
     * @brief This structure records the information of every accounts.
     */
    struct accountInfo
    {
        string strNumber;       /// account number, generated automatically
        string strName;         /// name of the account owner
        string strPasswd;       /// password of the account
        string strAddress;      /// address of the account owner
        int iType;              /// type of the account
                                /// -# 0:1 year
                                /// -# 1:3 year
                                /// -# 2:5 year
        double dInterest;       /// interest, set according to the type
        bool bLost;             /// lost or not
        time_t tLostTime;       /// if lost, this variable has some value
        string strOperator;     /// the operator who open the account
        vector<flowInfo> vFlow; /// flow of the account
    };

    vector<accountInfo> vAccount; /// use a vector to store all the account information

    map<string, int> mAccount; /// map account number to the index of the account in vAccount

    map<string, double> mMoney; /// map account number to how much money the account has
};

#endif /// BANKDB_H
