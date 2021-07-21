#ifndef ECONOMICCALC_H
#define ECONOMICCALC_H

#include "bankdb.h"
#include <time.h>
#include <vector>

class economiccalc
{
public:
    economiccalc();
    void SetType(int);
    void Add(double, time_t);
    void Sub(double, time_t);
    double Query(time_t);
    double QueryPrepare(time_t);

private:
    int iType;
    struct Flow
    {
        double dMoney;
        time_t tTime;
    };
    double dMoney;
    vector<Flow> vFlow;
};

#endif // ECONOMICCALC_H
