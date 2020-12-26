#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "ArraySequence.h"
using namespace std;

class Person 
{
public:
	string name;
	Person* partner;
	vector<Person*> friends;
	vector<Person*> haters;
public:
	Person()
	{
		//this->name = name;
		this->partner = NULL;
	}
	Person(string name)
	{
		this->name = name;
		this->partner = NULL;
	}
	void add_partner(Person* partner)
	{
		this->partner = partner;
		partner->partner = this;
	}
	void add_friend(Person* friends)
	{
		this->friends.push_back(friends);
		friends->friends.push_back(this);
	}
	//void add_hater(Person* haters)
	//{
	//	this->haters.push_back(haters);
	//	haters->haters.push_back(this);
	//}
	friend ostream& operator << (ostream &out, const Person &p)
	{
		return out << p.name;
	}
	//bool operator== (const Person a, const Person b)
	//{
	//	return (a.name == b.name);
	//}
};

bool operator== (const Person a, const Person b)
{
	return (a.name == b.name);
}


