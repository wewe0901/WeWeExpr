/*
 * CommandReader.h
 *
 *  Created on: 2011/10/13
 *      Author: wewe0901
 */

#ifndef COMMANDREADER_H_
#define COMMANDREADER_H_

#include <map>
#include <string>
#include <cstdlib>
namespace WeWeExpr {

class CommandReader {
public:
	CommandReader(int argc,char* argv[]);
	virtual ~CommandReader();
	int getOptionInteger(std::string);
	std::string getOptionString(std::string);
	double getOptionDouble(std::string);
	bool issetOption(std::string);
	void test();
private:
	std::map<std::string,std::string> options;
};


} /* namespace WeWeExpr */
#endif /* COMMANDREADER_H_ */
