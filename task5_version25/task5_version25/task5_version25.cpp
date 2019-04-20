#include <iostream>
#include <fstream>
#include <string>

template <typename T>
T findeInFile(T fileName, std::string blockName , std::string parametrName) {
	std::fstream fs;
	fs.open(fileName, std::fstream::in);
	if (!fs) {
		std::cout << "Error with file name " << fileName << " no in current directory" << std::endl;
		return NULL;
	}
	fs.close();
}


int main()
{
	if (auto a = findeInFile("inpu.txt", "", "") != NULL) {
		std::cout << a;
	}	
}