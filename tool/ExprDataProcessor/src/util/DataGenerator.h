/*
 * DataGenerator.h
 *
 *  Created on: 2011/10/14
 *      Author: wewe0901
 */

#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <string>
#include "FileCombieHelper.h"


namespace WeWeExpr {

class DataGenerator {
public:
	DataGenerator();
	virtual ~DataGenerator();

    std::string getDateStr() const;
    int getDayNum() const;
    std::string getIPrefix() const;
    std::string getOPrefix() const;

    void setDateStr(std::string dateStr);
    void setDayNum(int days);
    void setIPrefix(std::string iPrefix);
    void setOPrefix(std::string oPrefix);
    void onlyWorkDay(bool ans = false);
    void onlyWeekend(bool ans = false );
    void generate();
    int getDayDelay() const;
    void setDayDelay(int dayDelay);

private:
    bool _validateParams();
	std::string iPrefix;
	std::string oPrefix;
	std::string dateStr;
	int dayNum;
	int dayDelay;
	bool workday;
	bool weekend;

};

} /* namespace WeWeExpr */
#endif /* DATAGENERATOR_H_ */
