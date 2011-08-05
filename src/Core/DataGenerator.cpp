/*
 * DataGenerator.cpp
 *
 *  Created on: Aug 1, 2011
 *      Author: wewe0901
 */

#include "DataGenerator.h"

namespace WeWeExpr {
\
DataGenerator::DataGenerator() {
	// TODO Auto-generated constructor stub
	normalData.clear();
	uniformData.clear();
}
DataGenerator::DataGenerator(int randomSeed):rng(randomSeed) {
	// TODO Auto-generated constructor stub
	normalData.clear();
	uniformData.clear();
}

DataGenerator::~DataGenerator() {
	// TODO Auto-generated destructor stub

}
std::vector<int> & DataGenerator::normalDist(double mean, double variance,int size)
{
	normalData.clear();
	boost::random::normal_distribution<> normal_dist(mean,variance);

	for(int i = 0; i < size; i++)
		normalData.push_back((int)normal_dist(rng));

	return normalData;

}
std::vector<int> & DataGenerator::uniformDist(int lower,int upper,int size)
{
	uniformData.clear();

	boost::random::uniform_int_distribution<> index_dist(lower,upper);

	for(int i = 0; i < size; i++)
		uniformData.push_back((int) index_dist(rng));

	return uniformData;
}
} /* namespace WeWeExpr */
