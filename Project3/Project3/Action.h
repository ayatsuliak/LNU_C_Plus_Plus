#pragma once
#include<fstream>
#include<iostream>
#include<memory>
#include<vector>

using namespace std;

//��������� ���� �ĳ��(�����, ���������) � �����������, ����������, ����, ����系, ���� ����������� ����(����, ������ ��) 
//�� ���� ����������� �� ��������, ���� �������� ���������� �� 7 ��� �� ��� �����.
//� ���������� ���� ������ ��� ��� ���������� ����� 2 ���.
//�) ������� ��� � ����� � ����������� �� ������� ��� ����� �� ��� ���������� ���, � ����� � �������� ĳ�.
//�)���������� ��� ������� ����� �������� ��������� ��� �� ����������� �������� ����� ��������� ������� � ��������� ����.

class Action
{
private:
	string name;
	double time;
public:
	friend fstream& operator>>(fstream& is, Action& _action);
	friend ostream& operator<<(ostream& os, const Action& _action);

	string getName();
	double getTime();

	~Action(){}
};

class Routine
{
private:
	tm date;
	vector<Action> actionList;
	size_t countAction;
public:
	friend fstream& operator>>(fstream& is, Routine& _routine);
	friend ostream& operator<<(ostream& os, const Routine& _routine);

	size_t getCountAction();

	double AllTime()
	{
		double time = 0.0;
		for (size_t i = 0; i < countAction; i++)
		{
			if (actionList[i].getName() == "walk")
			{
				time += actionList[i].getTime();
			}
		}
		return time;
	}

	~Routine()
	{
		actionList.clear();
	}
};

class RoutineForTheWeek
{
private:
	string personName;
	vector<Routine> routineList;
public:
	friend fstream& operator>>(fstream& is, RoutineForTheWeek& _routineForTheWeek);
	friend ostream& operator<<(ostream& os, const RoutineForTheWeek& _routineForTheWeek);
	vector<size_t> getCountActionWeek()
	{
		vector<size_t> result(7);
		for (size_t i = 0; i < 7; i++)
		{
			result[i] = routineList[i].getCountAction();
		}
		return result;
	}

	vector<double> getAllTimeWeek()
	{
		vector<double> result(7);
		for (size_t i = 0; i < 7; i++)
		{
			result[i] = routineList[i].AllTime();
		}
		return result;
	}

	Routine operator[](size_t pos);

	string getName();

	~RoutineForTheWeek()
	{
		routineList.clear();
	}
};

