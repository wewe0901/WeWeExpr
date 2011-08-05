/*
 * OptimalReservationUniformExpr.h
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#ifndef OPTIMALRESERVATIONUNIFORMEXPR_H_
#define OPTIMALRESERVATIONUNIFORMEXPR_H_

#include "Experimental.h"
#include "../Core/DataGenerator.h"
#include "../Core/ResourceAllocator.h"
#include "../Core/CostCalculator.h"
#include "../Core/PenaltyCalculator.h"
#include <cmath>
namespace WeWeExpr {

class OptimalReservationUniformExpr: public Experimental {
public:
	OptimalReservationUniformExpr(Configuration & config);
	virtual ~OptimalReservationUniformExpr();
	virtual void init();
	virtual	void doExpr();
protected:
	int lower;
	int upper;
	double costOnDemand;
	double costReservedAmortized;
	double costReservedUp;
	double penaltyFactor;

	ResourceAllocator resourceAllocator;
	CostCalculator costCalculator;
	PenaltyCalculator penaltyCalculator;
	DataGenerator * dataGenerator;
	int size;
	std::vector<int> uniformDistData;
};

} /* namespace WeWeExpr */
#endif /* OPTIMALRESERVATIONUNIFORMEXPR_H_ */
