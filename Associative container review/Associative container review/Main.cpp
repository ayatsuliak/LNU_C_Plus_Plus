#pragma once
#include "Source.h"

using namespace std;

int main() 
{
	ifstream file_input("publications.txt");  
	Catalog catalogs;  
	try 
	{
		if (!file_input.is_open())
		{
			throw exception("file not exist");
		}
		read_from_file(file_input, catalogs);
		file_input.close();

		ofstream file_output("sortbysurname.txt"); 
		ofstream file1_output("getbyyear.txt"); 
		int id = 0;
		for (auto it = catalogs.get_publications().begin(); it != catalogs.get_publications().end(); it++)
		{
			cout << typeid(*((*it).second)).name() << '\t' << Catalog::id++ << '\t' << *((*it).second) << endl;
			file_output << typeid(*((*it).second)).name() << '\t' << Catalog::id << '\t' << *((*it).second) << endl;

		}
		file_output.close();
		int year;
		cout << "Enter year of book ,which you want to get" << endl;
		cin >> year;
		id = 0;
		for (auto it = catalogs.get_publications().begin(); it != catalogs.get_publications().end(); it++)
		{
			//++id;
			if ((*it).second->get_year() == year)
			{
				cout << typeid(*((*it).second)).name() << '\t' << Catalog::id++ << '\t' << *((*it).second) << endl;
				file1_output << typeid(*((*it).second)).name() << '\t' << Catalog::id << '\t' << *((*it).second) << endl;
			}

		}
		file1_output.close();
	}
	catch (exception& e)
	{
		cerr << e.what();
	}

	return 0;
}