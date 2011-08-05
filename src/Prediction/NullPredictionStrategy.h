/*
 * NullPredictionStrategy.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef NULLPREDICTIONSTRATEGY_H_
#define NULLPREDICTIONSTRATEGY_H_

#include "IPredictionStrategy.h"
#include <queue>

namespace WeWeExpr {

class NullPredictionStrategy: public IPredictionStrategy {
public:
	NullPredictionStrategy();
	virtual ~NullPredictionStrategy();
	virtual void trainning(std::vector<int> data);
	virtual int nextPrediction() ;
	virtual void update(int data);
	void setDelay(int d);
private:
	int previousData;
	std::queue<int> delayData;
	int delay;
	int delayCount;
};

} /* namespace WeWeExperimental */
#endif /* NULLPREDICTIONSTRATEGY_H_ */
