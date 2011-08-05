//============================================================================
// Name        : WeWeExpr.cpp
// Author      : wewe0901
// Version     :
// Copyright   : Use it
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Util/Configuration.h"
#include "Expr/ExperimentalManager.h"

using namespace std;
using namespace WeWeExpr;

void Usage();

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		Usage();
		return 0;
	}
	try
	{
		Configuration config(argv[1]);
		ExperimentalManager::run(config);
	}
	catch(string &e)
	{
		cout<<e<<endl;
	}

	return 0;
}

void Usage()
{
	cout << "USAGE: WeWeExpr config.ini" << endl;
}
