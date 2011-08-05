/*
 * ExperimentalManager.h
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#ifndef EXPERIMENTALMANAGER_H_
#define EXPERIMENTALMANAGER_H_
#include <string>
#include "../Util/Configuration.h"
#include "Experimental.h"
#include "TestExperimental.h"
#include "OptimalReservationExpr.h"
#include "OptimalReservationNormalExpr.h"
#include "OptimalReservationUniformExpr.h"

namespace WeWeExpr {

class ExperimentalManager {
public:
	static void run(Configuration & config)
	{
		Experimental *expr = NULL;
		std::string experimentalName = config.getConfig("Experimental");

		if(experimentalName.compare("Test")==0)
			expr = new TestExperimental(config);
		else if(experimentalName.compare("OptimalReservation")==0)
			expr = new OptimalReservationExpr(config);
		else if(experimentalName.compare("OptimalReservationNormal")==0)
					expr = new OptimalReservationNormalExpr(config);
		else if(experimentalName.compare("OptimalReservationUniform")==0)
					expr = new OptimalReservationUniformExpr(config);
		else
			throw std::string("Experimental not found! \""+config.getConfig("Experimental")+"\"");

		expr->init();
		expr->doExpr();
		delete expr;
	}

};

} /* namespace WeWeExpr */
#endif /* EXPERIMENTALMANAGER_H_ */
