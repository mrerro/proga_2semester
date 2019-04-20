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
		if (fileName.length() == 0 || blockName.length() == 0 || parametrName.length() == 0) {
			throw 1;
		}		
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
		case 1:
			std::cout << "Error passed empty parameter" << std::endl;
			break;
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
	double a = findeInFile("input.txt", "A_material", "N");
	if (a != NULL) {
		std::cout << std::to_string(a) << std::endl;
	}
	std::cout << std::endl;
	a = findeInFile("input.txt", "Data", "Pressure");
	if (a != NULL) {
		std::cout << std::to_string(a) << std::endl;
	}
	std::cout << std::endl;
	a = findeInFile("input.txt", "Constants", "kB");
	if (a != NULL) {
		std::cout << std::to_string(a) << std::endl;
	}
	std::cout << std::endl;
	a = findeInFile("inp.txt", "Constants", "kB");
	if (a != NULL) {
		std::cout << std::to_string(a) << std::endl;
	}
	std::cout << std::endl;
	a = findeInFile("input.txt", "Co", "kB");
	if (a != NULL) {
		std::cout << std::to_string(a) << std::endl;
	}
	std::cout << std::endl;
	a = findeInFile("input.txt", "Constants", "");
	if (a != NULL) {
		std::cout << std::to_string(a) << std::endl;
	}
}