#pragma once
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

//Визначити тип «Ювелірна прикраса»(назва, метал, вага, ціна) та тип «Ювелірний магазин»(адреса, кількість прикрас, список прикрас).
//В текстовому файлі задано дані про 4 ювелірні магазини.Ввести дані в масив, видрукувати у текстовий файл список всіх назв металу(без повторів), 
//що присутні у ювелірних виробах магазинів із зазначенням кількості таких виробів
//В інший текстовий файл вивести посортовані за назвою прикраси лише з тих магазинів, загальна сума виробів в яких не менше 500.


class Jewelry
{
private:
	string name;
	string metal;
	double weight;
	double price;
public:
	friend fstream& operator>>(fstream& is, Jewelry& other);
	friend ostream& operator<<(ostream& os, const Jewelry& other);

	string GetName();
	string GetMetal();
	double GetPrice();

	~Jewelry() {};
};

class Shop
{
private:
	string adress;
	size_t count;
	vector<Jewelry> jewelry;
public:
	friend fstream& operator>>(fstream& is, Shop& other);
	friend ostream& operator<<(ostream& os, const Shop& other);

	size_t GetCount();

	vector<string> GetMetalShop()
	{
		vector<string> result(GetCount());
		for(size_t i=0;i< GetCount();i++)
		{
			result[i] = jewelry[i].GetMetal();
		}
		return result;
	}

	vector<string> GetNameShop()
	{
		vector<string> result(GetCount());
		for (size_t i = 0; i < GetCount(); i++)
		{
			result[i] = jewelry[i].GetName();
		}
		return result;
	}

	double GetPriceShop()
	{
		double price = 0.0;
		vector<double> result(count);
		for (size_t i = 0; i < count; i++)
		{
			price += jewelry[i].GetPrice();
		}
		return price;
	}

	~Shop()
	{
		jewelry.clear();
	}
};

