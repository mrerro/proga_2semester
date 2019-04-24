#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <locale>


std::string getGroupNumber(std::string str) {
	str = str.substr(0, str.length() - 1);
	std::string out = "";
	bool split = false;
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (split) {
			out += *it;
		}
		if (*it == ' ') {
			split = true;
		}

	}
	return out;
}

std::string getPerson(std::string str, std::string group) {
	std::string out = "";
	bool split = false;
	int splitCount = 0;
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (split) {
			if (splitCount == 3) { //после имени вставить группу
				out += group + " ";
				splitCount = -1;
			}
			if (*it == '(' || *it == ')') { //выкидываем скобки
			}
			else {
				out += *it;
			}
		}
		if (*it == ' ') {
			split = true;
			splitCount += 1;
		}
	}
	return out;
}

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
		while (getline(fs, str)) {
			if (!str.find("Группа")) {
				group = getGroupNumber(str);
			}
			else if (!str.find("[")) {
				out.push_back(getPerson(str, group));
			}
		}
		if (out.size() == 0) {
			throw 3;
		}
		else {
			out.sort();
		}
		fs.close();
		fs.open("out.txt", std::fstream::out);
		fs << "ФамилияИмя Группа Год рождения\n";
		for (std::string string : out) {
			fs << string + "\n";
		}
		fs.close();
		std::cout << "Success!!!" << std::endl;
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
	setlocale(LC_ALL, "Russian");
	std::cout << "1_________________" << std::endl;
	parseDB("input.txt");
	std::cout << "2_________________" << std::endl;
	parseDB("input2.txt");
	std::cout << "3_________________" << std::endl;
	parseDB("i.txt");
	std::cout << "4_________________" << std::endl;
	parseDB("");
}