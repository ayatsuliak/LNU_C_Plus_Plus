#pragma once
#include <exception>
#include <fstream>
#include <iostream>  
#include <map>

using namespace std;

//.� ���������� ���� ����� ��� ��� ������ ������� ���� �� ������ �������.
//- ��������� �������� ����(�����, ������, �������)
//- ������ ��� � �����, ���������� ������� ������ ����� � �������, ����� � �������� ������(�� ��������).
//- ������� � ����1 ������������ �� �������� ������ ����� ��������.
//- ������ ������� ����� ����� � ������ �����, ���������� ���� ���������.� ����2 ������� �� ����� �� �����, ��������� ���� �������.

class Publication 
{
private:
	string tittle = "";
	string author = "";
	int year = 0;
public:
	Publication(string _tittle, string _author, int _year);
	virtual ~Publication() = 0 {};

	string get_author();
	int get_year();
	friend istream& operator>>(istream& in, Publication& publications);
	friend ostream& operator<<(ostream& out, const Publication& publpublications);
};

class Book :public Publication
{
public:
	Book(string _tittle, string _author, int _year) :Publication(_tittle, _author, _year){}
	virtual ~Book() override {}
};

class Article :public Publication
{
public:
	Article(string _tittle, string _author, int _year) :Publication(_tittle, _author, _year){}
	virtual ~Article() override {}
};

class Catalog
{
	map<string, Publication*> publications;
	

public:
	static int id;
	void add(Publication* p);
	static int getId();

	map<string, Publication*>& get_publications();
};

void read_from_file(ifstream& fin, Catalog& catalog);