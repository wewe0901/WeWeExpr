/*
 * OptimalReservationUniformExpr.cpp
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#include "OptimalReservationUniformExpr.h"

namespace WeWeExpr {

OptimalReservationUniformExpr::OptimalReservationUniformExpr(Configuration & config):Experimental(config) {
	this->dataGenerator = new DataGenerator(atoi(this->configuration.getConfig("randomSeed").c_str()));
}

OptimalReservationUniformExpr::~OptimalReservationUniformExpr() {
	delete this->dataGenerator;

}

    void OptimalReservationUniformExpr::init()
    {
    	//read configuration and setup variable
		this->costOnDemand = atof(this->configuration.getConfig("costOnDemand").c_str());
		this->costReservedAmortized = atof(this->configuration.getConfig("costReservedAmortized").c_str());
		this->costReservedUp = atof(this->configuration.getConfig("costReservedUp").c_str());
		this->penaltyFactor = atof(this->configuration.getConfig("penaltyFactor").c_str());
		this->lower = atoi(this->configuration.getConfig("lower").c_str());
		this->upper = atoi(this->configuration.getConfig("upper").c_str());


		//setup data generator
		size = atoi(this->configuration.getConfig("dataSize").c_str());
		resourceAllocator.setPredictor(NULL);


		//setup cost calculator
		costCalculator.setCostOnDemand(costOnDemand);
		costCalculator.setCostReservedAmortized(costReservedAmortized);
		costCalculator.setCostReservedUp(costReservedUp);

		//setup penalty calculator
		penaltyCalculator.setPenaltyFactor(penaltyFactor);
    }

    void OptimalReservationUniformExpr::doExpr()
    {
    	std::vector<int> optReserveData;
    	std::vector<double> minCostData;
    	double minCostMean = 0;
    	double optReserveMean = 0.0;

    	for(int n = 0 ; n < TEST_RUN ; n++)
    	{
			uniformDistData = dataGenerator->uniformDist(lower,upper,size);
			resourceAllocator.doAllocate(uniformDistData);
			int max=0;
			for(int i = 0; i < uniformDistData.size();i++)
			{
				if(max< uniformDistData[i])
					max = uniformDistData[i];
			}
			double minCost = 1000000;
			int optimalReserve = 0.0;
			for(int i =0 ; i <= max; i++ )
			{
				double cost = 0.0;
				double penalty = 0.0;

				costCalculator.setReserveVMNumber(i);

				cost = costCalculator.doCalculate(resourceAllocator.getResourceTrace());

				penalty = penaltyCalculator.doCalculate(
						uniformDistData,
						uniformDistData,
						resourceAllocator.getResourceTrace());
				if(cost+penalty < minCost)
				{
					minCost = cost+penalty;
					optimalReserve = i;
				}
			}
			minCostMean += minCost;
			optReserveMean += optimalReserve;
			optReserveData.push_back(optimalReserve);
			minCostData.push_back(minCost);
    	}

    	//Calculate Confidence interval
    	minCostMean /= (double)TEST_RUN;
    	optReserveMean /= (double)TEST_RUN;
    	double minCostSD = 0.0;
    	double optReserveSD = 0.0;
    	for(int n = 0 ; n< TEST_RUN ;n++)
    	{
    		minCostSD += pow(minCostData[n]-minCostMean,2);
    		optReserveSD += pow(optReserveData[n]-optReserveMean,2);
    	}
    	minCostSD = sqrt(minCostSD/(double)TEST_RUN);
    	optReserveSD = sqrt(optReserveSD/(double)TEST_RUN);
    	// 95% confidence
    	double minCostConfidenceRange = 1.96*minCostSD/sqrt(TEST_RUN);
    	double optReserveConfidenceRange = 1.96*optReserveSD/sqrt(TEST_RUN);

    	std::cout << "\t mean\t range" << std::endl;
    	std::cout << "minCost\t" <<   minCostMean << "\t" << minCostConfidenceRange << std::endl;
    	std::cout << "optReserve\t" << optReserveMean << "\t" << optReserveConfidenceRange<< std::endl;

    }

} /* namespace WeWeExpr */
