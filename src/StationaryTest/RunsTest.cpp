/*
 * RunsTest.cpp
 *
 *  Created on: 2011/7/26
 *      Author: wewe0901
 */

#include "RunsTest.h"
#include "ZTable.h"
#include <cmath>
#include <algorithm>
#include <iostream>
namespace WeWeExpr {

RunsTest::RunsTest() {

}

RunsTest::~RunsTest() {
	// TODO Auto-generated destructor stub
}


bool RunsTest::test(std::vector<int> & data)
{
	//REFERENCE :
	// An Examination of the Runs Test, Reverse Arrangements Test, and modified
	// Reverse Arrangements Test for assessing surface EMG signal stationarity
	//                                     Journal of Neuroscience Methods 2006
	// getMedium

	std::vector<int> temp(data);
	std::sort(temp.begin(),temp.end());

	int medium =temp.at(data.size()/2);
	temp.clear();

	int totalRound = 0;
	int positiveCount = 0;
	int negativeCount = 0;
	int currentState = -1;
	int oldState = -1;
	//run test find positiveCount, negativeCount, totalRound;

	for(int i=0; i < data.size() ; i++)
	{
		if(data[i] >= medium)
		{
			positiveCount++;
			currentState = 1;
		}
		else
		{
			negativeCount++;
			currentState = 0;
		}
		if(currentState != oldState)
			++totalRound;
	}

	//Calculate z
	double r = totalRound;
	double N = data.size();
	double N1 = positiveCount;
	double N2 = negativeCount;
	double h = ( ((2*N1*N2)/N)+1 > r)? 0.5:-0.5;

	double z =  (r+h-((2*N1*N2)/N)-1) / sqrt((2*N1*N2*(2*N1*N2-N))/(N*N*(N-1)));

	double zTableValue = ZTable::zValue(percentile);
	std::cerr<<"N="<<N<<"\tN1="<<N1<<"\tN2="<<N2<<"\tr="<<r<<"\t z="<<z<<"\t ztable="<<zTableValue<<std::endl;
	if(z >= zTableValue || z <= -zTableValue)
		return true;

	return false;//no significant trend in the signal
}

}
