#include "bankdb.h"
#include <fstream>
#include <QMessageBox>
#include <QDialog>
#include <QDebug>
#include <map>
#include <time.h>

using namespace std;

bankdb::bankdb()
{
    GetFile();
    //qDebug()<<("创建数据库\n");
}

void bankdb::GetFile()
{
    //qDebug()<<("开始读取数据\n");
    vAccount.clear();
    mAccount.clear();
    mMoney.clear();

    int iNumberOfAccounts,iNumberOfFlow;
    ifstream iFile("E:\\code\\bank\\bankdb.db");

    iFile>>iNumberOfAccounts;
    qDebug()<<(QString::number(iNumberOfAccounts));
    for (int i=0;i<iNumberOfAccounts;i++)
    {
        accountInfo tmpAccount;
        iFile>>tmpAccount.strNumber
             >>tmpAccount.strName
             >>tmpAccount.strPasswd
             >>tmpAccount.strAddress
             >>tmpAccount.iType
             >>tmpAccount.dInterest
             >>tmpAccount.bLost
             >>tmpAccount.tLostTime
             >>tmpAccount.strOperator
             >>iNumberOfFlow;
        mMoney[tmpAccount.strNumber]=0;
        for (int j=0;j<iNumberOfFlow;j++)
        {
            flowInfo tmpFlow;
            iFile>>tmpFlow.tTime
                 >>tmpFlow.dMoney
                 >>tmpFlow.iOperationType
                 >>tmpFlow.strOperator;
            if (tmpFlow.iOperationType==0)
            {
                mMoney[tmpAccount.strNumber]+=tmpFlow.dMoney;
            }
            else
            {
                mMoney[tmpAccount.strNumber]-=tmpFlow.dMoney;
            }
            tmpAccount.vFlow.push_back(tmpFlow);
        }
        mAccount[tmpAccount.strNumber]=vAccount.size();
        vAccount.push_back(tmpAccount);
    }
    //qDebug()<<("数据读取完毕\n");
}

void bankdb::WriteFile()
{
    int iNumberOfAccounts=vAccount.size();
    ofstream oFile("E:\\code\\bank\\bankdb.db",ios::trunc);

    oFile<<iNumberOfAccounts<<"\n";
    for (int i=0;i<iNumberOfAccounts;i++)
    {
        accountInfo tmpAccount=vAccount[i];
        int iNumberOfFlow=tmpAccount.vFlow.size();
        oFile<<tmpAccount.strNumber<<"\n"
             <<tmpAccount.strName<<"\n"
             <<tmpAccount.strPasswd<<"\n"
             <<tmpAccount.strAddress<<"\n"
             <<tmpAccount.iType<<"\n"
             <<tmpAccount.dInterest<<"\n"
             <<tmpAccount.bLost<<"\n"
             <<tmpAccount.tLostTime<<"\n"
             <<tmpAccount.strOperator<<"\n"
             <<iNumberOfFlow<<"\n";
        for (int j=0;j<iNumberOfFlow;j++)
        {
            flowInfo tmpFlow=tmpAccount.vFlow[j];
            oFile<<tmpFlow.tTime<<"\n"
                 <<tmpFlow.dMoney<<"\n"
                 <<tmpFlow.iOperationType<<"\n"
                 <<tmpFlow.strOperator<<"\n";
        }
    }
}

void bankdb::AddAccount(string strNum, string strNam, string strPas, string strAdd, int iTyp, double dInt, string strOpe)
{
    accountInfo tmpAccountInfo;
    tmpAccountInfo.strNumber=strNum;
    tmpAccountInfo.strName=strNam;
    tmpAccountInfo.strPasswd=strPas;
    tmpAccountInfo.strAddress=strAdd;
    tmpAccountInfo.iType=iTyp;
    tmpAccountInfo.dInterest=dInt;
    tmpAccountInfo.bLost=false;
    tmpAccountInfo.tLostTime=time(nullptr);
    tmpAccountInfo.strOperator=strOpe;
    vAccount.push_back(tmpAccountInfo);
    vAccount[vAccount.size()-1].vFlow.clear();
    WriteFile();
    GetFile();
}

