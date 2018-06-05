#include <iostream>
#include <string>
#include <memory>
#include "LinkedList.h"

std::shared_ptr<LinkedList<int>> someList(int n1, int n2, int n3) {
	auto temp = new LinkedList<int>;
	std::shared_ptr<LinkedList<int>> ptr(temp);

	temp->add(n1);
	temp->add(n2);
	temp->add(n3);

	return ptr;
}

LinkedList<int> someListTwo(int n1, int n2, int n3) {
	
	LinkedList<int> temp;

	temp.add(n1);
	temp.add(n2);
	temp.add(n3);

	return temp;
}

int main() {
	
	//#define  loop
#ifdef loop
	while (true) {

		LinkedList<int> list;
		LinkedList<std::string> stringList;

		LinkedList<int> rand(list);

		list.add(13);
		list.add(42);
		list.add(69);

		stringList.add("Word");
		stringList.add("Caster class");
		stringList.add("Lorem Inpsum");
		stringList.add("Moist von Lipwig");
		stringList.add("Going Postal");

		LinkedList<int> copyList;
		copyList(*someList(9, 7, 5));

		LinkedList<int> testList;

		testList = someListTwo(13, 42, 69);

	for (auto element : testList)
	{
		std::cout << element << std::endl;
	}

		for (auto iter = copyList.begin(); iter != copyList.end(); ++iter) {
			std::cout << *iter << std::endl;
		}

		std::cout << copyList.size() << std::endl;

		std::cout << list.size() << std::endl;

		std::cout << stringList.size() << std::endl;

		for (LinkedList<int>::Iterator iter = list.begin(); iter != list.end(); iter++) {
			std::cout << *iter << std::endl;
		}
		for (auto iter = stringList.begin(); iter != stringList.end(); iter++) {
			std::cout << *iter << std::endl;
		}

		for (auto num : copyList)
		{
			std::cout << num << std::endl;
		}
		for (auto& num : copyList)
		{
			num = 0;
		}
		for (auto num : copyList)
		{
			std::cout << num << std::endl;
		}

		for (auto num : list)
		{
			std::cout << num << std::endl;
		}

	}
#endif
#ifndef loop
	
	LinkedList<int> list;
	LinkedList<std::string> stringList;

	LinkedList<int> rand(list);

	list.add(13);
	list.add(42);
	list.add(69);

	stringList.add("Word");
	stringList.add("Caster class");
	stringList.add("Lorem Inpsum");
	stringList.add("Moist von Lipwig");
	stringList.add("Going Postal");

	LinkedList<int> copyList;
	copyList(*someList(9, 7, 5));

	LinkedList<int> testList;

	testList = someListTwo(13, 42, 69);

	for (auto element : testList)
	{
		std::cout << element << std::endl;
	}

	for (auto iter = copyList.begin(); iter != copyList.end(); ++iter) {
		std::cout << *iter << std::endl;
	}

	std::cout << copyList.size() << std::endl;

	std::cout << list.size() << std::endl;

	std::cout << stringList.size() << std::endl;

	for (LinkedList<int>::Iterator iter = list.begin(); iter != list.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	for (auto iter = stringList.begin(); iter != stringList.end(); iter++) {
		std::cout << *iter << std::endl;
	}

	for (auto num : copyList)
	{
		std::cout << num << std::endl;
	}
	for (auto& num : copyList)
	{
		num = 0;
	}
	for (auto num : copyList)
	{
		std::cout << num << std::endl;
	}

	for (auto num : list)
	{
		std::cout << num << std::endl;
	}
	system("pause");


	return 0;
#endif
}
	
