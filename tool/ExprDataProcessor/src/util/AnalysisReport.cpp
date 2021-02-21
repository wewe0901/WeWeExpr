/*
 * AnalysisReport.cpp
 *
 *  Created on: 2011/10/13
 *      Author: wewe0901
 */

#include "AnalysisReport.h"

namespace WeWeExpr {

AnalysisReport::AnalysisReport() {
	// TODO Auto-generated constructor stub

}

AnalysisReport::~AnalysisReport() {
	// TODO Auto-generated destructor stub
}

    double AnalysisReport::getMax() const
    {
        return max;
    }

    double AnalysisReport::getMean() const
    {
        return mean;
    }

    double AnalysisReport::getMin() const
    {
        return min;
    }

    double AnalysisReport::getVariance() const
    {
        return variance;
    }

    void AnalysisReport::setMax(double max)
    {
        this->max = max;
    }

    void AnalysisReport::setMean(double mean)
    {
        this->mean = mean;
    }

    void AnalysisReport::setMin(double min)
    {
        this->min = min;
    }

    void AnalysisReport::setVariance(double variance)
    {
        this->variance = variance;}

    double AnalysisReport::getStdDev() const
    {
        return stdDev;
    }

    void AnalysisReport::setStdDev(double stdDev)
    {
        this->stdDev = stdDev;}

} /* namespace WeWeExpr */
