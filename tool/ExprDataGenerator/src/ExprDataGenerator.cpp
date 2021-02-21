//============================================================================
// Name        : ExprDataGenerator.cpp
// Author      : wewe0901
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

void Usage();
void generateCommand(char * argv[]);
void generateFile(char * argv[]);
void testDate();
int getYear(int date);
int getMonth(int date);
int getDay(int date);
int dateAdd(int date, int d);
bool dateCheck(int date);
void generateTrainingFile(int startDate, int trainingDataDayNum);
void generateTestFile( int startDate, int testDataDayNum, int trainingDataDayNum);
int dayOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

const string TRACE_PREFIX = "online-";
const string TRACE_EXT = ".log";
const string OUTPUT_PREFIX = "ecourse-tranining-";
const string OUTPUT_EXT = ".log";
const string TEST_PREFIX = "ecourse-test-";
const string TEST_EXT = ".log";

int main(int argc, char* argv[]) {

	if(argc == 4){
		generateFile(argv);
	}
	else if(argc == 5 && argv[4][0] =='c'){
		generateCommand(argv);
	}
	else{
		Usage();
		return 0;
	}

	return 0;
}

void Usage()
{
	cout<< "Usage:ExprDataGenerator 20110721 5 1 [c]" <<endl;
	cout<< "ExprDataGenerator date trainingSetNum testSetNum"<<endl;
}
void generateCommand(char * argv[])
{

	int startDate = atoi(argv[1]);
	int trainingDataDayNum = atoi(argv[2]);
	int testDataDayNum = atoi(argv[3]);
	if(!dateCheck(startDate)){
		cout <<"Error date format!"<< endl;
		exit(0);
	}
	if(trainingDataDayNum < 1
		||testDataDayNum < 1){
		cout<< "Error number : must > 1"<<endl;
		exit(0);
	}
	const string COMMAND_FORMAT = "WEWE_EXPR.exe -E PredictionGainEfficiency -T %s -L %s -I 5 -S 8 -a 0.0043 -u 0.005 -o 0.014 -p 0.005 -r 53 -P HMMML -N 40 -t %d -d %d > output/20111007-testHMMML-confidence/gain-%d-t%d-0.005.result\n";
	stringstream trainingFileName;
	stringstream testFileName;
	trainingFileName << "input/"<<OUTPUT_PREFIX << startDate << "_" << dateAdd(startDate,trainingDataDayNum-1) << OUTPUT_EXT;
	//generate test file
	if(testDataDayNum == 1)
		testFileName << "input/"<<TEST_PREFIX << dateAdd(startDate, trainingDataDayNum) <<TEST_EXT;
	else if(testDataDayNum > 1)
		testFileName <<"input/"<< TEST_PREFIX << dateAdd(startDate, trainingDataDayNum) << "-" << dateAdd(startDate, trainingDataDayNum+testDataDayNum-1)<<TEST_EXT;

	for(int t=1 ; t<= 3 ;t++)
	{

		printf( COMMAND_FORMAT.c_str(),
				trainingFileName.str().c_str(),
				testFileName.str().c_str(),
				t,
				t,
				dateAdd(startDate, trainingDataDayNum),
				t);

	}

}
void generateTestFile( int startDate, int testDataDayNum, int trainingDataDayNum)
{
	ifstream inputFile;
	ofstream outputFile;
	vector<int> logData;

	stringstream trainingFileName;
	stringstream testFileName;
    //Generate test file
    if(testDataDayNum == 1)
        testFileName << TEST_PREFIX << dateAdd(startDate, trainingDataDayNum) << TEST_EXT;

    else
        if(testDataDayNum > 1)
            testFileName << TEST_PREFIX << dateAdd(startDate, trainingDataDayNum) << "-" << dateAdd(startDate, trainingDataDayNum + testDataDayNum - 1) << TEST_EXT;


    outputFile.open(testFileName.str().c_str());
    cout << " -L input/" << testFileName.str() << endl;
    for(int i = trainingDataDayNum;i < testDataDayNum + trainingDataDayNum;i++){
        stringstream inputFileName;
        inputFileName << TRACE_PREFIX << dateAdd(startDate, i) << TRACE_EXT;
        inputFile.open(inputFileName.str().c_str());
        while(inputFile.good()){
            int timestamp, data;
            inputFile >> timestamp >> data;
            outputFile << timestamp << " " << data << endl;
        }
        inputFile.close();
        inputFileName.clear();
    }

    outputFile.close();
}

void generateFile(char * argv[])
{

	int startDate = atoi(argv[1]);
	int trainingDataDayNum = atoi(argv[2]);
	int testDataDayNum = atoi(argv[3]);

	if(!dateCheck(startDate)){
		cout <<"Error date format!"<< endl;
		exit(0);
	}
	if(trainingDataDayNum < 1
		||testDataDayNum < 1){
		cout<< "Error number : must > 1"<<endl;
		exit(0);
	}


	generateTrainingFile( startDate,trainingDataDayNum);

	//Generate test file
    generateTestFile(testDataDayNum, startDate, trainingDataDayNum);
}
void generateTrainingFile(int startDate, int trainingDataDayNum)
{
	ifstream inputFile;
	ofstream outputFile;
	vector<int> logData;

	stringstream trainingFileName;
	stringstream testFileName;

	trainingFileName << OUTPUT_PREFIX << startDate << "_" << dateAdd(startDate,trainingDataDayNum-1) << OUTPUT_EXT;
	outputFile.open(trainingFileName.str().c_str());
	cout<<"-T input/"<<trainingFileName.str();
	for(int i = 0; i < trainingDataDayNum ; i++){
		stringstream inputFileName;
		inputFileName << TRACE_PREFIX << dateAdd(startDate,i) << TRACE_EXT;
		inputFile.open(inputFileName.str().c_str());
		while(inputFile.good())
		{
			int timestamp,data;
			inputFile >> timestamp >> data;
			outputFile << timestamp << " " << data <<endl;
		}
		inputFile.close();
		inputFileName.flush();
	}
	outputFile.close();
	trainingFileName.clear();

}



void testDate()
{
	int date = 20110506;
	int dateAddOne = 20110507;
	int dateAdd30 = 20110606;

	cout<<"date:"<<date<<endl;
	cout<<"date + 1:"<< (dateAdd(date,1) == dateAddOne)<< "("<<dateAdd(date,1)<< ")"<< endl;
	cout<<"date + 30"<< (dateAdd(date,30) == dateAdd30) <<"("<<dateAdd(date,30)<<")" << endl;
}
bool dateCheck(int date)
{
	int year = getYear(date);
	int month = getMonth(date);
	int day = getDay(date);

	if(year != 2011
		|| month < 1
		|| month > 12
		|| day < 1
		|| day > dayOfMonth[month]){

		return false;
	}
	return true;
}
int dateAdd(int date, int d)
{
	int year = getYear(date);
	int month = getMonth(date);
	int day = getDay(date);

	day += d;
	if(day > dayOfMonth[month])
	{
		day = day - dayOfMonth[month];
		month++;
	}

	return year*10000 + month * 100 + day;
}
int getYear(int date)
{
	return date / 10000;
}
int getMonth(int date)
{
	return (date / 100) % 100;
}
int getDay(int date)
{
	return date % 100;
}
bool isWeekend(int date)
{
	time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = getYear(date) - 1900;
	timeinfo->tm_mon = getMonth(date) - 1;
	timeinfo->tm_mday = getDay(date);

	// call mktime: timeinfo->tm_wday will be set
	mktime ( timeinfo );

	return (timeinfo->tm_wday == 0)||((timeinfo->tm_wday == 6));
}
