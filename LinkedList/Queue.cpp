#include "Queue.h"
#include <iostream>


TYPE Queue::Front() const
{
		return head->value;
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
