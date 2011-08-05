/*
 * HMMLastWeekDayPredictionStrategy.h
 *
 *  Created on: 2011/7/19
 *      Author: wewe0901
 */

#ifndef HMMLASTWEEKDAYPREDICTIONSTRATEGY_H_
#define HMMLASTWEEKDAYPREDICTIONSTRATEGY_H_

#include "IPredictionStrategy.h"

namespace WeWeExpr {

class HMMLastWeekDayPredictionStrategy: public IPredictionStrategy {
public:
	HMMLastWeekDayPredictionStrategy();
	virtual ~HMMLastWeekDayPredictionStrategy();
	virtual void trainning(std::vector<int> data);
	virtual int nextPrediction();
	virtual void update(int data);
};

}

#endif /* HMMLASTWEEKDAYPREDICTIONSTRATEGY_H_ */
