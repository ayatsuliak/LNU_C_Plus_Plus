#include<iostream>
#include<fstream>

using namespace std;

class Phone
{
protected:
	string name;
	string brand;
	double price;
public:
	Phone();

	Phone(string name, string brand, double price);

	friend istream& operator>>(istream& is, Phone& phone);
	friend ostream& operator<<(ostream& os, const Phone& phone);

	virtual void input(fstream& file);
	virtual void print(fstream& file);
};

class MobilePhone :public Phone
{
protected:
	string color;
	double memory_capacity;
public:
	MobilePhone() :Phone()
	{
		this->color = "none";
		this->memory_capacity = 0;
	}

	MobilePhone(string color, double memory_capacity, string name, string brand, double price) :Phone(name, brand, price)
	{
		this->color = color;
		this->memory_capacity = memory_capacity;
	}

	friend istream& operator>>(istream& is, MobilePhone& mobile_phone);
	friend ostream& operator<<(ostream& os, const MobilePhone& mobile_phone);
};

class RadioPhone :public Phone
{
protected:
	double range;
	bool answering_machine;
public:
	RadioPhone() :Phone()
	{
		this->range = 0;
		this->answering_machine = false;
	}

	RadioPhone(double range, bool answering_machine) :Phone(name, brand, price)
	{
		this->range = range;
		if (answering_machine == true)
		{
			this->answering_machine = true;
			cout << "True";
		}
		else
		{
			this->answering_machine = false;
			cout << "False";
		}
	}

	friend istream& operator>>(istream& is, RadioPhone& radio_phone);
	friend ostream& operator<<(ostream& os, const RadioPhone& radio_phone);
};
