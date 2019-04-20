#include <iostream>
#include <deque>
#include <list>

void myDequeTester() {
	std::deque <std::list<int>> myDeque = {};
	std::list <int> one = { 1,1 };
	std::list <int> two = { 2 };
	std::list <int> three = { 3,3 };
	std::list <int> four = { 4 };
	std::list <int> five = { 5 };
	//вставка в конец
	myDeque.push_back(two);
	//ыставка в начало
	myDeque.push_front(one);
	myDeque.push_front(three);
	//вставка в конец
	myDeque.push_back(four);
	//вставка в произвольное место спомощью итератора 
	std::deque <std::list<int>>::iterator it = std::next(myDeque.begin(), 3);
	myDeque.insert(it, five);

	//вывод через итераторы
	for (std::list <int> list : myDeque) {
		for (int item : list) {
			std::cout << list.front() << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	myDequeTester();
}