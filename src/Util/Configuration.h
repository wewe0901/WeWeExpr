/*
 * Configuration.h
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_
#include <map>
#include <string>
namespace WeWeExpr {

class Configuration {
public:
	Configuration(std::string path);
	virtual ~Configuration();
	std::string getConfig(std::string key);
	void setConfig(std::string key, std::string value);

private:
	std::map<std::string,std::string> store;
};

} /* namespace WeWeExperimental */
#endif /* CONFIGURATION_H_ */
