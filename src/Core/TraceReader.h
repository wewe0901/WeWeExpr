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
namespace WeWeExpr {

class TraceReader {
public:
	TraceReader();
	virtual ~TraceReader();

	std::vector<int> & load(std::string filename);
	std::vector<int> & getTrace();

private:
	std::vector<int> trace;
};

}

#endif /* TRACEREADER_H_ */
