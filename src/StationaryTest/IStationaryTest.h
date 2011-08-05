/*
 * IStationaryTest.h
 *
 *  Created on: 2011/7/26
 *      Author: wewe0901
 */

#ifndef ISTATIONARYTEST_H_
#define ISTATIONARYTEST_H_
#include<vector>
namespace WeWeExpr {

class IStationaryTest {

    public:
        virtual bool test(std::vector<int> & data) = 0;
        virtual void setPercentile(double p)=0;
    };

}

#endif /* ISTATIONARYTEST_H_ */
