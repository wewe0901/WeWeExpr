/*
 * OptimalReservationExpr.h
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#ifndef OPTIMALRESERVATIONEXPR_H_
#define OPTIMALRESERVATIONEXPR_H_

#include "Experimental.h"
#include "../Core/TraceReader.h"
#include "../Core/DemandObserver.h"
#include "../Core/ResourceAllocator.h"
#include "../Core/CostCalculator.h"
#include "../Core/PenaltyCalculator.h"
namespace WeWeExpr {

class OptimalReservationExpr: public WeWeExpr::Experimental {
public:
	OptimalReservationExpr(Configuration & config);

	virtual ~OptimalReservationExpr();

	virtual void init();
	virtual	void doExpr();

protected:
	int serverCapability;
	int intaval;
	double costOnDemand;
	double costReservedAmortized;
	double costReservedUp;
	double penaltyFactor;
	TraceReader traceReader;
	DemandObserver demandObserver;
	ResourceAllocator resourceAllocator;
	CostCalculator costCalculator;
	PenaltyCalculator penaltyCalculator;
};

} /* namespace WeWeExpr */
#endif /* OPTIMALRESERVATIONEXPR_H_ */
