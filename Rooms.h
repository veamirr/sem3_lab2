#pragma once
#include <vector>
using namespace std;

class Rooms
{
public:
	vector<int> triples;
	vector<int> doubles;
	vector<int> single;
public:
	Rooms(){}
	void Add(int room)
	{
		if (room / 100 == 3) triples.push_back(room);
		else if (room / 100 == 2) doubles.push_back(room);
		else single.push_back(room);
	}
	int TriplesNumber()
	{
		return triples.size();
	}
	int DoubleNumber()
	{
		return doubles.size();
	}
	int SinglesNumber()
	{
		return single.size();
	}
};