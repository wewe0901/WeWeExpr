/*
 * AnalysisReport.h
 *
 *  Created on: 2011/10/13
 *      Author: wewe0901
 */

#ifndef ANALYSISREPORT_H_
#define ANALYSISREPORT_H_

namespace WeWeExpr {

class AnalysisReport {
public:
	AnalysisReport();
	virtual ~AnalysisReport();
    double getMax() const;
    double getMean() const;
    double getMin() const;
    double getVariance() const;
    void setMax(double max);
    void setMean(double mean);
    void setMin(double min);
    void setVariance(double variance);
    double getStdDev() const;
    void setStdDev(double stdDev);
private:
    double max;
    double mean;
    double min;
    double variance;
    double stdDev;
};

} /* namespace WeWeExpr */
#endif /* ANALYSISREPORT_H_ */
