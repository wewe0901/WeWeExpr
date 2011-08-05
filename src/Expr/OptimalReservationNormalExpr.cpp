/*
 * OptimalReservationNormalExpr.cpp
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#include "OptimalReservationNormalExpr.h"

namespace WeWeExpr {

OptimalReservationNormalExpr::OptimalReservationNormalExpr(Configuration & config):Experimental(config) {
	this->dataGenerator = new DataGenerator(atoi(this->configuration.getConfig("randomSeed").c_str()));
}

OptimalReservationNormalExpr::~OptimalReservationNormalExpr() {
	delete this->dataGenerator;
}

    void OptimalReservationNormalExpr::init()
    {
    	//read configuration and setup variable

		this->costOnDemand = atof(this->configuration.getConfig("costOnDemand").c_str());
		this->costReservedAmortized = atof(this->configuration.getConfig("costReservedAmortized").c_str());
		this->costReservedUp = atof(this->configuration.getConfig("costReservedUp").c_str());
		this->penaltyFactor = atof(this->configuration.getConfig("penaltyFactor").c_str());
		this->mean = atof(this->configuration.getConfig("mean").c_str());
		this->variance = atof(this->configuration.getConfig("variance").c_str());

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

    void OptimalReservationNormalExpr::doExpr()
    {

    	std::vector<int> optReserveData;
		std::vector<double> minCostData;
		double minCostMean = 0;
		double optReserveMean = 0.0;

		for(int n = 0 ; n < TEST_RUN ; n++)
		{
			normalDistData = dataGenerator->normalDist(mean,variance,size);
			resourceAllocator.doAllocate(normalDistData);
			int max=0;
			for(int i = 0; i < normalDistData.size();i++)
			{
				if(max< normalDistData[i])
					max = normalDistData[i];
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
						normalDistData,
						normalDistData,
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
