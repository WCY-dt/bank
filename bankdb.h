#ifndef BANKDB_H
#define BANKDB_H

#include<string>
#include<vector>
#include<map>

using namespace std;

class bankdb
{
public:
    bankdb();
    void GetFile();
    void WriteFile();

    void AddAccount(string,string,string,string,int,double,string);

    void EditAccount(string,string,string,int,double);
    void EditPasswd(string,string);
    void SetLost(string,time_t);

    bool ExistAccount(string);
    bool CheckAccount(string,string);

    string GetName(string);
    string GetAddress(string);
    int GetType(string);
    double GetInterest(string);
    bool GetLost(string);
    time_t GetLostTime(string);
    string GetOperator(string);

    string GetNumber(int);
    string GetName(int);
    string GetAddress(int);
    int GetType(int);
    double GetInterest(int);
    bool GetLost(int);
    time_t GetLostTime(int);
    string GetOperator(int);

    int GetNumberOfAccounts();
    int GetNumberOfFlows(string);

    time_t GetTime(string,int);
    double GetMoney(string,int);
    int GetOperationType(string,int);
    string GetOperator(string,int);

    void DepositMoney(string,time_t,double,string);
    bool WithdrawMoney(string,time_t,double,string);


private:
    struct flowInfo{
        time_t tTime;
        double dMoney;
        int iOperationType;
        string strOperator;
    };

    struct accountInfo{
        string strNumber;
        string strName;
        string strPasswd;
        string strAddress;
        int iType;
        double dInterest;
        bool bLost;
        time_t tLostTime;
        string strOperator;
        vector<flowInfo> vFlow;
    };

    vector<accountInfo> vAccount;

    map<string,int> mAccount;

    map<string,double> mMoney;
};

#endif // BANKDB_H
