// BinaryTreeUniquePtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>

template<class T>
class Tree
{
	struct Node
	{
		std::vector<std::unique_ptr<Node>> children;
		T data;
		const int key;
		Node()
		{}
		Node(T data, const int key) : data(data), key(key)
		{}
		Node(const int key) : key(key)
		{}
	};
public:
	std::unique_ptr<Node> root;
	std::unique_ptr<Node> nothing;

	std::unique_ptr<Node>& FindByKey(std::unique_ptr<Node>& curRoot, const int key)
	{
		if (curRoot->key == key)
		{
			return curRoot;
		}
		else
		{
			for (auto& el : curRoot->children)
			{
				auto& n = FindByKey(el, key);
				if (n)
				{
					std::cout << "root was found" << std::endl;
					return n;
				}
			}
			return nothing;
		}
	}

	void InsertByRoot(T data, const int key, std::unique_ptr<Node>& curRoot)
	{
		auto newNode = std::make_unique<Node>(data, key);
		if (root == nullptr)
		{
			root = std::move(newNode);
			std::cout << "tree initialized" << std::endl;
		}
		else
		{
			auto& a = FindByKey(root, key);
			if (!a)
			{
				curRoot->children.emplace_back(std::move(newNode));
			}
			else 
			{
				std::cout << "the key already exists" << key << std::endl;
			}
		}
	}

	void InsertByKey(T data, const int newKey, const int parentKey)
	{
		auto newNode = std::make_unique<Node>(data, newKey);

		if (root == nullptr)
		{
			root = std::move(newNode);
			std::cout << "tree initialized" << std::endl;
		}
		else
		{
			auto& a = FindByKey(root, parentKey);
			if (newKey != parentKey)
			{
			if (!a)
			{
				std::cout << "there's no such parent key : " << parentKey <<std::endl;
				return;
			}

				auto& b = FindByKey(root, newKey);
				if (b)
				{
					std::cout << "the key already exists : " << newKey << std::endl;
					std::cout << "Do you want to change the value?" << std::endl;
					std::string answer;
					std::cin >> answer;
					if (answer == "y")
					{
						b->data = data;
						std::cout << "value has changed" << std::endl;
					}
				}
				else
				{
					std::cout << "the parent key exists " << newKey << std::endl;
					a->children.emplace_back(std::move(newNode));
				}
			}
			else
			{
				a->data = data;
			}
		}
	}


	void Show(std::unique_ptr<Node>& curRoot)
	{
		if (curRoot)
		{
			std::cout << "data = " << curRoot->data << "; key = " << curRoot->key << std::endl;

			if (!curRoot->children.empty())
			{
				for (auto& el : curRoot->children)
				{
					Show(el);
				}
			}
		}
	}
	
	void DeleteInternal(std::unique_ptr<Node>& curRoot)
	{
		std::cout << "deleted a node" << std::endl;
		curRoot.reset();
	}


	void DeleteByKey(const int key)
	{
		auto& curRoot = FindByKey(root, key); 
		if (!curRoot)
		{
			std::cout << "there's no such key" << std::endl;
		}
		else
		{
			for (size_t i = 0; i < curRoot->children.size(); i++)
			{
				DeleteInternal(curRoot->children[i]);
			}
			curRoot.reset();
			std::cout << "deleted a node" << std::endl;
		}
	}

	void DeleteByRoot(std::unique_ptr<Node>& curRoot)
	{
		for (size_t i = 0; i < curRoot->children.size(); i++)
		{
			DeleteInternal(curRoot->children[i]);
		}
		curRoot.reset();
		std::cout << "deleted a node" << std::endl;
	}
};




int main()
{
	Tree<int> myTree;
 	myTree.InsertByRoot(111, 1, myTree.root);
	myTree.InsertByKey(0, 0, 1);
	myTree.InsertByRoot(666, 22, myTree.root);
	myTree.InsertByRoot(999, 11, myTree.root);
	myTree.InsertByKey(555, 666, 1);
	myTree.InsertByKey(51515, 1, 1);
	//myTree.DeleteByKey(1);
	myTree.Show(myTree.root);

}

