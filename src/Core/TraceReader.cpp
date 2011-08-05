/*
 * TraceReader.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "TraceReader.h"
#include <fstream>
#include <string>

namespace WeWeExpr {

TraceReader::TraceReader() {

}

TraceReader::~TraceReader() {

}

std::vector<int> & TraceReader::load(std::string filename)
{
	std::ifstream logFile;
	logFile.open(filename.c_str());
	int timestamp=0;
	int data=0;
	if(!logFile.is_open())
			throw std::string(filename+" file open fail");

	while(logFile.good())
	{
		logFile >> timestamp >> data;
		trace.push_back(data);
	}


	return this->trace;
}

std::vector<int> & TraceReader::getTrace()
{

	return this->trace;
}

}
