#include <iostream>

using TYPE = int;

struct Node
{
	TYPE value;
	Node* leftChild;
	Node* rightChild;

};

void InsertInternal(Node* newNode, Node* tree) //Dima skazal chto tipy < 8 bajt kopirovat' bystree, chem brat' na nich ssylku
{

	if (tree->value < newNode->value)
	{
		if (tree->rightChild != nullptr)
		{
			InsertInternal(newNode, tree->rightChild);
		}
		else
		{
			tree->rightChild = newNode;
			std::cout << newNode->value << " node added to the right" << std::endl;
		}
	}
	else
	{
		if (tree->leftChild != nullptr)
		{
			InsertInternal(newNode, tree->leftChild);
		}
		else
		{
			tree->leftChild = newNode;
			std::cout << newNode->value << " node added to the left" << std::endl;
		}
	}
}

void Insert(TYPE value, Node*& tree)
{
	Node* newNode = new Node;
	newNode->value = value;
	newNode->leftChild = nullptr;
	newNode->rightChild = nullptr;

	if (tree == nullptr)
	{
		tree = newNode;
		std::cout << "tree initialized" << std::endl;
	}
	else
	{
		InsertInternal(newNode, tree);
	}

}

void ShowPreOrder(Node* tree)
{
	if (tree != nullptr)
	{
		std::cout << tree->value << std::endl;
		ShowPreOrder(tree->leftChild);
		ShowPreOrder(tree->rightChild);
	}
}

void ShowInOrder(Node* tree)
{
	if (tree != nullptr)
	{
		ShowInOrder(tree->leftChild);
		std::cout << tree->value << std::endl;
		ShowInOrder(tree->rightChild);
	}
}

void ShowPostOrder(Node* tree)
{
	if (tree != nullptr)
	{
		ShowPostOrder(tree->leftChild);
		ShowPostOrder(tree->rightChild);
		std::cout << tree->value << std::endl;
	}
}

void DeleteWithChildren(Node*& tree) //chto eta funkciya delaet takogo, chto esli argumentom budet "Node* tree" obhody ne budut rabotat'?
{						//Ponyal: sozdaet ukazatel', kotoryj ukazyvaet na tot zhe ob"ekt, potom udalyaet etot ob"ekt i obnulyaet ukazatel'-kopiyu, no ne obnulyaet ishodnyi ukazatel'
	if (tree != nullptr) //poetomu kogda funkciya obhoda na n-oj iteracii pytaetsya vytashchit' infu s pomoshch'yu etogo ukazatelya vyletaet error (konkretnee - read access violation, ibo pamyat' byla osvobozhdena i programma ne imeet prav eyo yuzat')
	{
		DeleteWithChildren(tree->leftChild);
		DeleteWithChildren(tree->rightChild);
		delete tree;
		tree = nullptr;
	}
}


int main()
{
	Node* TREE = nullptr;
	Node* tree1 = nullptr;
	Insert(25, TREE);
	Insert(15, TREE);
	Insert(10, TREE);
	Insert(4, TREE);
	Insert(5, TREE);
	Insert(6, TREE);
	Insert(12, TREE);
	Insert(22, TREE);
	Insert(18, TREE);
	Insert(50, TREE);
	Insert(24, TREE);
	Insert(35, TREE);
	Insert(31, TREE);
	Insert(44, TREE);
	Insert(70, TREE);
	Insert(66, TREE);
	Insert(90, TREE);
	DeleteWithChildren(TREE->leftChild);
	std::cout << "---------------------INORDER------------------" << std::endl;
	ShowInOrder(TREE);
	std::cout << "-----------------------PREORDER----------------" << std::endl;
	ShowPreOrder(TREE);
	std::cout << "-----------------------POSTORDER---------------" << std::endl;
	ShowPostOrder(TREE);
}

