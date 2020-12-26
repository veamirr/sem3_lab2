#pragma once
#include <iostream>
using namespace std;

template<class T>
class BinaryTree
{
	struct Node
	{
		T data;
		Node* lchild;
		Node* rchild;

		Node(T dataNew)
		{
			data = dataNew;
			lchild = NULL;
			rchild = NULL;
		}
	};

private:
	Node* root;
	int size = 0;

	void Insert(T newData, Node*& theRoot, bool (*cmp)(T, T))
	{
		size++;
		if (theRoot == NULL)
		{
			theRoot = new Node(newData);
			return;
		}
		if (cmp(theRoot->data, newData) == true)
			Insert(newData, theRoot->lchild, cmp);
		else
			Insert(newData, theRoot->rchild, cmp);
	}

	void PrintTree(Node* theRoot)
	{
		if (theRoot)
		{
			PrintTree(theRoot->lchild);
			cout << theRoot->data << " ";
			PrintTree(theRoot->rchild);
		}
	}

	T Max(Node* theRoot)
	{
		while (theRoot->rchild != NULL) theRoot = theRoot->rchild;
		return theRoot->data;
	}

	bool Empty(Node* theRoot)
	{
		if (theRoot != NULL) return false;
		else return true;
	}

	void DeleteMax(Node* theRoot)
	{
		while (theRoot->rchild != NULL) theRoot = theRoot->rchild;
		if (theRoot->lchild == NULL) delete theRoot;
		else
		{
			//to be continued...
		}
	}
	void Delete(Node* theRoot)
	{
		if (theRoot == NULL) return;
		else
		{
			if (theRoot->rchild != NULL)
			{
				theRoot->data = theRoot->rchild->data;
				Delete(theRoot->rchild);
			}
			else if (theRoot->lchild != NULL)
			{
				theRoot->data = theRoot->lchild->data;
				Delete(theRoot->lchild);
			}
			else theRoot = NULL;
		}
	}

public:
	BinaryTree()
	{
		root = NULL;
	}
	void AddItem(T newData, bool (*cmp)(T, T))
	{
		Insert(newData, root, cmp);
	}
	void PrintTree()
	{
		PrintTree(root);
	}
	bool Empty()
	{
		return Empty(root);
	}
	T MaxElement()
	{
		return Max(root);
	}
	void DeleteMax()
	{
		DeleteMax(root);
	}
};
