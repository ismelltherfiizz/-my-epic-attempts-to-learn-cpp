// allocator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <io.h>
#define memorySize 1000000

char memory[memorySize];
void* memoryPtr = memory;
void* memoryPtrEnd = memory + memorySize;

struct Block
{

	size_t size;
	bool isFree;
	Block* nextBlock;

};


Block* freeList = static_cast<Block*>(memoryPtr);

void init()
{
	freeList->size = memorySize - sizeof(Block);
	freeList->isFree = true;
	freeList->nextBlock = nullptr;
}

void split(Block* fittingBlock, size_t size)
{
	Block* newBlock = fittingBlock + size + sizeof(Block);
	newBlock->size = fittingBlock->size - size - sizeof(Block);
	newBlock->isFree = true;
	newBlock->nextBlock = fittingBlock->nextBlock;
	fittingBlock->size = size;
	fittingBlock->isFree = false;
	fittingBlock->nextBlock = newBlock;
}


void* myMalloc(size_t size)
{
	Block* curBlock, *prevBlock;
	if (!(freeList->size))
	{
		init();
		std::cout << "Memory initialized" << std::endl;
	}
	curBlock = freeList;
	while ((curBlock->size < size) || (curBlock->isFree == false) && (curBlock->nextBlock != nullptr))
	{
		prevBlock = curBlock;
		curBlock = curBlock->nextBlock;
		std::cout << "block checked" << std::endl;
	}
	if (curBlock->size == size)
	{
		curBlock->isFree = false;
		std::cout << "exact fitting block allocated" << std::endl;
		return ++curBlock;
	}

	else if (curBlock->size > size + sizeof(Block))
	{
		split(curBlock, size);
		std::cout << "fitting block allocated with a split" << std::endl; 
		return ++curBlock;
	}
	else
	{
		std::cout << "not enough memory to allocate" << std::endl;
		return nullptr;
	}

}


void merge()
{
	Block* curBlock, *prevBlock;
	curBlock = freeList;
	while ((curBlock->nextBlock) != nullptr)
	{
		if ((curBlock->isFree) && (curBlock->nextBlock->isFree))
		{
			curBlock->size += (curBlock->nextBlock->size) + sizeof(Block);
			curBlock->nextBlock = curBlock->nextBlock->nextBlock;
		}
		prevBlock = curBlock->nextBlock;
		
		if (curBlock->nextBlock != nullptr) curBlock = curBlock->nextBlock;
		else return;
	}
}


void myFree(void* ptr)
{
	if (memoryPtr <= ptr && ptr <= memoryPtrEnd)
	{
		Block* curBlock = static_cast<Block*>(ptr);
		--curBlock;
		curBlock->isFree = true;
		merge();
		std::cout << "block is freed" << std::endl;
	}
	else std::cout << "provide a valid pointer" << std::endl;
}

void* myRealloc(void* ptr, size_t new_size)
{
	if (ptr != nullptr)
	{
		Block* curBlock = (Block*)ptr;
		--curBlock;
		curBlock->isFree = true;
		if (curBlock->size + curBlock->nextBlock->size >= new_size && curBlock->nextBlock->isFree)
		{
			merge();
			split(curBlock, new_size);
			std::cout << "realloc completed (expanded)" << " size is " << curBlock->size << std::endl;
			return ++curBlock;
		}
		else if (curBlock->size > new_size)
		{
			split(curBlock, new_size);
			std::cout << "realloc completed (contracted)" << " size is " << curBlock->size << std::endl;
			return ++curBlock;
		}
		else
		{
			Block* newBlock = (Block*)myMalloc(new_size);
			memcpy(newBlock, ++curBlock, (curBlock-1)->size);
			myFree(curBlock);
			std::cout << "realloc completed (new memory block allocated)" << " size is " << (newBlock-1)->size << std::endl;
			return newBlock;
		}
	}
	else return myMalloc(new_size);
}
int main()
{
	int oldSize = 16;

	int* arr = static_cast<int*>(myMalloc(sizeof(int) * oldSize));
	int* arr1 = (int*)myMalloc(sizeof(int) * 5);
	for (int i = 0; i < oldSize; i++)
	{
		arr[i] = i;
		std::cout << arr[i] << std::endl;
	}
	myFree(arr1);
	int newSize = 20;
	arr = (int*)myRealloc(arr, sizeof(int)*newSize);
	
	for (int i = 0; i < newSize; i++)
	{
		//arr[i] = i;
		std::cout << arr[i] << std::endl;
	}


}
