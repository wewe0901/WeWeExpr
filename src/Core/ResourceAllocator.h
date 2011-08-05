/*
 * ResourceAllocator.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef RESOURCEALLOCATOR_H_
#define RESOURCEALLOCATOR_H_
#include <vector>
#include "../Prediction/IPredictionStrategy.h"

namespace WeWeExpr {

class ResourceAllocator {
public:
	ResourceAllocator();
	virtual ~ResourceAllocator();
	void setPredictor(IPredictionStrategy * predictor);
	std::vector<int> & doAllocate(std::vector<int> & demandTrace);

	std::vector<int> & getResourceTrace();
private:
	IPredictionStrategy* predictor;
	std::vector<int> resourceTrace;
};

} /* namespace WeWeExperimental */
#endif /* RESOURCEALLOCATOR_H_ */
