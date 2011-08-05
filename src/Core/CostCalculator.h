/*
 * CostCalculator.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef COSTCALCULATOR_H_
#define COSTCALCULATOR_H_

#include <vector>

namespace WeWeExpr {

class CostCalculator {
public:
	CostCalculator();
	virtual ~CostCalculator();


	void setCostReservedAmortized(double price);
	void setCostReservedUp(double price);
	void setCostOnDemand(double price);

	void setReserveVMNumber(int);
	double doCalculate(std::vector<int> & trace);
private:
	double costReservedAmortized;
	double costReservedUp;
	double costOnDemand;
	//double penaltyPerUser;
	int reservedVMNumber;
};

}

#endif /* COSTCALCULATOR_H_ */
