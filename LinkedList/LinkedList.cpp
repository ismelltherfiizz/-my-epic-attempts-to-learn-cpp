// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLinkedList.h"
#include "Queue.h"

#include <algorithm>
#include <list>
#include "ListDerived.h"
#include <new>
#include "Vector.h"
int main()
{
	Vector<int>* v = new Vector<int>;
	//Vector<int> v;
	v->pushBack(666);
	v->pushBack(777);
	v->pushBack(888);
	for (int i = 0; i < v->getSize(); i++)
	{
		std::cout << (*v)[i] << endl;
	}
}
