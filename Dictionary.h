#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>
using namespace std;

template <class T, class U>
class Dictionary
{
	vector<pair<T, U>> element;
public:
	Dictionary() {};

	Dictionary(initializer_list<pair<T, U>> store)
	{
		for (pair<T, U> object : store) element.push_back(object);
	}

	void Add(T key, U value)
	{
		element.push_back(make_pair(key,value));
	}

	void Print()
	{
		for (int i = 0; i < element.size(); i++)
		{
			cout << element[i].first << " " << element[i].second << "\n";
		}
	}

	int search(T key)
	{
		int j = 0;
		for (int i = 0; i < element.size(); i++)
		{
			if (element[i].first == key) j++;
		}
		return j;
	}

	U operator[] (T key)
	{
		for (int i = 0; i < element.size(); i++)
		{
			if (element[i].first == key) return element[i].second;
		}
	}


};