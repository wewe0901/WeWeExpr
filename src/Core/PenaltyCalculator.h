/*
 * PenaltyCalculator.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef PENALTYCALCULATOR_H_
#define PENALTYCALCULATOR_H_

#include <vector>
#include <string>
namespace WeWeExpr {

class PenaltyCalculator {
public:
	PenaltyCalculator();
	virtual ~PenaltyCalculator();

	void setPenaltyFactor(double factor);
	double doCalculate(std::vector<int> &onlineTrace,std::vector<int> &demandTrace, std::vector<int> &resourceTrace);
private:
	double penaltyFactor;
};

}

#endif /* PENALTYCALCULATOR_H_ */
