#pragma once
#include<iostream>
#include<fstream>

using namespace std;

//��������� ����������� ��� �������� ������, �� ��� �������� ���� � ���� �� �������� ����.
//���� �������� ������ ������ ���� ��� ��������� ������� �� ����������� ������, �� ��� �� ���� ��������, 
//���� ���� - ���� ��������, ���� �������� ���� � ���� ������������ ��� �������.
//� ���������� ���� ������ ��� ��� ������� �������� �������.������ ��� � ���� ��������� � 
//�) ������� � ����� ���� � ������ �������, �� ������ �������� �� ������ x.
//�) ��������� ��� ������� ����� �� ������ ���� �� �������� � ���� �� ������(600 ��)

class IAircraft
{
protected:
	string typeOfAircraft;
	double maxHeight;
public:
	void input(fstream& file);
	void print(fstream& file);

	double getMaxHeight();

	virtual ~IAircraft(){}
};

class Plane :public IAircraft
{
protected:
	double speed;
public:
	void input(fstream& file);
	void print(fstream& file);

	friend fstream& operator>>(fstream& is, Plane& _plane);
	friend fstream& operator<<(fstream& os, Plane& _plane);

	double getSpeed();

	virtual ~Plane() {}
};

class Balloon :public IAircraft
{
protected:
	double maxFlightTime;
public:
	void input(fstream& file);
	void print(fstream& file);

	friend fstream& operator>>(fstream& is, Balloon& _balloon);
	friend fstream& operator<<(fstream& os, Balloon& _balloon);

	virtual ~Balloon() {}
};

