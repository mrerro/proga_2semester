#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

double findeInFile(std::string fileName, std::string blockName, std::string parametrName) {
	std::fstream fs;
	std::string str;
	bool isBlockFound = false;
	bool isParemetrFound = false;
	try {
		fs.open(fileName, std::fstream::in);
		if (!fs) {
			throw 2;
		}
		while (getline(fs, str)) {
			str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
			if (isBlockFound && !isParemetrFound) {
				if (!str.find(parametrName)) {
					isParemetrFound = true;
					std::cout << "Parametr found: " << str << std::endl;
					fs.close();
					return std::stod(str.substr(str.find("=") + 1, str.length() - str.find("=")));
				}
				if (str == "}" && !isParemetrFound) {
					throw 3;
				}
			}
			if (str == blockName && !isBlockFound) {
				isBlockFound = true;
				std::cout << "Block found: " << str << std::endl;
			}
		}
		fs.close();
		std::cout << "file ended before request" << std::endl;
		return NULL;
	}
	catch (int error) {
		switch (error)
		{
		case 2:
			std::cout << "Error with file name " << fileName << " no in current directory" << std::endl;
			break;
		case 3:
			std::cout << "Error there is no such parameter " << parametrName << " in the block " << blockName << std::endl;
			break;
		}
		fs.close();
		return NULL;
	}
}


int main()
{
	if (auto a = findeInFile("inpu.txt", "", "") != NULL) {
		std::cout << a;
	}	
}