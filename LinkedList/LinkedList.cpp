// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLinkedList.h"
#include "Queue.h"

#include <algorithm>
#include <list>

int main()
{
	std::list<int> l;

	MyLinkedList List;
	MyLinkedList List1;
	Queue* q = new Queue();
	q->Push(200);
	q->Push(150);
	q->Push(100);
	//q.Pop();
	List.PushFront(15);
	List.PushFront(45);
	List.PushFront(66);
	List.Insert(0, 666);
	List.PushBack(777);
	List.PushBack(888);
	List.PopBack();
	//List.Insert(4, 1000);
	List1 = List;
	//List1.PushFront(999);
	//List.Get(0);
	//List.PopFront();
	List.Display();
	List1.Display();
	q->Display();
	//q.Display();
	//std::cout << List.Get(0) << std::endl << List.Get(1);
	std::cout << "front is : " << q->Front() << std::endl;
	//delete List;

	


	int n1 = 15;
	auto findResult = std::find(List.begin(), List.end(), n1);
	if(findResult != nullptr)
	{
		std::cout << "list does have " << n1 << '\n';
	}
	else
	{
		std::cout << "list doesn't have " << n1 << '\n';
	}
	delete q;
}

