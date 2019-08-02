#pragma once
using TYPE = int; 


class MyLinkedList
{
protected:
	struct Node
	{
		TYPE value;
		Node* pNext;
	};
	Node* head;


public:
	MyLinkedList();
	MyLinkedList(const MyLinkedList &source);
	~MyLinkedList();
	MyLinkedList& operator=(const MyLinkedList& source);

	void PushFront(TYPE newValue);
	void PopFront();
	void PushBack(TYPE newValue);
	void PopBack();
	void RemoveByValue(TYPE value);
	void Insert(int index, TYPE newValue);
	virtual TYPE Get(int index) const;
	void Display() const;
	bool isHeadEmpty() const;
	
};


