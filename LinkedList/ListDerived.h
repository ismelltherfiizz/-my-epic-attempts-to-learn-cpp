#pragma once
#include "MyLinkedList.h"
#include "Base.h"
class ListDerived :
	public MyLinkedList, virtual public Base
{
public:
	typedef void (ListDerived::* funcPtr) ();

};

