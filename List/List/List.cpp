#include<iostream>
#include<list>
#include<fstream>
#include<algorithm>

using namespace std;

template<typename T>
void Print(list<T>& lst, ostream& f)
{
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		f << *itr;
		f << " ";
	}
}

int main()
{
	fstream f1;
	fstream f2;
	f1.open("File.txt");
	f2.open("File2.txt");
	list<char> lst;
	char ch;
	while (!f1.eof())
	{
		f1 >> ch;
		lst.push_back(ch);
	}

	auto itr2 = find(lst.begin(), lst.end(), '.');
	replace(lst.begin(), itr2, ',', ' ');
	replace(itr2, lst.end(), '3', '+');

	Print(lst, f2);
	Print(lst, cout);

	f1.close();
	f2.close();
	return 0;
}