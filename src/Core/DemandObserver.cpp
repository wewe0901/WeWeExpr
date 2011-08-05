/*
 * DemandObserver.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "DemandObserver.h"
#include <cmath>
#include<iostream>

namespace WeWeExpr {

DemandObserver::DemandObserver() {
	// TODO Auto-generated constructor stub
	totalMax=0;
}

DemandObserver::~DemandObserver() {
	// TODO Auto-generated destructor stub
}

void DemandObserver::setServerCapability(int cap)
{
	this->serverCapability = cap;
}
void DemandObserver::setIntaval(int intaval)
{
	this->intaval = intaval;
}
void DemandObserver::setTrace(std::vector<int> & trace)
{

	int max = 0;
	for(int i= 0 ;i < trace.size(); i++)
	{

		if(trace[i]>max)
			max = trace[i];

		if(max>totalMax)
			totalMax=max;

		if( i % intaval == intaval-1 )
		{
			double demand = ceil((double)max/(double)serverCapability);
			this->onlineTrace.push_back(max);
			this->demandTrace.push_back((int)demand);
			max = 0;
		}

	}
	totalMax = ceil((double)totalMax/(double)serverCapability);
}

int DemandObserver::getMaxDemand()
{
	return totalMax;
}

std::vector<int> & DemandObserver::getOnlineTrace()
{
	return this->onlineTrace;
}
std::vector<int> & DemandObserver::getDemandTrace()
{
	return this->demandTrace;
}

} /* namespace WeWeExperimental */
