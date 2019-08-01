#include "Queue.h"
#include <iostream>


TYPE Queue::Front() const
{
	if (!MyLinkedList::isHeadEmpty()) 
	{
		return head->value;
	}
	else std::cout << "queue is empty";
}


void Queue::Pop()
{
	MyLinkedList::PopFront();
}

void Queue::Push(TYPE newValue)
{
	MyLinkedList::PushBack(newValue);

}

void Queue::Display() const
{
	MyLinkedList::Display();
}
