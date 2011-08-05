/*
 * NullPredictionStrategy.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "NullPredictionStrategy.h"

namespace WeWeExpr {

NullPredictionStrategy::NullPredictionStrategy() {

	previousData=0;
	delayCount=0;
	delay=0;
}

NullPredictionStrategy::~NullPredictionStrategy() {

}
void NullPredictionStrategy::trainning(std::vector<int> data)
{
	//not
}
int NullPredictionStrategy::nextPrediction()
{
	if(delayCount >= delay){
		int data = this->delayData.front();
		this->delayData.pop();

		return data;
	}
	return previousData;
}

void NullPredictionStrategy::update(int data)
{

	this->delayData.push(data);
	delayCount++;

}
void NullPredictionStrategy::setDelay(int d)
{
	this->delay = d;
}
} /* namespace WeWeExperimental */
