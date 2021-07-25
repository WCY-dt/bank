/************************************************************************
 * Copyright (C) 2021 Chenyang https://wcy-dt.github.io                 *
 *                                                                      *
 * @file     economicclac.cpp                                           *
 * @brief    Economic calc is used as auxiliary for database and server.*
 *           it can calculate the interest.                             *
 * @author   Chenyang                                                   *
 * @date     2021 - 07                                                  *
 ************************************************************************/

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
    int iType; /// type

    /**
     * @note the struct of Flow is like a chain.
     *       when we deposit, the chain adds,
     *       when we withdraw, the chain minus.
     */
    struct Flow
    {
        double dMoney; /// money change
                       /// -# +:deposit
                       /// -# -:withdraw
        time_t tTime;  /// time of operation
    };
    double dMoney; /// money till some point of time
    vector<Flow> vFlow;
};

#endif // ECONOMICCALC_H
