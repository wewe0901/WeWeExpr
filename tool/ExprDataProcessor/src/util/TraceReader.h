/*
 * TraceReader.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef TRACEREADER_H_
#define TRACEREADER_H_

#include <string>
#include <vector>
#include <fstream>
#include <string>

namespace WeWeExpr {

class TraceReader {
public:
	TraceReader();
	virtual ~TraceReader();

	std::vector<double> & load(std::string filename);
	std::vector<double> & getTrace();

private:
	std::vector<double> trace;
};

}


#endif /* TRACEREADER_H_ */
