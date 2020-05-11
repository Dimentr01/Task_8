#include "BST.h"
#include <iomanip>
#include <iostream>

// Создать узел
BST* CreateNode(int value)
{
	auto node = new BST;
	node->key = value;
	node->Right = node->Left = nullptr;
	node->weight = rand() % 3 - 1;
	return node;
}

// Добавить элемент в дерево
BST* Insert(BST* root, int value)
{
	if (root == nullptr)
	{
		return CreateNode(value);
	}
	if (value < root->key)
	{
		root->Left = Insert(root->Left, value);
	}
	if(value > root->key)
	{
		root->Right = Insert(root->Right, value);
	}

	return root;
}

void InOrderPrintInternal(BST* root, int n)
{
	if (root != nullptr) {
		InOrderPrintInternal(root->Right, n+2);
		std::cout << std::setw(n * 3) << root->key << "(" << root->weight << ")" << std::endl;
		InOrderPrintInternal(root->Left, n + 2);
	}
}

// Печать дерева с Inorder обходом
void InOrderPrint(BST* root, int n)
{
	std::cout << "-----------------------------------------------" << std::endl;
	InOrderPrintInternal(root, n);
	std::cout << "-----------------------------------------------" << std::endl;
}

// Удалить элемент из дерева
BST* Remove(BST* root, int value)
{
	if (root == nullptr)
	{
		std::cout << "can not remove item " << value << std::endl;
		return root;
	}
	// если меньше
	if(value < root->key)
	{
		root->Left = Remove(root->Left, value);
	}
		
	// если больше
	else if (value > root->key)
	{
		root->Right = Remove(root->Right, value);
	}
		
	// если совпало
	else
	{
		//// если лист, удаляем спокойно
		if (root->Right == nullptr && root->Left == nullptr)
		{
			delete root;
			return nullptr;
		}
		// если один потомок или лист
		BST* returnItem; // на него подцепим предка
		if (root->Left == nullptr)
		{
			returnItem = root->Right;
			delete root;
			return returnItem;
		}
		if (root->Right == nullptr)
		{
			returnItem = root->Left;
			delete root;
			return returnItem;
		}
			
		// не позвело, 2 потомка
		// будем искать самый маленький справа
		BST* temp = root->Right;
		while (temp != nullptr && temp->Left != nullptr)
			temp = temp->Left;

		// обновляем
		root->key = temp->key;
		root->weight = temp->weight;
		// удаляем его
		root->Right = Remove(root->Right, temp->key);
	}
	// возвращаем после изменения
	return root;
}

// Вывести на экран листья с ненулевым весом
void PrintLeafsInternal(BST* root)
{
	if (root != nullptr) {
		if (root->Right == nullptr && root->Left == nullptr && root->weight >= 0)
		{
			std::cout << root->key << "(" << root->weight << ") ";
		}
		PrintLeafsInternal(root->Right);
		PrintLeafsInternal(root->Left);
	}
}

void PrintLeafs(BST* root)
{
	PrintLeafsInternal(root);
	std::cout << std::endl;
}
