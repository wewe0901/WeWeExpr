/*
 * DemandObserver.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef DEMANDOBSERVER_H_
#define DEMANDOBSERVER_H_
#include <vector>
namespace WeWeExpr {

class DemandObserver {
public:
	DemandObserver();
	virtual ~DemandObserver();
	void setServerCapability(int cap);
	void setIntaval(int intaval);
	void setTrace(std::vector<int> & trace);

	std::vector<int> & getOnlineTrace();
	std::vector<int> & getDemandTrace();
	int getMaxDemand();
private:
	int intaval;
	int serverCapability;
	std::vector<int> onlineTrace;
	std::vector<int> demandTrace;
	int totalMax;
};

} /* namespace WeWeExperimental */
#endif /* DEMANDOBSERVER_H_ */
