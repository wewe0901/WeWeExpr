/*
 * FileCombieHelper.h
 *
 *  Created on: 2011/10/14
 *      Author: wewe0901
 */

#ifndef FILECOMBIEHELPER_H_
#define FILECOMBIEHELPER_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
namespace WeWeExpr {

class FileCombieHelper {
public:

	static void combieToFile(std::vector<std::string> files, std::string outputFilename){
		std::ifstream input;
		std::ofstream output;
		output.open(outputFilename.c_str());
		if(!output.is_open())
			throw std::string(outputFilename+" : File open fail!");

		char buffer[1024];
		for(int i = 0; i < files.size(); i++){
			input.open(files[i].c_str());
			if(!input.is_open())
				throw std::string(files[i]+" : File open fail!");
			while(input.good()){
				input.getline(buffer,1024);
				output << buffer<<std::endl;
			}
			input.close();
		}
		output.close();
	}
};

} /* namespace WeWeExpr */
#endif /* FILECOMBIEHELPER_H_ */
