#pragma once
#include "BinaryTree.h"
#include <queue>
using namespace std;

template <class T, bool (*cmp)(T, T)>
class PriorityQueue
{
	BinaryTree<T> btree;

public:
	PriorityQueue(){}

	void push(T newData)
	{
		btree.AddItem(newData, cmp);
	}
	T front()
	{
		return btree.MaxElement();
	}
	void pop()
	{
		btree.DeleteMax();
	}
	bool empty()
	{
		return btree.Empty();
	}
	void print()
	{
		btree.PrintTree();
	}
};