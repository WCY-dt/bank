#include "bankserver.h"
#include "bankdb.h"
#include "economiccalc.h"
#include <QDebug>

bankServer::bankServer()
{
    //qDebug()<<("服务器启动\n");
}

bool bankServer::AccountExist(string strNumber)
{
    return (db.ExistAccount(strNumber));
}

bool bankServer::AccountAdd(string strNum, string strNam, string strPas, string strAdd, int iTyp, double dInt, string strOpe)
{
    if (strNam!="" &&
        strPas!="" &&
        strAdd!="" &&
        strOpe!="")
    {
        db.AddAccount(strNum, strNam, strPas, strAdd, iTyp, dInt, strOpe);
        return true;
    }
    return false;
}

bool bankServer::AccountEdit(string strNam, string strAdd, int iTyp, double dInt)
{
    if (strNam!="" && strAdd!="")
    {
        db.EditAccount(strCurrentNumber, strNam, strAdd, iTyp, dInt);
        return true;
    }
    return false;
}

bool bankServer::PasswdEdit(string strOldPasswd, string strPasswd)
{
    if (!db.CheckAccount(strCurrentNumber,strOldPasswd))
    {
        return false;
    }
    db.EditPasswd(strCurrentNumber, strPasswd);
    return true;
}

bool bankServer::Login(string strNumber, string strPasswd)
{
    //qDebug()<<("查找账号\n");
    if(!db.CheckAccount(strNumber,strPasswd))
    {
        //qDebug()<<("未找到\n");
        return false;
    }
    strCurrentNumber=strNumber;
    //qDebug()<<("找到\n");
    return true;
}

void bankServer::ReportLost(time_t tTime)
{
    db.SetLost(strCurrentNumber,tTime);
}


void bankServer::Deposit(double dMoney,string strOpe)
{
    time_t tTime=time(NULL);
    db.DepositMoney(strCurrentNumber,tTime,dMoney,strOpe);
}

bool bankServer::Withdraw(double dMoney,string strOpe)
{
    time_t tTime=time(NULL);
    return db.WithdrawMoney(strCurrentNumber,tTime,dMoney,strOpe);
}

string bankServer::GetName()
{
    return db.GetName(strCurrentNumber);
}

string bankServer::GetAddress()
{
    return db.GetAddress(strCurrentNumber);
}

int bankServer::GetType()
{
    return db.GetType(strCurrentNumber);
}

double bankServer::GetInterest()
{
    return db.GetInterest(strCurrentNumber);
}

bool bankServer::GetLost()
{
    return db.GetLost(strCurrentNumber);
}

time_t bankServer::GetLostTime()
{
    return db.GetLostTime(strCurrentNumber);
}

string bankServer::GetOperator()
{
    return db.GetOperator(strCurrentNumber);
}

string bankServer::GetNumber(int iNum)
{
    return db.GetNumber(iNum);
}


string bankServer::GetName(int iNum)
{
    return db.GetName(iNum);
}

string bankServer::GetAddress(int iNum)
{
    return db.GetAddress(iNum);
}

int bankServer::GetType(int iNum)
{
    return db.GetType(iNum);
}

double bankServer::GetInterest(int iNum)
{
    return db.GetInterest(iNum);
}

bool bankServer::GetLost(int iNum)
{
    return db.GetLost(iNum);
}

time_t bankServer::GetLostTime(int iNum)
{
    return db.GetLostTime(iNum);
}

string bankServer::GetOperator(int iNum)
{
    return db.GetOperator(iNum);
}

int bankServer::GetNumberOfAccounts()
{
    return db.GetNumberOfAccounts();
}

int bankServer::GetNumberOfFlows()
{
    return db.GetNumberOfFlows(strCurrentNumber);
}

time_t bankServer::GetTime(int iFlow)
{
    return db.GetTime(strCurrentNumber,iFlow);
}

double bankServer::GetMoney(int iFlow)
{
    return db.GetMoney(strCurrentNumber,iFlow);
}

int bankServer::GetOperationType(int iFlow)
{
    return db.GetOperationType(strCurrentNumber,iFlow);
}

string bankServer::GetFlowOperator(int iFlow)
{
    return db.GetOperator(strCurrentNumber,iFlow);
}

double bankServer::GetTotal()
{
    economiccalc Ecocalc;
    Ecocalc.SetType(GetType());
    for (int i=0;i<GetNumberOfFlows();i++)
    {
        if (GetOperationType(i)==0)
        {
            Ecocalc.Add(GetMoney(i),GetTime(i));
        }
        else
        {
            Ecocalc.Sub(GetMoney(i),GetTime(i));
        }
    }
    return Ecocalc.Query(time(nullptr));
}

double bankServer::GetPrepare(time_t iDay)
{
    double dAns=0;

    time_t tTime1=time(nullptr);
    time_t tTime2=iDay;
    if (tTime1>=tTime2) return 0;
    //qDebug()<<tTime1;
    //qDebug()<<tTime2;

    for (int k=0;k<GetNumberOfAccounts();k++)
    {
        strCurrentNumber=GetNumber(k);
        economiccalc Ecocalc;
        Ecocalc.SetType(GetType());
        //qDebug()<<GetNumberOfFlows();
        for (int i=0;i<GetNumberOfFlows();i++)
        {
           if (GetOperationType(i)==0)
           {
              //qDebug()<<"存款了";
              //qDebug()<<GetMoney(i)<<" "<<GetTime(i);
              Ecocalc.Add(GetMoney(i),GetTime(i));
           }
           else
           {
              //qDebug()<<"取款了";
              Ecocalc.Sub(GetMoney(i),GetTime(i));
           }
        }

        //qDebug()<<Ecocalc.Query(tTime1);
        //qDebug()<<Ecocalc.Query(tTime2);

        dAns+=(Ecocalc.QueryPrepare(tTime2));
    }
    return dAns;
}

