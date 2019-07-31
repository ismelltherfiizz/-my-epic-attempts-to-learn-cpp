#pragma once
using TYPE = int;

struct Node{
	TYPE value;
	Node* pNext;
}; 


class MyLinkedList
{
public:

	void Push(TYPE value);
	void Pop();
	void RemoveByValue(TYPE value);
	void Insert(int index, TYPE value);
	TYPE Get(int index);
	void Display();
};


