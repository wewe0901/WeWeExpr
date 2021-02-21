/*
 * TraceReader.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "TraceReader.h"


namespace WeWeExpr {

TraceReader::TraceReader()
{
}



TraceReader::~TraceReader()
{
}



std::vector<double>& TraceReader::load(std::string filename)
{
	this->trace.clear();
	std::ifstream logFile;
	logFile.open(filename.c_str());
	double timestamp=0;
	double data=0;
	if(!logFile.is_open())
			throw std::string(filename+" file open fail");

	while(logFile.good())
	{
		logFile >> timestamp >> data;
		trace.push_back(data);
	}


	return this->trace;
}



std::vector<double> & TraceReader::getTrace()
{
	return this->trace;
}



}
