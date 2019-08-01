// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLinkedList.h"
#include "Queue.h"

int main()
{
	MyLinkedList* List = new MyLinkedList();
	Queue* q = new Queue();
	q->Push(200);
	q->Push(150);
	q->Push(100);
	//q.Pop();

	List->PushFront(15);
	List->PushFront(45);
	List->PushFront(66);
	List->Insert(0, 666);
	List->PushBack(777);
	List->PushBack(888);
	List->PopBack();
	//List.Get(0);
	//List.PopFront();
	//List.RemoveByValue(15);
	List->Display();
	q->Display();
	//q.Display();
	//std::cout << List.Get(0) << std::endl << List.Get(1);
	std::cout << "front is : " << q->Front();
	delete List;
	delete q;
}

