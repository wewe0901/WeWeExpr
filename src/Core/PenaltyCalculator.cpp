/*
 * PenaltyCalculator.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "PenaltyCalculator.h"
#include<iostream>
namespace WeWeExpr {

PenaltyCalculator::PenaltyCalculator() {
	penaltyFactor = 0.0;
}

PenaltyCalculator::~PenaltyCalculator() {
	// TODO Auto-generated destructor stub
}

    void PenaltyCalculator::setPenaltyFactor(double factor)
    {
		this->penaltyFactor = factor;
    }

    double PenaltyCalculator::doCalculate(std::vector<int> & onlineTrace,std::vector<int> & demandTrace, std::vector<int> & resourceTrace)
    {

		if(demandTrace.size() != resourceTrace.size()
				|| demandTrace.size() != onlineTrace.size())
			return 0.0;

		double cost = 0.0;

		for(int i = 0; i < demandTrace.size(); i ++ )
		{
			if(resourceTrace[i] < demandTrace[i])
				cost += penaltyFactor * onlineTrace[i];
		}

		return cost;

    }

}
