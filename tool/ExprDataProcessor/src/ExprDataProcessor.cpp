//============================================================================
// Name        : ExprDataProcessor.cpp
// Author      : wewe0901
// Version     :
// Copyright   : Your copyright notice
// Description : Process WEWE Expr input data
//============================================================================

#include <iostream>
#include "util/CommandReader.h"
#include "util/DataAnalysis.h"
#include "util/DataGenerator.h"
#include "util/TraceReader.h"

using namespace std;
using namespace WeWeExpr;


int main(int argc, char* argv[]) {
	/**
	 * This program has few responsibility
	 * 1. Analysis input data.(ex: mean, variance ...etc)
	 * 2. Generator input data.
	 */


	try{
		CommandReader command(argc,argv);

		if(command.getOptionString("action").compare("analysis")==0){

			TraceReader trace;
			DataAnalysis dataAnalyzer;
			trace.load(command.getOptionString("traceFile"));
			AnalysisReport report = dataAnalyzer.doAnalysis(trace.getTrace());

			cout<<command.getOptionString("traceFile")<< " ";
			cout<< report.getMin() << " " << report.getMax() << " " << report.getMean() << " " << report.getVariance() << " " << report.getStdDev() << endl;

		}
		else if(command.getOptionString("action").compare("generate")==0){

			//combie.combieToFile(vector<string> inptFiles,string ouputFileName);
			cout<<"strat!"<<endl;
			DataGenerator generator;
			generator.setDateStr(command.getOptionString("startDate"));
			generator.setIPrefix(command.getOptionString("iPrefix"));
			generator.setOPrefix(command.getOptionString("oPrefix"));
			generator.setDayNum(command.getOptionInteger("days"));
			generator.onlyWeekend(command.issetOption("justWeekend"));
			generator.onlyWorkDay(command.issetOption("justWorkday"));
			generator.setDayDelay(command.issetOption("justWorkday"));
			generator.generate();
			cout<<"Done!!"<<endl;

		}
	}
	catch(std::string &e){
		cout << "Exception Occur :" << e << endl;
	}


	return 0;
}
