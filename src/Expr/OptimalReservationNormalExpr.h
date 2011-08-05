/*
 * OpotimalReservationNormalExpr.h
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#ifndef OPTIMALRESERVATIONNORMALEXPR_H_
#define OPTIMALRESERVATIONNORMALEXPR_H_

#include "Experimental.h"
#include "../Core/DataGenerator.h"
#include "../Core/ResourceAllocator.h"
#include "../Core/CostCalculator.h"
#include "../Core/PenaltyCalculator.h"
#include <cmath>
namespace WeWeExpr {

class OptimalReservationNormalExpr: public Experimental {
public:
	OptimalReservationNormalExpr(Configuration & config);
	virtual ~OptimalReservationNormalExpr();
	virtual void init();
	virtual	void doExpr();
protected:
	double mean;
	double variance;
	double costOnDemand;
	double costReservedAmortized;
	double costReservedUp;
	double penaltyFactor;

	ResourceAllocator resourceAllocator;
	CostCalculator costCalculator;
	PenaltyCalculator penaltyCalculator;
	DataGenerator *dataGenerator;
	std::vector<int> normalDistData;
	int size;
};

} /* namespace WeWeExpr */
#endif /* OPTIMALRESERVATIONNORMALEXPR_H_ */
