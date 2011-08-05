/*
 * HMMWrapper.cpp
 *
 *  Created on: 2011/7/18
 *      Author: wewe0901
 */

#include "HMMWrapper.h"



HMMWrapper::HMMWrapper(int n,int m) {

	initHMM(n,m);
}

HMMWrapper::~HMMWrapper() {
	freeHMM();
}

void HMMWrapper::initHMM(int n,int m)
{
	N=n;
	M=m;
	int seed = hmmgetseed();
	InitHMM(&hmm, n, m, seed);
}

void HMMWrapper::freeHMM()
{
	FreeHMM(&hmm);
}

void HMMWrapper::baumWelch(std::vector<int> & observation)
{
	int	niter;
	int T;
	int *O;
	double	logprobinit, logprobfinal;
	double 	**alpha;
	double	**beta;
	double	**gamma;

	T = observation.size();
	O = this->vectorToSequence(observation);
	alpha = dmatrix(1, T, 1, hmm.N);
	beta = dmatrix(1, T, 1, hmm.N);
	gamma = dmatrix(1, T, 1, hmm.N);

	BaumWelch(&hmm, T, O, alpha, beta, gamma, &niter,&logprobinit, &logprobfinal);
	free_ivector(O, 1, T);
	free_dmatrix(alpha, 1, T, 1, hmm.N);
	free_dmatrix(beta, 1, T, 1, hmm.N);
	free_dmatrix(gamma, 1, T, 1, hmm.N);
}

int * HMMWrapper::vectorToSequence(std::vector<int> &v)
{
	int *O;
	O = ivector(1,v.size());
	for (int i=1; i <= v.size(); i++)
		O[i] = v[i-1];

	return O;
}


void HMMWrapper::viterbi(std::vector<int> & v)
{
	int	*O;	/* observation sequence O[1..T] */
	int	*q;	/* state sequence q[1..T] */
	double **delta;
	int	**psi;
	int T = v.size();
	double 	proba;

	optSequence.clear();

	O = this->vectorToSequence(v);
	q = ivector(1,T);

	delta = dmatrix(1, T, 1, hmm.N);
	psi = imatrix(1, T, 1, hmm.N);

	Viterbi(&hmm, T, O, delta, psi, q, &proba);

	for(int i=1 ;i<=T;i++)
		optSequence.push_back(q[i]);

	free_ivector(q, 1, T);
	free_ivector(O, 1, T);
	free_imatrix(psi, 1, T, 1, hmm.N);
	free_dmatrix(delta, 1, T, 1, hmm.N);
}

int HMMWrapper::genInitialState()
{
	return GenInitalState(&hmm);
}

int HMMWrapper::genNextState(int q)
{
	return GenNextState(&hmm,q);
}

int HMMWrapper::genSymbol(int q)
{
	double tempSum,temp;
	tempSum = 0.0;

	for(int j=1;j<=hmm.N;j++)
	{
		temp = 0.0;
		for(int k=1;k<=hmm.M;k++)
		{
			temp += k * hmm.B[j][k];
		}
		tempSum += hmm.A[q][j]*temp;
	}

	return tempSum;
	//return GenSymbol(&hmm,q);
}
void HMMWrapper::dumpHMM()
{

	//PrintHMM(stderr,&hmm);
}

