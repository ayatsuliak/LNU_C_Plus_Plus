#pragma once
#include "Source.h"

using namespace std;

Publication::Publication(string _tittle, string _author, int _year)
{
	this->tittle = _tittle;
	this->author = _author;
	this->year = _year;
}

string Publication::get_author()
{
	return author;
}

int Publication::get_year()
{
	return year;
}

istream& operator>>(istream& in, Publication& publications)
{
	in >> publications.tittle >> publications.author >> publications.year;
	return in;
}

ostream& operator<<(ostream& out, const Publication& publications)
{
	out << publications.tittle << '\t' << publications.author << '\t' << publications.year;
	return out;
}

void Catalog::add(Publication* publication)
{
	publications.insert(make_pair(publication->get_author(), publication));
	//id++;
}

int Catalog::id = 1;

map<string, Publication*>& Catalog::get_publications()
{
	return publications;
}

void read_from_file(ifstream& fin, Catalog& catalog)
{
	Publication* current_publication = nullptr;
	string publication_type;
	string tittle, author;
	int year;
	while (!fin.eof())
	{
		fin >> publication_type >> tittle >> author >> year;;

		if (publication_type == "book") {
			current_publication = new Book(tittle, author, year);
		}
		else if (publication_type == "article")
		{
			current_publication = new Article(tittle, author, year);
		}
		catalog.add(current_publication);
	}
}