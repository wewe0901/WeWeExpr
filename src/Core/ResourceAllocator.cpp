/*
 * ResourceAllocator.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "ResourceAllocator.h"

namespace WeWeExpr {

ResourceAllocator::ResourceAllocator() {
	// TODO Auto-generated constructor stub

}

ResourceAllocator::~ResourceAllocator() {
	// TODO Auto-generated destructor stub
}

void ResourceAllocator::setPredictor(IPredictionStrategy * predictor)
{
	this->predictor = predictor;
}

std::vector<int> & ResourceAllocator::doAllocate(std::vector<int> & demandTrace)
{
	this->resourceTrace.clear();
	if(this->predictor != NULL)
	{
		for(int i = 0; i < demandTrace.size(); i++)
		{
			int allocate = this->predictor->nextPrediction();
			this->resourceTrace.push_back(allocate);
			this->predictor->update(demandTrace[i]);
		}
	}
	else
	{
		for(int i = 0; i < demandTrace.size();i++)
			this->resourceTrace.push_back(demandTrace[i]);
	}
	return this->resourceTrace;
}

std::vector<int> & ResourceAllocator::getResourceTrace()
{
	return this->resourceTrace;
}

} /* namespace WeWeExperimental */
