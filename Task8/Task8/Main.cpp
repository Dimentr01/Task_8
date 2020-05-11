#include <iostream>
#include <ctime>
#include "BST.h"

void TestBST()
{
	BST* tree = nullptr;

	tree = Insert(tree, 8);
	tree = Insert(tree, 4);
	tree = Insert(tree, 10);
	tree = Insert(tree, 20);
	tree = Insert(tree, 7);
	tree = Insert(tree, 3);
	tree = Insert(tree, 5);
	tree = Insert(tree, 6);


	InOrderPrint(tree, 2);
	PrintLeafs(tree);
	Remove(tree, 4);

	InOrderPrint(tree, 2);
	PrintLeafs(tree);
}

BST* Initialize(BST* tree)
{
	for (int i = 0; i < rand()%5 + 10; i++)
	{
		tree = Insert(tree, rand() % 25);
	}
	return tree;
}

void menu(BST* tree)
{
	int menuItem;
	
	while(true)
	{
		std::cout << "1 - Add element" << std::endl;
		std::cout << "2 - Remove element" << std::endl;
		std::cout << "3 - Print tree" << std::endl;
		std::cout << "4 - Print leafs" << std::endl;
		std::cout << "0 - Exit" << std::endl;

		std::cin >> menuItem;
		
		if (menuItem == 0)
			break;
		switch (menuItem)
		{
		case 1:
			int elementInsert;
			std::cout << "Input element for insert" << std::endl;
			std::cin >> elementInsert;
			tree = Insert(tree, elementInsert);
			break;
		case 2:
			int elementRemove;
			std::cout << "Input element for remove" << std::endl;
			std::cin >> elementRemove;
			tree = Remove(tree, elementRemove);
			break;
		case 3:
			InOrderPrint(tree, 2);
			break;
		case 4:
			PrintLeafs(tree);
			break;
		default:
			break;
		}
	}
	
}

int main()
{
	std::srand(unsigned(std::time(0)));
	BST* tree = nullptr;
	tree = Initialize(tree);
	
	menu(tree);

	return 0;
}

