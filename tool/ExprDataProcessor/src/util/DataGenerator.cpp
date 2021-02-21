/*
 * DataGenerator.cpp
 *
 *  Created on: 2011/10/14
 *      Author: wewe0901
 */

#include "DataGenerator.h"
#include "boost/date_time/gregorian/gregorian.hpp"

namespace WeWeExpr {

DataGenerator::DataGenerator() {

	this->iPrefix = "";
	this->oPrefix = "";
	this->dateStr = "";
	this->dayNum = 0;
	this->dayDelay= 0;
	this->weekend = false;
	this->workday = false;
}

DataGenerator::~DataGenerator() {

}

std::string DataGenerator::getDateStr() const
{
    return dateStr;
}

int DataGenerator::getDayNum() const
{
    return dayNum;
}

std::string DataGenerator::getIPrefix() const
{
    return iPrefix;
}

std::string DataGenerator::getOPrefix() const
{
    return oPrefix;
}

void DataGenerator::setDateStr(std::string dateStr)
{
    this->dateStr = dateStr;
}

void DataGenerator::setDayNum(int days)
{
    this->dayNum = days;
}

void DataGenerator::setIPrefix(std::string iPrefix)
{
    this->iPrefix = iPrefix;
}

void DataGenerator::setOPrefix(std::string oPrefix)
{
    this->oPrefix = oPrefix;
}

void DataGenerator::generate()
{
	if(!this->_validateParams())
		throw std::string("Error Parameter :Please set all parameter");
	using namespace boost::gregorian;
	date dt(from_undelimited_string(this->dateStr));
	date dTemp(from_undelimited_string(this->dateStr));
	std::vector<std::string> files;

	int dayCount = 0;

	//用來校正 記錄時候的延遲狀態， 名為 20110616的檔案 其實為20110615的記錄
	//如果 要 20110615往後三天的資料 需要抓 名為 20110616 ~20110618的資料
	//實記帳的資料為20110615~20110617
	if(this->dayDelay > 0){
		dt += days(this->dayDelay);
		dTemp+=days(this->dayDelay);
	}
	while(dayCount != this->dayNum){

		if((dTemp-days(this->dayDelay)).day_of_week() == 0 || (dTemp-days(this->dayDelay)).day_of_week() == 6){
			if(this->workday){
				dTemp += days(1);
				continue;
			}
		}
		else if(this->weekend){
			dTemp += days(1);
			continue;
		}

		files.push_back(this->getIPrefix() + to_iso_string(dTemp) +".log");
		dTemp+= days(1);
		dayCount++;
	}
	if(this->dayDelay > 0){
		dt -= days(this->dayDelay);
		dTemp -=days(this->dayDelay);
	}
	std::string outputName = this->getOPrefix() + to_iso_string(dt) + "-" + to_iso_string(dTemp-days(1))+".log";
	FileCombieHelper::combieToFile(files,outputName);


}
    void DataGenerator::onlyWorkDay(bool ans)
    {
    	this->workday = ans;
    }

    void DataGenerator::onlyWeekend(bool ans)
    {
    	this->weekend = ans;
    }

    bool DataGenerator::_validateParams()
    {
    	return (this->dateStr.compare("") != 0)
    			&& (this->iPrefix.compare("") != 0)
    			&& (this->oPrefix.compare("") != 0)
    			&& (this->dayNum > 0);
    }

    int DataGenerator::getDayDelay() const
    {
        return dayDelay;
    }

    void DataGenerator::setDayDelay(int dayDelay)
    {
        this->dayDelay = dayDelay;}

    /* namespace WeWeExpr */
}

