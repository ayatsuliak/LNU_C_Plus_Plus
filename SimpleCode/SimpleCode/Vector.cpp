#include<iostream>
#include<fstream>
#include<vector>

//using namespace std;

void PushToFile(std::string str, std::ostream& f)
{
	f << str << std::endl;
}

//int main()
//{
//	std::fstream f;
//	f.open("File.txt", std::ofstream::app);
//	std::string str = "user andriy07 andriy1234519";
//	PushToFile(str, f);
//	str = "admin maksim09 maksim12345";
//	PushToFile(str, f);
//	f.close();
//	return 0;
//}


//int main()
//{
//	vector<int> my_vector{ 2,4,1,66 };
//	vector<int> ::iterator itr = my_vector.begin();
//	advance(itr, 2);
//	my_vector.insert(itr, 999);
//	
//
//	for (vector<int> ::iterator i = my_vector.begin(); i != my_vector.end(); i++)
//	{
//		cout << *i << endl;
//	}
//	cout << endl;
//	vector<int> ::iterator it = my_vector.begin();
//	advance(it, 1);
//	my_vector.erase(it);
//	for (vector<int> ::iterator i = my_vector.begin(); i != my_vector.end(); i++)
//	{
//		cout << *i << endl;
//	}
//
//}