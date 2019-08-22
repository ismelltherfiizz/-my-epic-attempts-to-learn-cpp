// BinaryTreeUniquePtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>

using TYPE = int;


class Tree
{

	struct Node
	{
		std::vector<std::unique_ptr<Node>> children;
		TYPE data;
		int key;
	};
public:
	std::unique_ptr<Node> root;
	static int key_counter;

	bool Insert(std::unique_ptr<Node>& CurRoot, int Key)
	{
		if (CurRoot->key == Key)
		{
			///
			return true;
		}
		else
		{
			for (auto& El : CurRoot->children)
			{
				if (Insert(El, Key))
				{
					return true;
				}
			}
		}
		return false;
	}

	std::unique_ptr<Node>& SearchByData(TYPE data)
	{
		if (root != nullptr)
		{
			for (auto & el : root->children)
			{
				if (el->data = data)
				{
					return el;
				}
				else
				{
					
				}
			}
		}
		else
		{
			std::cout << "tree is nullptr";
		}
	}

	void Insert(TYPE data, std::unique_ptr<Node>& tree)
	{
		auto newNode = std::make_unique<Node>();
		newNode->data = data;
		newNode->key = key_counter++;
		if (tree == nullptr)
		{
			tree = std::move(newNode);
			std::cout << "tree initialized" << std::endl;
		}
		else
		{
			tree->children.emplace_back(newNode);
		}
	}


};

int Tree::key_counter = 0;

int main()
{

}

