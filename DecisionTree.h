#pragma once
#include "Guests.h"
#include "Rooms.h"
#include "Dictionary.h"
#include "Person.h"
#include <vector>
using namespace std;

class Node
{
public:
	Dictionary<int, Person> data;
	vector<Node*> children;
	int cost = 0;
	Node(Dictionary<int, Person> data)
	{
		this->data = data;
	}
	Node(Dictionary<int, Person> data, int cost)
	{
		this->data = data;
		this->cost = cost;
	}
	Node() {};
};
