#pragma once
#include "Dictionary.h"
#include "Rooms.h"
#include "Guests.h"
#include <vector>

class Node
{
public:
	Dictionary<Rooms,vector<Person>> data;
	vector<Node*> children;
	Node(Dictionary<Rooms, vector<Person>> data) : data(data) {};

	void DecisionTree(Rooms* rooms, Guests* guests)
	{

	}
};
