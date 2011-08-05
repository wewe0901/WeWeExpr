/*
 * HMMPredictionStrategy.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef HMMPREDICTIONSTRATEGY_H_
#define HMMPREDICTIONSTRATEGY_H_

#include "IPredictionStrategy.h"
#include <cmath>
#include "HMMWrapper.h"

namespace WeWeExpr {

class HMMPredictionStrategy: public IPredictionStrategy {
public:
	HMMPredictionStrategy(int n ,int m);
	virtual ~HMMPredictionStrategy();
	virtual void trainning(std::vector<int> data);
	virtual int nextPrediction();
	virtual void update(int data);
private:
	HMMWrapper * hmm;
	int trainningMax;
	int seqCount;
	int shift;
};

} /* namespace WeWeExperimental */
#endif /* HMMPREDICTIONSTRATEGY_H_ */
