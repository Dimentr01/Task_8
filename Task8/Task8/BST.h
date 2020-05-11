#pragma once

struct BST
{
	int key;
	int weight;
	BST* Left;
	BST* Right;
};

// Создать узел
BST* CreateNode(int value);

// Добавить элемент в дерево
BST* Insert(BST* root, int value);

// Печать дерева с Inorder обходом
void InOrderPrint(BST* root, int n);

// Удалить элемент из дерева
BST* Remove(BST* root, int value);

// Вывести на экран листья с ненулевым весом
void PrintLeafs(BST* root);