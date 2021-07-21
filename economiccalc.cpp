#include "economiccalc.h"
#include <QDebug>

economiccalc::economiccalc()
{
    dMoney = 0;
    vFlow.clear();
}

void economiccalc::SetType(int iSetType)
{
    iType = iSetType;
}

void economiccalc::Add(double dMoney, time_t tTime)
{
    //qDebug()<<dMoney<<" "<<tTime;
    Flow tmpFlow;
    tmpFlow.tTime = tTime;
    tmpFlow.dMoney = dMoney;
    vFlow.push_back(tmpFlow);
    //qDebug()<<vFlow.size();
}

void economiccalc::Sub(double dMoney, time_t tTime)
{
    //qDebug()<<dMoney;
    double dMoneyNeeded = dMoney;
    int iTmpPos = vFlow.size() - 1;
    while (dMoneyNeeded > 0 && iTmpPos >= 0)
    {
        if (tTime < vFlow[iTmpPos].tTime)
        {
            iTmpPos--;
        }
        else if (vFlow[iTmpPos].dMoney > dMoneyNeeded)
        {
            //qDebug()<<"here";
            vFlow[iTmpPos].dMoney -= dMoneyNeeded;
            dMoneyNeeded = 0;
            iTmpPos--;
        }
        else
        {
            //qDebug()<<"there";
            dMoneyNeeded -= vFlow[iTmpPos].dMoney;
            vFlow[iTmpPos].dMoney = 0;
            iTmpPos--;
        }
    }
    //qDebug()<<vFlow.size();
}

double economiccalc::Query(time_t tTime)
{
    //qDebug()<<iType;
    //qDebug()<<vFlow.size();
    double dAns = 0;
    int iTmpTime;
    double dInterest;
    switch (iType)
    {
    case 0:
        iTmpTime = 31536000;
        dInterest = 1.98;
        break;
    case 1:
        iTmpTime = 94608000;
        dInterest = 2.25;
        break;
    case 2:
        iTmpTime = 157680000;
        dInterest = 3.5;
        break;
    }

    for (int i = 0; i < (int)vFlow.size(); i++)
    {
        int iYieldInterestYear = ((int)difftime(tTime, vFlow[i].tTime)) / iTmpTime;
        //qDebug()<<(int)difftime(tTime,vFlow[i].tTime);
        double dYieldInterest = vFlow[i].dMoney;
        for (int j = 1; j <= iYieldInterestYear; j++)
        {
            dYieldInterest = dYieldInterest * (1 + (dInterest / 100));
        }
        dAns += dYieldInterest;
    }
    return dAns;
}

double economiccalc::QueryPrepare(time_t tTime2)
{
    time_t tTime1 = time(nullptr);
    double dAns = 0;
    int iTmpTime;
    double dInterest;
    switch (iType)
    {
    case 0:
        iTmpTime = 31536000;
        dInterest = 1.98;
        break;
    case 1:
        iTmpTime = 94608000;
        dInterest = 2.25;
        break;
    case 2:
        iTmpTime = 157680000;
        dInterest = 3.5;
        break;
    }

    for (int i = 0; i < (int)vFlow.size(); i++)
    {
        int iDifftime1 = (int)difftime(tTime1, vFlow[i].tTime);
        int iDifftime2 = (int)difftime(tTime2, vFlow[i].tTime);
        if (((iDifftime1 / iTmpTime) + 1) * iTmpTime <= iDifftime2)
        {
            int iYieldInterestYear = iDifftime2 / iTmpTime;
            //qDebug()<<(int)difftime(tTime,vFlow[i].tTime);
            double dYieldInterest = vFlow[i].dMoney;
            for (int j = 1; j <= iYieldInterestYear; j++)
            {
                dYieldInterest = dYieldInterest * (1 + (dInterest / 100));
            }
            dAns += dYieldInterest;
        }
    }
    return dAns;
}
