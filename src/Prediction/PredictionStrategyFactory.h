/*
 * PredictionStretagyFactory.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef PREDICTIONSTRETAGYFACTORY_H_
#define PREDICTIONSTRETAGYFACTORY_H_

#include <string>
#include <cstdlib>
#include "Configuration.h"
#include "IPredictionStrategy.h"
#include "HMMPredictionStrategy.h"
#include "NullPredictionStrategy.h"
#include "HMMNewPredictionStrategy.h"

namespace WeWeExpr {

class PredictionStrategyFactory {
public:

	static IPredictionStrategy * createPredictionStrategy(std::string name,Configuration& config)
	{

		if(name == "HMM")
		{
			int n = atoi(config.getConfig("N").c_str());
			int m = atoi(config.getConfig("M").c_str());
			HMMPredictionStrategy * predictor;
			predictor = new HMMPredictionStrategy(n,m);
			return ( IPredictionStrategy * )predictor;
		}
		else if(name == "HMMNEW")
		{
			int n = atoi(config.getConfig("N").c_str());
			int windowSize = atoi(config.getConfig("windowSize").c_str());
			HMMNewPredictionStrategy * predictor;
			predictor = new HMMNewPredictionStrategy(n,windowSize);
			return ( IPredictionStrategy * )predictor;
		}
		else if(name == "NULL"){
			NullPredictionStrategy * predictor;
			predictor = new NullPredictionStrategy();
			predictor->setDelay( atoi(config.getConfig("delay").c_str()));
			return ( IPredictionStrategy * )predictor;
		}
		return NULL;
	}
};


} /* namespace WeWeExperimental */
#endif /* PREDICTIONSTRETAGYFACTORY_H_ */
