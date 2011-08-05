/*
 * TestExperimental.h
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#ifndef TESTEXPERIMENTAL_H_
#define TESTEXPERIMENTAL_H_

#include "Experimental.h"

namespace WeWeExpr {

class TestExperimental: public Experimental {
public:
	TestExperimental(Configuration &config);
	virtual ~TestExperimental();
	virtual void init();
	virtual void doExpr();
};

} /* namespace WeWeExpr */
#endif /* TESTEXPERIMENTAL_H_ */
