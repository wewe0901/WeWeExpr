/*
 * RunsTest.h
 *
 *  Created on: 2011/7/26
 *      Author: wewe0901
 */

#ifndef RUNSTEST_H_
#define RUNSTEST_H_

#include "IStationaryTest.h"

namespace WeWeExpr {

class RunsTest: public IStationaryTest {
public:
	RunsTest();
	virtual ~RunsTest();

	virtual void setPercentile(double p){percentile = p;}
	virtual bool test(std::vector<int> & data);
private:
        double percentile;
};

}

#endif /* RUNSTEST_H_ */
