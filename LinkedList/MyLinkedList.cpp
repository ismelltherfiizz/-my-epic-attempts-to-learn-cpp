#include "MyLinkedList.h"
#include <iostream>



OwnIterator::OwnIterator(ValueType* p) :
	p(p)
{

}

OwnIterator::OwnIterator(const OwnIterator& it) :
	p(it.p)
{

}

bool OwnIterator::operator!=(OwnIterator const& other) const
{
	return p != other.p;
}

bool OwnIterator::operator==(OwnIterator const& other) const
{
	return p == other.p;
}

bool OwnIterator::operator>(OwnIterator const& other) const
{
	return p>other.p;
}

bool OwnIterator::operator<(OwnIterator const& other) const
{
	return p<other.p;
}

const int& OwnIterator::operator*() const
{
	return p->value;
}

OwnIterator& OwnIterator::operator++()
{
	p = p->pNext;
	return *this;
}

MyLinkedList::MyLinkedList() 
{
	Node* ptr;
	ptr = head;
	head = nullptr;
}

MyLinkedList::MyLinkedList(const MyLinkedList& source)
{
	*this = source;
}

MyLinkedList& MyLinkedList::operator=(const MyLinkedList& source)
{
	if(this == &source)
	{
		return *this;
	}
	if (source.head)
	{
		Node* ptr;
		ptr = source.head;
		while (ptr != nullptr)
		{
			this->PushBack(ptr->value);
			ptr = ptr->pNext;
		}
	}
	return *this; //?
}



MyLinkedList::~MyLinkedList()
{
	Node* ptr;
	ptr = head;
	while (ptr != nullptr)
	{
		head = ptr->pNext;
		delete ptr;
		ptr = head;
	}
}

OwnIterator MyLinkedList::begin()
{
	if (head)
	{
		return head;
	}
}

OwnIterator MyLinkedList::end()
{
	Node* ptr;
	ptr = head;
	while (ptr->pNext != nullptr)
	{
		ptr = ptr->pNext;
	}
	if (ptr->pNext = nullptr)
	{
		return ptr;
	}

}

void MyLinkedList::PushFront(TYPE newValue)
{
	Node* newNode = new Node();
	newNode->value = newValue;
	newNode->pNext = head;
	head = newNode;
}

void MyLinkedList::PopFront()
{
	Node* ptr;
	ptr = head->pNext;
	delete head;
	head = ptr;
}

void MyLinkedList::PushBack(TYPE newValue)
{
	Node* ptr;
	Node* newNode = new Node();
	newNode->value = newValue;
	newNode->pNext = nullptr;

	ptr = head;
	if (head != nullptr)
	{
		while (ptr->pNext != nullptr)
		{
			ptr = ptr->pNext;
		}
		if (ptr->pNext == nullptr)
		{
			ptr->pNext = newNode;
		}
	}
	else head = newNode;

}

void MyLinkedList::PopBack()
{
	Node* ptr;
	ptr = head;
	while (ptr->pNext->pNext != nullptr)
	{
		ptr = ptr->pNext;
	}
	if (ptr->pNext->pNext == nullptr) {
		delete ptr->pNext;
		ptr->pNext = nullptr;
	}

}

void MyLinkedList::Insert(int index, TYPE newValue)
{
	Node* ptr;
	Node* newNode = new Node();
	newNode->value = newValue;
	ptr = head; 
	for (int i = 0; ptr != nullptr; i++) 
	{
		if (i == index) 
		{
			newNode->pNext = ptr->pNext;
			ptr->pNext = newNode;
			return;
		}
		ptr = ptr->pNext;
	}

}

void MyLinkedList::RemoveByValue(TYPE newValue)
{
	Node* ptr;
	Node* prevPtr;
	prevPtr = head;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->value == newValue)
		{
			if (ptr == head) 
			{
				head = ptr->pNext;
				delete ptr;
				return;
			}

			while (prevPtr != nullptr)
			{
				if (prevPtr->pNext->pNext == nullptr)
				{
					prevPtr->pNext = nullptr;
					delete ptr;
					return;
				}
				if (prevPtr->pNext == ptr)
				{
					prevPtr->pNext = ptr->pNext;
					delete ptr;
					return;
				}
				prevPtr = prevPtr->pNext;


			}

		}
		ptr = ptr->pNext;
	}
}
TYPE MyLinkedList::Get(int index)  const
{
	Node* ptr;
	if (head != nullptr)
	{
		ptr = head;
		for (int i = 0; ptr != nullptr; i++)
		{
			if (i == index) 
			{
				return ptr->value;
			}
			ptr = ptr->pNext;
		}
	}
	else
	{
		std::cout << "list is empty";
	}
		return -1;
}

void MyLinkedList::Display() const
{
	Node* ptr;
	ptr = head;
	while (ptr != nullptr) 
	{
		std::cout << ptr->value << " ";
		ptr = ptr->pNext;
	}
	std::cout << std::endl;

}

bool MyLinkedList::isHeadEmpty() const
{
	if (head == nullptr)
	{
		return true;
	}
	else return false;
}

