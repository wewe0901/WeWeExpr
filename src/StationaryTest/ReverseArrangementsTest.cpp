/*
 * ReverseArrangementsTest.cpp
 *
 *  Created on: 2011/7/26
 *      Author: wewe0901
 */

#include "ReverseArrangementsTest.h"
#include "ZTable.h"
#include <cmath>
#include <iostream>
namespace WeWeExpr {

ReverseArrangementsTest::ReverseArrangementsTest() {
	// TODO Auto-generated constructor stub

}

ReverseArrangementsTest::~ReverseArrangementsTest() {
	// TODO Auto-generated destructor stub
}
bool ReverseArrangementsTest::test(std::vector<int> & data)
{
	//REFERENCE :
	// An Examination of the Runs Test, Reverse Arrangements Test, and modified
	// Reverse Arrangements Test for assessing surface EMG signal stationarity
	//                                     Journal of Neuroscience Methods 2006
	//countReverse
	int totalReverse=0;

	for(int i =0; i < data.size() - 1 ; i++)
		for(int j = i + 1 ; j < data.size() ; j++)
			if(data.at(i)<data.at(j))
				totalReverse++;

	double N = (double) data.size();
	double R = (double) totalReverse;

	//Calculate z
	double z = ( R - ( N*(N-1) / 4.0) ) / sqrt( (( 2.0*N + 5.0 )*( N - 1 ) * N ) / 72.0 );
	// null hypothesis of p< percentil requires z >= zTableValue or z <= -zTalbeValue
	double zTableValue = ZTable::zValue(percentile);
	std::cerr<<"N="<<N<<"\tR="<<R<<"\t z="<<z<<"\t ztable="<<zTableValue<<std::endl;
	if(z >= zTableValue || z <= -zTableValue)
		return true;


	return false;//no significant trend in the signal
}
}
