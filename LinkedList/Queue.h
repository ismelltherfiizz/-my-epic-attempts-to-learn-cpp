#pragma once
#include "MyLinkedList.h"


class Queue : private MyLinkedList
{
public:
	TYPE Front() const;
	void Pop();
	void Push(TYPE newValue);
	void Display() const;
	

};

