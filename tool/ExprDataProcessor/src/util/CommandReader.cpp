/*
 * CommandReader.cpp
 *
 *  Created on: 2011/10/13
 *      Author: wewe0901
 */

#include "CommandReader.h"

namespace WeWeExpr {

CommandReader::CommandReader(int argc,char* argv[]) {

	for(int i = 0; i < argc; i++)
	{
		if(argv[i][0] == '-'){
			std::string option((argv[i]+1));
			std::string value("");

			if( i+1 < argc && argv[i+1][0] != '-'){
				value = argv[i+1];
				i++;
			}
			this->options[option] = value;
		}

	}
}

CommandReader::~CommandReader() {
	// TODO Auto-generated destructor stub
}


    int CommandReader::getOptionInteger(std::string allocator)
    {
    	if(!this->issetOption(allocator))
    		throw std::string(allocator+":Command Option not found\n");

    	return atoi(this->options[allocator].c_str());
    }

    std::string CommandReader::getOptionString(std::string allocator)
    {
    	if(!this->issetOption(allocator))
			throw std::string(allocator+":Command Option not found\n");
    	return this->options[allocator];
    }

    double CommandReader::getOptionDouble(std::string allocator)
    {
    	if(!this->issetOption(allocator))
			throw std::string(allocator+":Command Option not found\n");
    	return atof(this->options[allocator].c_str());
    }

    void CommandReader::test()
    {

    }

    bool CommandReader::issetOption(std::string allocator)
    {
    	return ! (this->options.end() == this->options.find(allocator));
    }

} /* namespace WeWeExpr */
