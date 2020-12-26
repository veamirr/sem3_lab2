#include <iostream>
#include "Person.h"
#include "Guests.h"
#include "Dictionary.h"
#include "Rooms.h"
#include "DecisionTree.h"
#include <queue>
#include <map>
using  namespace std;

//priority_queue < pair<int, Node>, vector<pair<int, Node>>, greater<pair<int, Node>>> acc;
Dictionary<int, Person> d;
Node min_cost(d, 0);

void CreateDecision(vector<int> rooms, vector<Person> guests, int i, Node node)
{
	if (guests[i].partner != NULL)
	{
		int j = 0;
		while ((j < rooms.size()) && (rooms[j] / 100 != 1))
		{
			Node child(node.data, node.cost);
			child.data.Add(rooms[j], guests[i]);
			child.data.Add(rooms[j], guests[i + 1]);
			child.cost = child.cost + (rooms[j] / 100 * 1000);
			//child.data.Print();
			node.children.push_back(&child);
			//cout << node.children.size() << "\n";

			vector<int> free_rooms;
			for (int k = 0; k < rooms.size(); k++) free_rooms.push_back(rooms[k]);
			free_rooms.erase(free_rooms.begin() + j);
			//for (int k = 0; k < free_rooms.size(); k++) cout << free_rooms[k] << "\n";

			if (i < (guests.size() - 2))
			{
				int new_i = i + 2;
				CreateDecision(free_rooms, guests, new_i, child);
			}
			else
			{
				child.data.Print();
				cout << "\n" << "Cost :" << child.cost;
				cout << "\n" << "\n";
				//acc.push(make_pair(child.cost, child));
				if ((child.cost < min_cost.cost) || (min_cost.cost == 0))
				{
					min_cost.cost = child.cost;
					min_cost.data = child.data;
				}
			}
			j++;
		    //cout << "YES\n";
		}
	}
	//if (guests[i].friends.size() != 0)
	else
	{
		int j = 0;
		while (j < rooms.size())
		{
			int key = 0;
			if ((node.data.search(rooms[j]) > 0) && (node.data.search(rooms[j]) < (rooms[j] / 100)))//те в комнате кто-то живет
			{
				//cout << "YES\n";
				for (int k = 0; k < guests[i].friends.size(); k++)
					if (guests[i].friends[k]->name == node.data[rooms[j]].name)
					{
						//cout << "YES we have friends\n";
						key = 1;
						break;
					}
			}
			if ((key == 1) || (node.data.search(rooms[j]) == 0))//в комнате пока никто не живет
			{
				Node child(node.data, node.cost);
				child.data.Add(rooms[j], guests[i]);
				child.cost = child.cost + (rooms[j] / 100 * 1000);
				vector<int> free_rooms;
				//if (node.data.search(rooms[j]) == (rooms[j] / 100)) cout << "YES WE DELETE\n";
				//cout << node.data.search(rooms[j]) << " ";
				if ((rooms[j] / 100 == 1))
				{
					for (int k = 0; k < rooms.size(); k++) free_rooms.push_back(rooms[k]);
					free_rooms.erase(free_rooms.begin() + j);
				}
				else
				{
					for (int k = 0; k < rooms.size(); k++) free_rooms.push_back(rooms[k]);
				}
				if (i < (guests.size() - 1))
				{
					int new_i = i + 1;
					CreateDecision(free_rooms, guests, new_i, child);
				}
				else
				{
					child.data.Print();
					cout << "\n" << "Cost :" << child.cost;
					cout << "\n" << "\n";
					//acc.push(make_pair(child.cost, child));
					if ((child.cost < min_cost.cost) || (min_cost.cost == 0))
					{
						min_cost.cost = child.cost;
						min_cost.data = child.data;
					}
				}
				j++;
			}
			else
			{
				j++;
				//cout << "NO room is not free\n";
			}
		}
	}
}


int main()
{
	Person Lily("Lily"), Jack("Jack"), Bob("Bob"), Billy("Billy"), Emma("Emma"), Alan("Alan"), Dilan("Dilan");
	Lily.add_partner(&Jack);
	Bob.add_friend(&Billy);
	Billy.add_friend(&Jack);
	//Emma.add_partner(&Alan);
	Bob.add_friend(&Alan);

	//Guests guests;
	//guests.AddPerson(Lily);
    //guests.AddPerson(Jack);
	//guests.AddPerson(Bob);
	//guests.AddPerson(Billy);

	//Rooms rooms;
	//rooms.Add(101);
	//rooms.Add(201);
	//rooms.Add(202);
	//rooms.Add(301);

	vector<int> rooms;
	rooms.push_back(301);
	rooms.push_back(201);
	//rooms.push_back(202);
	rooms.push_back(101);
	rooms.push_back(102);
	//rooms.push_back(103);
	//rooms.push_back(104);

	vector<Person> guests;
	guests.push_back(Lily);
	guests.push_back(Jack);
	guests.push_back(Bob);
	guests.push_back(Billy);
	//guests.push_back(Alan);
	//guests.push_back(Dilan);

	Dictionary<int, Person> data;
	Node tree(data,0);
	//Node min_cost(data, 0);
	CreateDecision(rooms, guests, 0, tree);

	cout << "Cheapest accomodation is: " << "\n";
	min_cost.data.Print();
	cout << "Cost: " << min_cost.cost;

	//cout << "Cheapest accomodation is: " << acc.top().first;


	//Dictionary<int, string> dict;
	//dict.Add(2, "Lol");
	//dict.Add(5, "mda");
	//dict.Print();
	//cout << dict[2];
	//Dictionary<int, string> dict2(dict);
	//cout << dict2[2];

	//map<int, int> lol;
	//lol.insert(make_pair(1,2));
	//lol.insert(make_pair(3, 2));
	//lol.insert(make_pair(4, 5));
	//lol.insert(make_pair(10, 1));
	//for (int i = 0; i < lol.size(); i++) cout << lol[i] << "\n";

}