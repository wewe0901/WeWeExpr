/*
 * Experimetal.h
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#ifndef EXPERIMETAL_H_
#define EXPERIMETAL_H_

#include "IExperimental.h"
#include "../Util/Configuration.h"
namespace WeWeExpr {
const int TEST_RUN =20;
class Experimental: public IExperimental {
public:
	Experimental(Configuration & config);
	virtual ~Experimental();

	virtual void init(){};
	virtual	void doExpr(){};
protected:
	Configuration & configuration;
};

} /* namespace WeWeExpr */
#endif /* EXPERIMETAL_H_ */
