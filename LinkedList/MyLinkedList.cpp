#include "MyLinkedList.h"
#include <corecrt_malloc.h>
#include <iostream>

Node* head = nullptr;

void MyLinkedList::Push(TYPE newValue)
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->value = newValue;
	newNode->pNext = head;
	head = newNode;
}

void MyLinkedList::Pop()
{
	Node* tempPtr;
	tempPtr = head->pNext;
	free(head);
	head = tempPtr;
}

void MyLinkedList::Insert(int index, TYPE value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* ptr;
	newNode->value = value;
	ptr = head; 
	for (int i = 0; ptr != nullptr; i++) {
		if (i == index) {
			newNode->pNext = ptr->pNext;
			ptr->pNext = newNode;
		}
		ptr = ptr->pNext;
	}

}

void MyLinkedList::RemoveByValue(TYPE value)
{
	Node* ptr;
	Node* prevPtr;
	prevPtr = head;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->value == value)
		{
			if (ptr == head) 
			{
				head = ptr->pNext;
				free(ptr);
				return;
			}

			while (prevPtr != nullptr)
			{
				if (prevPtr->pNext->pNext == nullptr)
				{
					prevPtr->pNext = nullptr;
					free(ptr);
					return;
				}
				if (prevPtr->pNext == ptr)
				{
					prevPtr->pNext = ptr->pNext;
					free(ptr);
					return;
				}
				prevPtr = prevPtr->pNext;


			}

		}
		ptr = ptr->pNext;
	}
}
TYPE MyLinkedList::Get(int index)
{
	Node* ptr;
	ptr = head;
	for (int i = 0; ptr != nullptr; i++) {
		if (i == index) {
			return ptr->value;
		}
		ptr = ptr->pNext;
	}
}

void MyLinkedList::Display() {
	 Node* ptr;
	ptr = head;
	while (ptr != nullptr) {
		std::cout << ptr->value << " ";
		ptr = ptr->pNext;
	}
}
