/*
 * DataAnalysis.cpp
 *
 *  Created on: 2011/10/13
 *      Author: wewe0901
 */

#include "DataAnalysis.h"

namespace WeWeExpr {

DataAnalysis::DataAnalysis() {
	// TODO Auto-generated constructor stub

}

DataAnalysis::~DataAnalysis() {
	// TODO Auto-generated destructor stub
}

    AnalysisReport & DataAnalysis::doAnalysis(std::vector<double> trace)
    {
    	double max, min, mean, variance;
    	max = trace[0];
    	min = trace[0];
    	mean = variance = 0.0;

    	for(unsigned int i = 0 ; i< trace.size();i++){
    		mean += trace[i]/trace.size();

    		if(trace[i] > max)
    			max = trace[i];

    		if(trace[i] < min)
    			min = trace[i];

    	}

    	for(unsigned int i = 0 ; i <trace.size();i++){
    		variance += pow((trace[i] - mean),2)/trace.size();
    	}

    	this->report.setMax(max);
    	this->report.setMin(min);
    	this->report.setMean(mean);
    	this->report.setVariance(variance);
    	this->report.setStdDev(sqrt(variance));

    	return this->report;
    }

} /* namespace WeWeExpr */
