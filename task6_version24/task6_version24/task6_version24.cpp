#include <iostream>
#include <deque>
#include <list>
#include <vector>

void myDequeTester() { //задача 1
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

void thinOutTheVector() {	//задача 2 "Проредить vector tepm относительно vector values"
	
	std::vector <int> temp = { 1,2,3,1,42,38,5,6,5,80,60 };
	std::vector <int> values = { 1,2,42,38 };
	for (std::vector <int>::iterator it = temp.begin(); it != temp.end(); ++it)
	{
		if (std::find(values.begin(), values.end(), *it) == values.end()) {
			if (it != temp.begin())
				temp.erase(it--); // если элемент не первый, то итератор на предыдущий элемент остается валидным
			else
			{
				temp.erase(it); // удалепние 1-го элемента
				it = temp.begin(); // восстанавливаем итератор
			}
		}
	}
	for (int item_temp : temp) {
		std::cout << item_temp << " ";
	}
}

int main()
{
	//myDequeTester();	
	thinOutTheVector();
}