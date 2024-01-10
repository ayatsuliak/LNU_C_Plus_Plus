#include<iostream>
#include<queue>
#include<cstdlib>
#include<fstream>
#define SIZE 10

using namespace std;
struct City
{
	string name;
	bool in_queue;
	vector<City*> connections;
	City(){}

	City(string _name)
	{
		this->name = _name;
	}

	bool operator<(City& other)
	{
		return (this->name < other.name);
	}

	~City(){}
};


class Road
{
private:
	City* cities = new City[SIZE];
public:
	Road(const vector<string>& _cities, const vector<pair<string, string>>& _roads)
	{
		for (int i = 0; i < SIZE; i++)
		{
			cities[i] = _cities[i];
		}
		for (auto it = _roads.begin(); it != _roads.end(); it++)
		{
			int i = 0;
			for (; i < SIZE; i++)
			{
				if (cities[i].name == it->first)
				{
					break;
				}
			}
			int j = 0;
			for (; j < SIZE; j++)
			{
				if (cities[j].name == it->second)
				{
					break;
				}
			}
			cities[i].connections.push_back(&cities[j]);
			cities[j].connections.push_back(&cities[i]);
		}
	}

	bool isConnect(string city1, string city2)
	{
		bool result = false;
		queue<City*> qu;
		int i = 0;
		qu.push(cities + i);
		cities[i].in_queue = true;
		for (auto it = qu.front()->connections.begin(); it != qu.front()->connections.end(); it++)
		{
			(*it)->in_queue = true;
			qu.push(*it);
		}
		while (!qu.empty())
		{
			
			if (qu.front()->name == city2)
			{
				result = true;
				break;
			}
			for (auto it = qu.front()->connections.begin(); it != qu.front()->connections.end(); it++)
			{
				if ((*it)->in_queue == false)
				{
					(*it)->in_queue = true;
					qu.push(*it);
				}
			}
			qu.pop();
		}
		for (int i = 0; i < SIZE; i++)
		{
			cities[i].in_queue = false;
		}
		return result;
	}

	~Road(){}
};

int main()
{
	ifstream in;
	in.open("Input.txt");
	vector <string> cities;
	vector<pair<string, string>> roads;

	string cityName;
	in >> cityName;
	while (cityName != "00")
	{
		cities.push_back(cityName);
		in >> cityName;
	}

	size_t i, j;
	while (!in.eof())
	{
		in >> i >> j;
		roads.emplace_back(make_pair(cities.at(--i), cities.at(--j)));
	}

	Road road(cities, roads);
	cout << "Road from Lviv to Kyiv ";
	cout << road.isConnect("Lviv", "Kyiv");
	cout << endl;
	
	cout << "Road from Ternopil to IvanoFrankivs ";
	cout << road.isConnect("Ternopil", "IvanoFrankivs");
	cout << endl;

	in.close();
	system("pause");
	return 0;
}