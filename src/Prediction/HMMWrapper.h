/*
 * HMMWrapper.h
 *
 *  Created on: 2011/7/18
 *      Author: wewe0901
 */

#ifndef HMMWRAPPER_H_
#define HMMWRAPPER_H_
#include<vector>


extern "C"
{
#include "hmm.h"
#include "nrutil.h"
}
class HMMWrapper {
public:
	HMMWrapper(int n,int m);
	virtual ~HMMWrapper();
	void baumWelch(std::vector<int>  & Observation);
	int * vectorToSequence(std::vector<int>  &v);
	void initHMM(int n,int m);
	void freeHMM();
	void viterbi(std::vector<int> & v);

	int genInitialState();
	int genNextState(int q);
	int genSymbol(int q);
	void dumpHMM();
	std::vector<int> optSequence;
	int N;
	int M;
private:
	HMM hmm;
	int T;

};


#endif /* HMMWRAPPER_H_ */
