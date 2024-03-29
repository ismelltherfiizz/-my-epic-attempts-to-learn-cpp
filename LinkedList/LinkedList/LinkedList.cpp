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
	Vector<int> v4{ 1, 2, 3, 4, 5 };
	//Vector<int> v;
	v2.pushBack(666);
	v2.pushBack(777); 
	v2.pushBack(888);
	v->pushBack(666);
	v->pushBack(777);
	v->pushBack(888);
	*v1 = *v;
	//v->pushBack(999);
	//v->pushBack(1000);
	v1->pushBack(999);
	v3 = { 1, 2, 3 };
	//v2.swap(v3);
	//v->swap(*v1);
	Vector<int>::Iterator it = v1->rEnd();
	//v1->insert(it - 4, 1000);
	v1->erase(it+1);
	//v->assign(it, it+3);
	cout << v->maxSize() << endl;
	std::cout << "v:" <<endl;
	for (size_t i = 0; i < v->getSize(); i++)
	{
		std::cout << (*v)[i] << endl;
	}
	std::cout << "v1:" << endl;
	for (size_t i = 0; i < v1->getSize(); i++)
	{
		std::cout << (*v1)[i] << endl;
	}

	//std::cout << "v2:" << endl;

	//for (int i = 0; i < v2.getSize(); i++)
	//{
	//	std::cout << v2[i] << endl;
	//}
	
	std::cout << "v3:" <<endl;
	for (size_t i = 0; i < v3.getSize(); i++)
	{
		std::cout << v3[i] << endl;
	}


	std::cout << "v4:" << endl;

for (size_t i = 0; i < v4.getSize(); i++)
{
	std::cout << v4[i] << endl;
}
}