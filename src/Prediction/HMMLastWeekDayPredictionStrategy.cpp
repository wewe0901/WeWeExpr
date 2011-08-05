/*
 * HMMLastWeekDayPredictionStrategy.cpp
 *
 *  Created on: 2011/7/19
 *      Author: wewe0901
 */

#include "HMMLastWeekDayPredictionStrategy.h"

namespace WeWeExpr {

HMMLastWeekDayPredictionStrategy::HMMLastWeekDayPredictionStrategy() {
	// TODO Auto-generated constructor stub

}

HMMLastWeekDayPredictionStrategy::~HMMLastWeekDayPredictionStrategy() {
	// TODO Auto-generated destructor stub
}
void HMMLastWeekDayPredictionStrategy::trainning(std::vector<int> data){}
int HMMLastWeekDayPredictionStrategy::nextPrediction(){return 1;}
void HMMLastWeekDayPredictionStrategy::update(int data){}
}
