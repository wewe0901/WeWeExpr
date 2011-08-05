/*
 * DataGenerator.h
 *
 *  Created on: Aug 1, 2011
 *      Author: wewe0901
 */

#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <vector>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
namespace WeWeExpr {

class DataGenerator {
public:
	DataGenerator();
	DataGenerator(int randomSeed);
	virtual ~DataGenerator();
	std::vector<int> &normalDist(double mean, double variance,int size);
	std::vector<int> &uniformDist(int lower,int upper,int size);
public:
	std::vector<int> normalData;
	std::vector<int> uniformData;
	boost::random::mt19937 rng;
};

} /* namespace WeWeExpr */
#endif /* DATAGENERATOR_H_ */
