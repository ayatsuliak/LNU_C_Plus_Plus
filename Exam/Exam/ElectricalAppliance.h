#pragma once
#include<iostream>
#include<fstream>

using namespace std;

//��������� ����������� ��� ��������������(�����, �����, ����).
//��������� 3 ������ �� ����� ���� : ����������(���������, ����), �������� ������(������� �������, �ᒺ�), 
//��������(���������, ������� �������).
//� ���������� ���� ������ ��� ��� 7 ����� ��������������.������� ��� � ���� ����� � ������� � 
//����1 �� ��������������, ���������� �� ������ �� ����������� �� �������.
//������� � ����2 ������ ���� ��  �������� ������� �������������� ������� �����.

class IElectricalAppliance
{
protected:
	string name;
	string company;
	double price;
public:
	virtual void Input(fstream& file);
	virtual void Print(fstream& file);

	virtual string nameElectricalAppliance();
	virtual string nameCompanyElectricalAppliance();
	virtual double priceElectricalAppliance();

	bool operator<(IElectricalAppliance& _electricalAppliance);

	virtual string getType() = 0;

	virtual ~IElectricalAppliance() {};
};

class Steamer :public IElectricalAppliance  //���������
{
protected:
	size_t powerSteamer;
	string colorSteamer;
public:
	void Input(fstream& file);
	void Print(fstream& file);

	friend fstream& operator>>(fstream& is, Steamer& _steamer);
	friend fstream& operator<<(fstream& os, Steamer& _steamer);

	string getType();
};

class WashingMachine :public IElectricalAppliance
{
protected:
	size_t countProgramInWashingMachine;
	double volumeWashingMachine;
public:
	void Input(fstream& file);
	void Print(fstream& file);

	friend fstream& operator>>(fstream& is, WashingMachine& _washingMachine);
	friend fstream& operator<<(fstream& os, WashingMachine& _washingMachine);

	string getType();
};

class Combine :public IElectricalAppliance
{
protected:
	size_t powerCombine;
	size_t countFunctionCombine;
public:
	void Input(fstream& file);
	void Print(fstream& file);

	friend fstream& operator>>(fstream& is, Combine& _combine);
	friend fstream& operator<<(fstream& os, Combine& _combine);

	string getType();
};