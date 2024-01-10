#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<memory>
#include<numeric>
#include <functional>
#include<iterator>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

//int main() {
//
//    /*ifstream in("text1.txt");
//    map<string, int>  wordmap;
//    string word;
//    while (in >> word)
//        wordmap[word]++;
//
//    map<string, int> :: iterator itr;
//    for (itr = wordmap.begin(); itr != wordmap.end(); itr++)
//        cout << itr->first << ": " << itr->second << endl;
//
//    multimap<string, int>  phone_book;
//    typedef multimap<string, int>::iterator I;
//
//    pair<I, I>  b = phone_book.equal_range("Petrenko");
//    for (I i = b.first; i != b.second; i++)
//        cout << i->second << '\n';*/
//
//
//    /*vector<int> v = { 2,5,7,4 };
//    partial_sum(begin(v), end(v), 5);
//    for (auto el : v)
//    {
//        cout << el << " ";
//    }
//
//    unique_ptr<vector<int>> v2;
//
//    auto ptr = move(v2);*/
//
//    /*vector<int> v(10);
//    vector<int>::iterator ins = v.begin();
//
//    ifstream ifs("data.txt");
//    istream_iterator<int> is(ifs), eostr;
//
//    remove_copy(is, eostr, ins, 4);
//
//    for (auto el : v)
//    {
//        cout << el << " ";
//    }*/
//}


//int main()
//{
//	fstream f;
//	f.open("NoNameFile.txt");
//	//string str = "hello";
//	string str2 = "aaa";
//	int compare();
//	string str;
//	getline(f, str, '#');
//	cout << str << endl;
//
//	vector<int> v(4, 5);
//	v[0] = 2;
//	for (auto el : v)
//	{
//		cout << el;
//	}
//}




//
//int op_increase(int i) 
//{ 
//	return ++i; 
//}
//
//template<typename T>
//class Multiply
//{
//	T fact;
//public:
//	Multiply(T fact)
//	{
//		this->fact = fact;
//	}
//	T operator()(T& elem)
//	{
//		return elem *= fact;
//	}
//};
//
//void print(int x)
//{
//	cout << x << "\t";
//}
//
//bool myfunction(int i, int j) 
//{
//	return (i == j);
//}
//
//struct Tovar
//{
//	int count;
//	double price;
//
//	Tovar(int count, double price)
//	{
//		this->count = count;
//		this->price = price;
//	}
//};
//
//double price(double v, Tovar& r)
//{
//	return v + r.count * r.price;
//}
//
//class NewPrice
//{
//	double zleva;
//public:
//	NewPrice(double zleva)
//	{
//		this->zleva = zleva;
//	}
//	double operator()(double v, const Tovar& r)
//	{
//		return v + r.count * r.price * zleva;
//	}
//};

//ostream_iterator<T>(cout, " ")
//int main()
//{
//	//////////////REPLACE////////////////
//	vector<int> v1 = { 1,2,5,2 };
//	vector<int> v2 = { 5,2 };
//	replace_copy(begin(v1), end(v1), back_inserter(v2), 2, 4);
//	for (auto elem : v2)
//	{
//		//cout << elem << "\t";
//	}
//	cout << endl;
//	replace_if(begin(v1), end(v1), [](const int& a)
//		{
//			return(a % 2 == 0);
//		}, 3);
//	for (auto elem : v1)
//	{
//		//cout << elem << "\t";
//	}
//
//
//	////////////TRANSFORM////////////
//	transform(begin(v1), end(v1), begin(v2), begin(v1), plus<int>());
//	for (auto elem : v1)
//	{
//		//cout << elem << "\t";
//	}
//	cout << endl;
//	vector<int> v3;
//	v3.resize(v1.size());  
//	transform(begin(v1), end(v1), begin(v3), op_increase);
//	for (auto elem : v3)
//	{
//		//cout << elem << "\t";
//	}
//	vector<int> vect = { 2,4,6,8 };
//
//	ostream_iterator<int> out(cout, " ");
//	transform(begin(vect), end(vect), out, bind2nd(divides<int>(), 2));  //ділить елем конта на 2
//
//	transform(begin(vect), end(vect), out, bind1st(divides<int>(), 2));  //ділить 2 на елем конта
//
//	
//	/////////////////////////COUNT///////////////////
//	auto res = count_if(begin(v1), end(v1), [](const int& a)
//		{
//			return(a % 2 == 1);
//		});
//	//cout << res;
//
//
//	/////////////////////////FOR_EACH///////////////////
//	/*for_each(begin(v1), end(v1), Multiply<int>(5));
//	for_each(begin(v1), end(v1), print);*/
//
//
//	/////////////////////////FIND  FIND_END///////////////////
//	vector<int> vc = { 4, 4,6,4, 8, 8,58 };
//	vector<int> vc2 = { 2,7,8,58 };
//	auto itr = find_end(begin(vc), end(vc), begin(vc2), end(vc2));
//
//	auto itr2 = find_first_of(begin(vc), end(vc), begin(vc2), end(vc2));  //знаходить перше входж елем з конта 1, яке співпад в конт 2
//
//	auto itr3 = adjacent_find(begin(vc), end(vc));  //шукає пару яка не співпала
//	if(itr3!=vc.end())
//		cout << *itr3;
//	cout << endl;
//	auto itr4= adjacent_find(itr3, end(vc), myfunction);
//	if (itr4 != vc.end())
//		cout << *itr4;
//
//	cout << endl;
//	/////////////////////////ACCUMULATE///////////////////
//	vector<Tovar> vct =
//	{
//		Tovar(3, 5),
//		Tovar(2, 15),
//		Tovar(33, 58),
//	};
//	double total = accumulate(begin(vct), end(vct), 0.0, price);
//	cout << total << endl;
//	double total2 = accumulate(begin(vct), end(vct), 0.0, NewPrice(0.1));
//	cout << total2 << endl;
//}


