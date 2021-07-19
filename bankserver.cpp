#include "bankserver.h"
#include "bankdb.h"
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
