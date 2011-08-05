/*
 * CostCalculator.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "CostCalculator.h"
#include <iostream>
namespace WeWeExpr {

CostCalculator::CostCalculator() {
	costReservedAmortized = 0.0;
	costReservedUp = 0.0;
	costOnDemand = 0.0;
	reservedVMNumber = 0;

}

CostCalculator::~CostCalculator() {

}


    void CostCalculator::setCostReservedAmortized(double price)
    {
        costReservedAmortized = price;
    }

    void CostCalculator::setCostReservedUp(double price)
    {
        costReservedUp = price;
    }

    void CostCalculator::setCostOnDemand(double price)
    {
        costOnDemand = price;
    }

    void CostCalculator::setReserveVMNumber(int n)
    {
        reservedVMNumber = n;
    }


    double CostCalculator::doCalculate(std::vector<int> & trace)
    {

        double cost = 0.0;

        for(int i = 0; i< trace.size(); i++)
        {
        	int d,r,o;
			d = r = o = 0;

			d = trace[i];
			r = (reservedVMNumber >= d) ? d : reservedVMNumber;
			o = (reservedVMNumber >= d) ? 0 : d - reservedVMNumber;

			cost += costReservedAmortized * reservedVMNumber + costReservedUp * r + costOnDemand * o;
        }

        return cost;
    }
}
