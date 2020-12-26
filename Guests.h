#pragma once
#include <vector>
#include "Person.h"
using namespace std;

class Guests
{
public:
	vector<Person> couples;
	vector<Person> friends;
	vector<Person> others;
public:
	Guests(){}
	void AddPerson(Person person)
	{
		if (person.partner != NULL) couples.push_back(person);
		else if (person.friends.empty() == false) friends.push_back(person);
		else others.push_back(person);
	}
	void PrintCouples()
	{
		for (int i = 0; i < couples.size(); i++)
		{
			cout << couples[i].name << "\n";
		}
	}

};
