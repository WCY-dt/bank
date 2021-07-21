#ifndef ECONOMICCALC_H
#define ECONOMICCALC_H

#include<time.h>
#include<vector>
#include "bankdb.h"


class economiccalc
{
public:
    economiccalc();
    void SetType(int);
    void Add(double,time_t);
    void Sub(double,time_t);
    double Query(time_t);
    double QueryPrepare(time_t);
private:
    int iType;
    struct Flow{
        double dMoney;
        time_t tTime;
    };
    double dMoney;
    vector<Flow> vFlow;
};

#endif // ECONOMICCALC_H
