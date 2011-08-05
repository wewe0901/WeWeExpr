/*
 * TestExperimental.cpp
 *
 *  Created on: Aug 3, 2011
 *      Author: wewe0901
 */

#include "TestExperimental.h"
#include <iostream>

namespace WeWeExpr {

TestExperimental::TestExperimental(Configuration &config):Experimental(config) {

	// TODO Auto-generated constructor stub
	std::cout<<"TestExperimental Constructed!!"<<std::endl;
}

TestExperimental::~TestExperimental() {
	// TODO Auto-generated destructor stub
	std::cout<<"TestExperimental Destructed!!"<<std::endl;
}

    void TestExperimental::init()
    {
    	std::cout<<"TestExperimental Initialization !!"<<std::endl;
    }

    void TestExperimental::doExpr()
    {
    	std::cout<<"TestExperimental do Experimental !!"<<std::endl;
    }

} /* namespace WeWeExpr */
