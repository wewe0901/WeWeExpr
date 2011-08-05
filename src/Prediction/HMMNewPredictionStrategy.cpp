/*
 * HMMNewPredictionStrategy.cpp
 *
 *  Created on: 2011/7/19
 *      Author: wewe0901
 */

#include "HMMNewPredictionStrategy.h"

namespace WeWeExpr {

HMMNewPredictionStrategy::HMMNewPredictionStrategy(int n, int windowSize) {
	// TODO Auto-generated constructor stub
	updateWindowSize = windowSize;
	shift = 0;
	hmm = new HMMWrapper(n,5);
}

HMMNewPredictionStrategy::~HMMNewPredictionStrategy() {
	// TODO Auto-generated destructor stub

	delete hmm;
}

void HMMNewPredictionStrategy::trainning(std::vector<int> data)
{

	int max=0;
	int min=data[0];

	for(int i=0 ;i < data.size();i++)
	{
		if(data[i]>max)
			max = data[i];
		if(data[i]<min)
			min = data[i];
	}
	shift = min-1;
	for(int i =0;i < data.size();i++)
		data[i]-=shift;
	hmm->freeHMM();
	hmm->initHMM(hmm->N,max-min+1);
	this->hmm->baumWelch(data);
	this->hmm->viterbi(data);
}

int HMMNewPredictionStrategy::nextPrediction()
{
	int prevState = this->hmm->optSequence[this->hmm->optSequence.size()-1];
	int curState = this->hmm->genNextState(prevState);

	return shift+this->hmm->genSymbol(curState);

}

void HMMNewPredictionStrategy::update(int data)
{
	updateWindow.push_back(data-shift);

	while(updateWindow.size() > updateWindowSize)
		updateWindow.erase(updateWindow.begin());

	this->hmm->viterbi(updateWindow);
}

}
