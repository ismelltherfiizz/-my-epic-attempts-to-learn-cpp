// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLinkedList.h"
#include "Queue.h"

#include <algorithm>
#include <list>
#include "ListDerived.h"
#include <new>
#include <vector>
#include "Vector.h"
int main()
{
	Vector<int>* v = new Vector<int>;
	Vector<int>* v1 = new Vector<int>;
	Vector<int> v2;
	Vector<int> v3;
	//Vector<int> v;
	v2.pushBack(666);
	v2.pushBack(777);
	v2.pushBack(888);
	v3.pushBack(0);
	v->pushBack(666);
	v->pushBack(777);
	v->pushBack(888);
	v->popBack();
	*v1 = *v;
	//v->pushBack(999);
	//v->pushBack(1000);
	v1->pushBack(999);

	v3 = v2;
	//v2.swap(v3);
	//v->swap(*v1);
	Vector<int>::Iterator it = v1->rBegin();
	v1->insert(it - 4, 1000);
	//v1->erase(it);
	//v->assign(it, it+3);
	cout << v->maxSize() << endl;
	for (int i = 0; i < v->getSize(); i++)
	{
		std::cout << (*v)[i] << endl;
	}
	for (int i = 0; i < v1->getSize(); i++)
	{
		std::cout << (*v1)[i] << endl;
	}

	std::cout << endl;

	//for (int i = 0; i < v2.getSize(); i++)
	//{
	//	std::cout << v2[i] << endl;
	//}
	/*
	for (int i = 0; i < v3.getSize(); i++)
	{
		std::cout << v3[i] << endl;
	}*/
}