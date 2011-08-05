/*
 * Configuration.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "Configuration.h"
#include <fstream>
namespace WeWeExpr {


Configuration::Configuration(std::string path)
{
	std::ifstream input;
	input.open(path.c_str());

	if(!input.is_open())
		throw std::string(path+" file open fail");
	char buffer[256];



	std::string key;
	std::string value;
	while(input.good()){
		input.getline(buffer,256);
		std::string temp(buffer);

		key = temp.substr(0,temp.find('='));
		value = temp.substr(temp.find('=')+1);


		setConfig(key,value);
	}
	input.close();
}

Configuration::~Configuration()
{
	 store.clear();
}

std::string Configuration::getConfig(std::string key)
{
	return store[key];
}

void Configuration::setConfig(std::string key, std::string value)
{
	 store[key] = value;
}

} /* namespace WeWeExperimental */
