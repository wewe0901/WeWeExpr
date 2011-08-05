/*
 * IExperimental.h
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#ifndef IEXPERIMENTAL_H_
#define IEXPERIMENTAL_H_
namespace WeWeExpr {

class IExperimental {
	virtual void init()=0;
	virtual	void doExpr()=0;
};

} /* namespace WeWeExpr */
#endif /* IEXPERIMENTAL_H_ */
