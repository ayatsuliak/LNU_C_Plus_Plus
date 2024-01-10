#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

//В текстовому файлі задані дані про розміщення букв у тексті : набір буква - список позицій, на яких вона стоїть у тексті.
//- Визначити необхідні типи
//- ввести дані з файлу
//- вивести в файл1 повний текст, що відповідає введеним даним.
//- вивести у файл2, букви, посортовані за їх кількістю у тексті, спочатку всі голосні, потім - приголосні.

int main()
{
	fstream f1, f2, f3;
	f1.open("Input.txt");
	f2.open("File1.txt");
	f3.open("File2.txt");
	char ltr;
	int pos;

	map<char, vector<int>> text;

	while (!f1.eof())
	{
		f1 >> ltr >> pos;
		while (pos != 0)
		{
			text[ltr].push_back(pos);
			f1 >> pos;
		}
	}

	int size = 0;
	for (auto itr = text.begin(); itr != text.end(); ++itr)
	{
		size += itr->second.size();
	}

	char* arr = new char[size];
	for (auto itr = text.begin(); itr!=text.end(); ++itr)
	{
		for (auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
		{
			arr[*itr2] = itr->first;
		}
	}

	for (size_t i = 1; i <= size; i++)
	{
		f2 << arr[i];
		cout << arr[i];
	}
	
	//////////////////////////////////////////////////////////////////////////////////////

	multimap<int, char> text2;
	for (auto itr = text.begin(); itr != text.end(); ++itr)
	{
		text2.insert(make_pair(itr->second.size(), itr->first));
	}

	for (auto itr2 = text2.begin(); itr2 != text2.end(); ++itr2)
	{
		switch (itr2->second)
		{
		case 'a':f3 << itr2->second << ": " << itr2->first << endl;
			continue;
		case 'e':f3 << itr2->second << ": " << itr2->first << endl;
			continue;
		case 'o':f3 << itr2->second << ": " << itr2->first << endl;
			continue;
		case 'i':f3 << itr2->second << ": " << itr2->first << endl;
			continue;
		case 'y':f3 << itr2->second << ": " << itr2->first << endl;
			continue;
		case 'u':f3 << itr2->second << ": " << itr2->first << endl;
			continue;
		}
	}
	for (auto itr2 = text2.begin(); itr2 != text2.end(); ++itr2)
	{
		if (itr2->second != 'a' && itr2->second != 'e' && itr2->second != 'o' && itr2->second != 'i' && itr2->second != 'y' && itr2->second != 'u')
		{
			f3 << itr2->second << ": " << itr2->first << endl;
		}
	}

	f1.close();
	f2.close();
	f3.close();
	return 0;
}