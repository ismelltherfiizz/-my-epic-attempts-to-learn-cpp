#pragma once
using TYPE = int; 


class MyLinkedList
{
private:
	struct Node {
		TYPE value;
		Node* pNext;
	};

public:
	Node* head;
	MyLinkedList();
	void PushFront(TYPE newValue);
	void PopFront();
	void PushBack(TYPE newValue);
	void PopBack();
	void RemoveByValue(TYPE value);
	void Insert(int index, TYPE newValue);
	virtual TYPE Get(int index) const;
	void Display() const;
	
protected:
	bool isHeadEmpty() const;
	
};


