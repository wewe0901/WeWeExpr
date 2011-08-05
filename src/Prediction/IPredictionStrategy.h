/*
 * IPredictionStretagy.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef IPREDICTIONSTRETAGY_H_
#define IPREDICTIONSTRETAGY_H_
#include <vector>
namespace WeWeExpr {

class IPredictionStrategy {
public:
	virtual void trainning(std::vector<int> data)=0;
	virtual int nextPrediction() = 0;
	virtual void update(int data) = 0;
};

} /* namespace WeWeExperimental */
#endif /* IPREDICTIONSTRETAGY_H_ */
