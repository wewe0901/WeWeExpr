/*
 * ReverseArrangementsTest.h
 *
 *  Created on: 2011/7/26
 *      Author: wewe0901
 */

#ifndef REVERSEARRANGEMENTSTEST_H_
#define REVERSEARRANGEMENTSTEST_H_

#include "IStationaryTest.h"

namespace WeWeExpr {

class ReverseArrangementsTest: public IStationaryTest {
public:
	ReverseArrangementsTest();
	virtual ~ReverseArrangementsTest();
	virtual bool test(std::vector<int> & data);
	virtual void setPercentile(double p){percentile = p;};
private:
	double percentile;
};

}

#endif /* REVERSEARRANGEMENTSTEST_H_ */
