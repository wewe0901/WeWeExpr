/*
 * OptimalReservationExpr.cpp
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#include "OptimalReservationExpr.h"
#include <iostream>
#include <cstdlib>
namespace WeWeExpr {

OptimalReservationExpr::OptimalReservationExpr(Configuration & config):Experimental(config){
	// TODO Auto-generated constructor stub

}

OptimalReservationExpr::~OptimalReservationExpr() {
	// TODO Auto-generated destructor stub
}
	void OptimalReservationExpr::init()
	{
		//read configuration and setup variable
		this->serverCapability = 1;
		this->intaval =5;
		this->costOnDemand = atof(this->configuration.getConfig("costOnDemand").c_str());
		this->costReservedAmortized = atof(this->configuration.getConfig("costReservedAmortized").c_str());
		this->costReservedUp = atof(this->configuration.getConfig("costReservedUp").c_str());
		this->penaltyFactor = atof(this->configuration.getConfig("penaltyFactor").c_str());

		//setup demand observer
		std::string logfile(this->configuration.getConfig("logFile"));
		demandObserver.setServerCapability(serverCapability);
		demandObserver.setIntaval(intaval);
		demandObserver.setTrace(traceReader.load(logfile));

		//setup cost calculator
		costCalculator.setCostOnDemand(costOnDemand);
		costCalculator.setCostReservedAmortized(costReservedAmortized);
		costCalculator.setCostReservedUp(costReservedUp);

		//setup penalty calculator
		penaltyCalculator.setPenaltyFactor(penaltyFactor);



	}

	void OptimalReservationExpr::doExpr()
	{
		// Real Data Expr
		std::vector<double> pdf;
		pdf.resize(demandObserver.getMaxDemand()+2);
		for(int i=0; i<=demandObserver.getMaxDemand();i++)
			pdf[i]=0.0;

		for(int i=0; i<demandObserver.getDemandTrace().size();i++)
		{
			int d = demandObserver.getDemandTrace().at(i);
			pdf[d] += 1.0/(double)demandObserver.getDemandTrace().size();

		}
		std::cout<< "demand" <<"\t" <<"PDF"<<"\t"<<"CDF"<<std::endl;

		double cdf=0.0;
		for(int i=0; i<=demandObserver.getMaxDemand();i++)
		{
			cdf += pdf[i];
			std::cout << i <<"\t" <<pdf[i] <<"\t" <<cdf<<std::endl;
		}
		resourceAllocator.doAllocate(demandObserver.getDemandTrace());
		for(int i =0 ; i < demandObserver.getMaxDemand(); i++ )
		{
			double cost = 0.0;
			double penalty = 0.0;

			costCalculator.setReserveVMNumber(i);

			cost = costCalculator.doCalculate(resourceAllocator.getResourceTrace());

			penalty = penaltyCalculator.doCalculate(
					demandObserver.getOnlineTrace(),
					demandObserver.getDemandTrace(),
					resourceAllocator.getResourceTrace());

			std::cout << i << "\t" << cost << "\t" << penalty << "\t" << cost+penalty<<std::endl;
		}
	}

} /* namespace WeWeExpr */
