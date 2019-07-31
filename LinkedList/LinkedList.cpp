// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLinkedList.h"

int main()
{
	MyLinkedList List;
	List.Push(15);
	List.Push(45);
	List.Push(66);
	List.Insert(0, 666);
	//List.Pop();
	//List.RemoveByValue(15);
	List.Display();
	//std::cout << List.Get(0) << std::endl << List.Get(1);
}

