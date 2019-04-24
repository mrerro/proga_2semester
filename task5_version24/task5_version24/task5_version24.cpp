#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <locale>


void parseDB(std::string fileName) {
	std::fstream fs;
	std::string str;
	std::string group;
	std::list<std::string> out = {};
	bool isBlockFound = false;
	bool isParemetrFound = false;
	try {
		if (fileName.length() == 0) {
			throw 1;
		}
		fs.open(fileName, std::fstream::in);
		if (!fs) {
			throw 2;
		}
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
			std::cout << "Error there are no matching parameters in the file" << std::endl;
			break;
		}
		fs.close();
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}