void bankdb::EditAccount(string strNum,string strNam, string strAdd, int iTyp, double dInt)
{
    vAccount[mAccount[strNum]].strName=strNam;
    vAccount[mAccount[strNum]].strAddress=strAdd;
    vAccount[mAccount[strNum]].iType=iTyp;
    vAccount[mAccount[strNum]].dInterest=dInt;
    WriteFile();
}

void bankdb::EditPasswd(string strNum, string strPas)
{
    vAccount[mAccount[strNum]].strPasswd=strPas;
    WriteFile();
}

void bankdb::SetLost(string strNum, time_t tTim)
{
    vAccount[mAccount[strNum]].bLost=true;
    vAccount[mAccount[strNum]].tLostTime=tTim;
    WriteFile();
}

bool bankdb::ExistAccount(string strNumber)
{
    //qDebug()<<("验证账号");
    //qDebug()<<(QString::fromStdString(strNumber));
    //qDebug()<<("0号账号");
    //qDebug()<<(QString::fromStdString(vAccount[0].strNumber));
    //qDebug()<<(QString::fromStdString(vAccount[0].strPasswd));
    map<string,int>::iterator iter;
    iter=mAccount.find(strNumber);
    return (iter!=mAccount.end());
}

bool bankdb::CheckAccount(string strNumber,string strPasswd)
{
    if (!ExistAccount(strNumber)) return false;
    //qDebug()<<(QString::fromStdString(vAccount[mAccount[strNumber]].strNumber));
    //qDebug()<<(QString::fromStdString(vAccount[mAccount[strNumber]].strPasswd));
    return (vAccount[mAccount[strNumber]].strPasswd==strPasswd);
}

string bankdb::GetName(string strNumber)
{
    return vAccount[mAccount[strNumber]].strName;
}

string bankdb::GetAddress(string strNumber)
{
    return vAccount[mAccount[strNumber]].strAddress;
}

int bankdb::GetType(string strNumber)
{
    return vAccount[mAccount[strNumber]].iType;
}

double bankdb::GetInterest(string strNumber)
{
    return vAccount[mAccount[strNumber]].dInterest;
}

bool bankdb::GetLost(string strNumber)
{
    return vAccount[mAccount[strNumber]].bLost;
}

time_t bankdb::GetLostTime(string strNumber)
{
    return vAccount[mAccount[strNumber]].tLostTime;
}

string bankdb::GetOperator(string strNumber)
{
    return vAccount[mAccount[strNumber]].strOperator;
}

void bankdb::DepositMoney(string strNumber, time_t tTim, double dMon, string strOpe)
{
    flowInfo tmpFlowInfo;
    tmpFlowInfo.tTime=tTim;
    tmpFlowInfo.dMoney=dMon;
    tmpFlowInfo.iOperationType=0;
    tmpFlowInfo.strOperator=strOpe;
    vAccount[mAccount[strNumber]].vFlow.push_back(tmpFlowInfo);
    mMoney[strNumber]+=dMon;
    WriteFile();
}

bool bankdb::WithdrawMoney(string strNumber, time_t tTim, double dMon, string strOpe)
{
    if (dMon>mMoney[strNumber])
    {
        return false;
    }
    flowInfo tmpFlowInfo;
    tmpFlowInfo.tTime=tTim;
    tmpFlowInfo.dMoney=dMon;
    tmpFlowInfo.iOperationType=1;
    tmpFlowInfo.strOperator=strOpe;
    vAccount[mAccount[strNumber]].vFlow.push_back(tmpFlowInfo);
    mMoney[strNumber]-=dMon;
    WriteFile();
    return true;
}
