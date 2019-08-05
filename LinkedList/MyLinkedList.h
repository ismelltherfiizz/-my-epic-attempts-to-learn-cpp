#pragma once
#include "OwnIterator.h"
using TYPE = int; 

	struct Node
	{
		TYPE value;
		Node* pNext;


		//friend bool operator ==(const Node& l, const Node& r) { return l.value == r.value; }

	};


	using ValueType = Node;

	class OwnIterator : public std::iterator<std::input_iterator_tag, ValueType>
	{
		friend class MyLinkedList;
	private:
	public:
		OwnIterator(const OwnIterator& it);
		OwnIterator(ValueType* p);
		OwnIterator() = default;
		bool operator!=(OwnIterator const& other) const;
		bool operator==(OwnIterator const& other) const; //need for BOOST_FOREACH
		bool operator>(OwnIterator const& other) const;
		bool operator<(OwnIterator const& other) const;

		friend bool operator>(OwnIterator const& left, OwnIterator const& right)  { return left->value > right->value; }
		friend bool operator<(OwnIterator const& left, OwnIterator const& right)  { return left->value < right->value; }

//		friend bool operator-(OwnIterator const& left, OwnIterator const& right) { return left-> < right->value; }



		Node* operator->() { return p; }
		const Node* operator->() const { return p; }


		const int& operator*() const;
		OwnIterator& operator++();
	private:
		ValueType* p;
	};



class MyLinkedList
{
protected:
	Node* head;

public:
	MyLinkedList();
	MyLinkedList(const MyLinkedList &source);
	~MyLinkedList();
	MyLinkedList& operator=(const MyLinkedList& source);


	OwnIterator iterator{head};
	OwnIterator const_iterator{ head };

	OwnIterator begin();
	OwnIterator end();

	OwnIterator begin() const;
	OwnIterator end() const;

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


