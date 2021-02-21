/*
 * DataAnalysis.h
 *
 *  Created on: 2011/10/13
 *      Author: wewe0901
 */

#ifndef DATAANALYSIS_H_
#define DATAANALYSIS_H
#include <vector>
#include <cmath>
#include "AnalysisReport.h";
namespace WeWeExpr {

class DataAnalysis {
public:
	DataAnalysis();
	virtual ~DataAnalysis();

	AnalysisReport & doAnalysis(std::vector<double> trace);

private:
	AnalysisReport report;

};

} /* namespace WeWeExpr */
#endif /* DATAANALYSIS_H_ */
