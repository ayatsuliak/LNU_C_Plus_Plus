#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<fstream>

using namespace std;

//int main()
//{
//	fstream f;
//	f.open("File.txt");
//	vector<char> v1;
//	while (!f.eof())
//	{
//		char ch;
//		f >> ch;
//		v1.push_back(ch);
//	}
//	auto res = count_if(begin(v1), end(v1), [](char ch)
//		{
//			return isdigit(ch);
//		});
//	cout << "Count number " << res << endl;
//
//	vector<char> v2;
//	copy(begin(v1) + 4, end(v1) - 5, back_inserter(v2));
//	for_each(begin(v2), end(v2), [](char ch)
//		{
//			cout << ch << " ";
//		});
//	cout << endl;
//
//	sort(begin(v2), end(v2));
//	auto itr = unique(begin(v2), end(v2));
//	v2.erase(itr, end(v2));
//	cout << "After sort and unique: ";
//	for_each(begin(v2), end(v2), [](char ch)
//		{
//			cout << ch << " ";
//		});
//
//	f.close();
//	return 0;
//}