/*
 * HMMNewPredictionStrategy.h
 *
 *  Created on: 2011/7/19
 *      Author: wewe0901
 */

#ifndef HMMNEWPREDICTIONSTRATEGY_H_
#define HMMNEWPREDICTIONSTRATEGY_H_

#include "IPredictionStrategy.h"
#include "HMMWrapper.h"
#include <vector>

namespace WeWeExpr {

class HMMNewPredictionStrategy: public IPredictionStrategy {
public:
	HMMNewPredictionStrategy(int n, int windowSize);
	virtual ~HMMNewPredictionStrategy();

	virtual void trainning(std::vector<int> data);
	virtual int nextPrediction();
	virtual void update(int data);

private:
	HMMWrapper * hmm;
	int updateWindowSize;
	std::vector<int> updateWindow;
	int shift;
};

}

#endif /* HMMNEWPREDICTIONSTRATEGY_H_ */