//void main()
//{
//	unsigned u[10] = { 20,2,7,6,30,40,3,2,40,20 };
//	set<unsigned> a(u, u + 5), b(u + 3, u + 10);  //2 6 7 20 30  
//												  //2 3 6 20 30 40
//	list<unsigned> v(a.size() + b.size());  //12
//	auto itr = set_difference(a.begin(), a.end(), b.begin(), b.end(), v.begin());
//	cout << *itr;
//	cout << endl;
//	list<unsigned> un(v.begin(), itr);
//	list<unsigned>::iterator j;
//	for (j = un.begin(); j != un.end(); j++) 
//	cout << *j;
//}

//void main() 
//{
//	unsigned u[] = { 2,40,3,2,40 };
//	set<unsigned> a(u, u + 5);
//	for (auto el : a)
//	{
//		cout << el << " ";
//	}
//	cout << endl;
//	set<unsigned> ::iterator f = find(a.begin(), a.end(), 3);
//	unsigned s = 0;
//	while (f != a.end())
//		s += *f++;
//	cout << s; 
//}


//int main()
//{
//	vector<int> v1 = { -4, -3, -2, -1, 0, 1 , 2 };
//	vector<int> v2(7), v3(7);
//	for (auto el : v1)
//	{
//		cout << el << " ";
//	}
//	cout << endl;
//	transform(v1.begin(), v1.end(),	ostream_iterator<int>(cout, " "), Multiply<int>(3));
//	transform(v1.begin(), v1.end(), v2.begin(), Multiply<int>(5));
//	cout << endl;
//	for (auto el : v2)
//	{
//		cout << el << " ";
//	}
//
//	cout << endl;
//
//	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),	multiplies<int>());
//	for (auto el : v3)
//	{
//		cout << el << " ";
//	}
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<functional>
//#include<numeric>
//
//using namespace std;
//
//template<typename T>
//void print(T a)
//{
//    cout << a << " ";
//}
//
//void f(vector<double> l1, vector<double> l2)
//{
//    //Task A
//    double max = *max_element(begin(l2), end(l2));
//    replace_copy_if(begin(l1), end(l1), begin(l2), [](double a)
//        {
//            return a > 0;
//        }, max);
//
//    //Task Б
//    double result = accumulate(begin(l2), end(l2), 0.0, [](double a, double b)
//        {
//            return a + b;
//        });
//    cout << "Sum container v2: " << result << endl;
//    cout << "Container v2: ";
//    for_each(begin(l2), end(l2), print<double>);
//}
//
//int main()
//{
//    vector<double> v1 = { 5,6,2,8 };
//    vector<double> v2 = { 2,5,3,7 };
//
//    f(v1, v2);
//
//    cout << endl;
//
//    cout << "Container v1: ";
//    for_each(begin(v1), end(v1), print<double>);
//
//    return 0;
//}


//int main()
//{
//	vector<int> v(10);
//	auto itr = v.begin();
//
//	ifstream ist("data.txt");
//	istream_iterator<int> is(ist), eostr;
//	remove_copy(is, eostr, v, 4);  //скопійовує у вектор всі елем з файлу(is-eostr), крім 4
//
//	ostream_iterator<int> out(cout, " ");
//	out = 1111111111;
//	copy(is, eostr, out);
//	out = 0000000000000;
//
//	int arr[4] = { 3,4,5,6 };
//	vector<int> v1(arr, arr + 4);
//	insert_iterator<vector<int>> ins(v1, v1.begin() + 2);  //ітерато вставки переходить на 6  елем
//	ins = 5;  //далі після 6 вставляє нові значення
//	ins = 6;
//
//
//}






