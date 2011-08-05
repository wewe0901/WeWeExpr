/*
 * HMMPredictionStrategy.cpp
 *
 *  Created on: 2011/7/16
 *      Author: wewe0901
 */

#include "HMMPredictionStrategy.h"
#include <vector>

namespace WeWeExpr {

HMMPredictionStrategy::HMMPredictionStrategy(int n ,int m) {
	// TODO Auto-generated constructor stub
	hmm = new HMMWrapper(n,m);
	trainningMax=0;
	seqCount=0;
	shift=0;
}

HMMPredictionStrategy::~HMMPredictionStrategy() {
	// TODO Auto-generated destructor stub
	delete hmm;
}
void HMMPredictionStrategy::trainning(std::vector<int> data)
{
	//normalize Data
	std::vector<int> dataCopy(data);
	int max=0;
	int min=dataCopy[0];

	for(int i=0 ;i < dataCopy.size();i++)
	{
		if(dataCopy[i]>max)
			max = dataCopy[i];
		if(dataCopy[i]<min)
			min = dataCopy[i];
	}
	shift = min-1;
	for(int i =0;i < dataCopy.size();i++)
		dataCopy[i]-=shift;
	hmm->freeHMM();
	hmm->initHMM(hmm->N,max-min+1);

	hmm->baumWelch(dataCopy);
	hmm->viterbi(dataCopy);
	trainningMax = dataCopy.size();
	seqCount=0;
}
int HMMPredictionStrategy::nextPrediction()
{

	//return hmm->optSequence[seqCount++];
	return shift+ceil(hmm->genSymbol(hmm->optSequence[seqCount++]));
}
void HMMPredictionStrategy::update(int data)
{
	/*std::vector<int> observe;
	observe.push_back(data);
	hmm->baumWelch(observe);
	hmm->viterbi(observe);*/
}
} /* namespace WeWeExperimental */
