#include <iostream>
#include <fstream>
#include <string>

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