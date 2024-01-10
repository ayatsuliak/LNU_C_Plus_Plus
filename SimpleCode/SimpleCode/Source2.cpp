#include <iostream>
#include<fstream>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<numeric>
#include<functional>
#include<thread>
using namespace std;

void SetInFile(std::fstream& f, std::string file_name)
{
	f.open(file_name, std::fstream::in | std::fstream::out | std::fstream::app);
	std::string str, str2, str3;
	std::cout << "Enter str: ";
	std::cin >> str;
	f << str << " ";
	std::cout << "Enter str2: ";
	std::cin >> str2;
	f << str2 << " ";
	std::cout << "Enter str3: ";
	std::cin >> str3;
	f << str3 << std::endl;
	std::fstream::ate;
}

class ShowEven
{
private:
	int even = 0;
	int count = 0;
public:
	void operator()(int value)
	{
		if (value % 2 == 0)
		{
			even += value;
			count++;
		}
	}

	void ShowEvenSum()
	{
		std::cout << "Even: " << even << std::endl;
	}

	void ShowCount()
	{
		std::cout << "Count: " << count << std::endl;
	}
};

class Person
{
private:
	
public:
	string name;
	int score;
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	bool operator()(const Person& ps)
	{
		return ps.score > 180;
	}
	int GetScore()
	{
		return score;
	}
	
};

int Sum(int a, int b)
{
	return a + b;
}

void DoWork(vector<int>& v, vector<function<void(int)>> f)
{
	for (auto el : v)
	{
		for (auto& elem : f)
		{
			elem(el);
		}
	}
}

template<typename T>
void ShowInfo(T (*foo)())
{
	cout << foo() << endl;
}

int main()
{
	//function<int(int, int)> f;  //приймає сигнатуру(тип ф-ції і типи параметрів)
	//f = Sum;
	//cout << f(4, 5);

	//int a = 55;
	//int b = 10;

	//auto f1 = [=]()mutable
	//{
	//	a = 100;
	//	b = 300;
	//};

	//auto f2 = [=]()->int  //лямбда-функції ми присвоюємо конкретний тип даних
	//{
	//	a = 100;
	//	b = 300;
	//}

	/*auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		cout << "ID: " << this_thread::get_id() << "\tmain work\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	auto end= chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << duration.count() << endl;*/

	map<int, string> m1;
	m1.insert(make_pair(1, "ya"));
	m1[2] = "you";
	m1[3] = "we";
	m1[4] = "they";
	m1[5] = "we";
	m1[6] = "they";
	/*for (auto itr : m1)
	{
		cout << itr.first << " " << itr.second << endl;
	}*/
	/*map<int, string> m2;
	auto itr = m1.begin();
	auto it = m2.begin();
	auto it2 = m2.end();
	m2.insert(it, make_pair<int, string>(7, "are"));
	m2.insert(it, make_pair<int, string>(8, "me"));
	m2.insert(it2, make_pair<int, string>(9, "ok"));
	m2.insert(itr, m1.find(4));
	for (auto itr : m2)
	{
		cout << itr.first << " " << itr.second << endl;
	}*/
	//cout << (m1.lower_bound(5))->first << (m1.lower_bound(5))->second;

	vector<int> v1 = { 2,5,4,3 };
	//stable_sort(begin(v1), end(v1));
	//partial_sum(begin(v1), end(v1), ostream_iterator<int>(cout, " "));
	cout << endl;
	/*replace_if(begin(v1), end(v1), [](int a)
		{
			return a < 4;
		}, 33);*/
	cout << endl;
	//cout << count_if(begin(v1), end(v1), );
	//replace(begin(v1), end(v1), 4, 16);
	/*for (auto el : v1)
	{
		cout << el << " ";
	}*/
	/*auto iterator = find_end(begin(v1), end(v1), begin(v1) + 3, end(v1) - 1);
	cout << *iterator;

	auto iterator2 = find_first_of(begin(v1), end(v1), begin(v1) + 4, end(v1) - 3);
	cout << *iterator2;*/

	cout << accumulate(begin(v1), end(v1), 1, multiplies<int>());
	cout << endl;
	transform(begin(v1), end(v1), ostream_iterator<int>(cout, " "), bind2nd(multiplies<int>(), 2));

	return 0;
}


//int main()
//{
//	std::fstream f;
//	/*for (int i = 0; i < 2; i++)
//	{
//		SetInFile(f, "File.txt");
//	}*/
//
//	/*SetInFile(f, "File.txt");
//	SetInFile(f, "File.txt");*/
//
//	/*ShowEven ef;
//	int arr[] = { 2,5,3,8,10 };
//	for (auto element : arr)
//	{
//		ef(element);
//	}
//
//	ef.ShowCount();
//	ef.ShowEvenSum();*/
//
//	vector<Person> v =
//	{
//		Person("max", 190),
//		Person("andrii", 186),
//		Person("vlad", 150),
//		Person("andrii", 200),
//	};
//
//	//int result = count_if(v.begin(), v.end(), v.front());
//	//cout << result;
//
//
//
//	//////////////SORT////////////////////////////////////
//	/*sort(v.begin(), v.end(), [](const Person& p1, const Person& p2)
//		{
//			bool result = p1.score > p2.score;
//			return result;
//		});*/
//	/*for (auto elem : v)
//	{
//		cout << "Name\t" << elem.name << "Score\t" << elem.score << endl;
//	}*/
//
//
//	//////////////FIND  FIND_IF  FIND_IF_NOT/////////////////////////////////
//	auto result = find_if(v.begin(), v.end(), [](const Person& p)
//		{
//			return p.score == 190 && p.name == "max";
//		});
//	/*if (result == v.end())
//	{
//		cout << "-" << endl;
//	}
//	else
//	{
//		cout << "+" << endl;
//	}*/
//
//
//	//////////////COPY  COPY_IF/////////////////////////////////
//	vector<Person> people;
//	//copy(v.begin(), v.end(), back_inserter(people));
//	/*for (auto elem : people)
//	{
//		cout << "Name\t" << elem.name << "\tScore\t" << elem.score << endl;
//	}*/
//
//	/*copy_if(v.begin(), v.end(), back_inserter(people), [](const Person& p)
//		{
//			return p.name == "andrii";
//		});*/
//	/*for (auto elem : people)
//	{
//		cout << "Name\t" << elem.name << "\tScore\t" << elem.score << endl;
//	}*/
//
//
//	///////////////REMOVE  REMOVE_IF//////////////////////////////////	
//	vector<int> v1 = { 2,4,1,45,3,2,9 };
//	auto it = remove(v1.begin(), v1.end(), 2);  //воно не видаляє, а переставляє в кінець
//	v1.erase(it, v1.end());  //видаляємо зі вказаного ітератора і до кінця
//
//	v.erase(remove_if(v.begin(), v.end(), [](const Person& p)  //можемо зразу передавати у erase
//		{
//			return p.score < 190;
//		}), v.end());
//	/*for (auto elem : v)
//	{
//		cout << "Name\t" << elem.name << "\tScore\t" << elem.score << endl;
//	}*/
//
//	////////////////MAX_ELEMENT  &&  MIN_ELEMENT//////////////////////////
//	vector<int> v2 = { 2,4,1,45,3,2,9 };
//	auto itr = max_element(v2.begin(), v2.end());
//	//cout << *itr;
//
//	itr = min_element(v2.begin(), v2.end());
//	//cout << *itr;
//
//
//	//////////ACCUMULATE//////////////////	
//	vector<int> v3 = { 2,5,7 };
//	auto rst = accumulate(begin(v3), end(v3), 0);  //просто сумує всі елем конта(замість 0 може буди будь яке число, яке теж буде сумуватись)
//
//	auto rst1 = accumulate(begin(v3), end(v3), 1, [](int a, int b)
//		{
//			return a * b;
//		});  //виконується перемножування елем конта і на число в 3 параметрі(тобто 1)
//
//	auto rst2 = accumulate(begin(v3), end(v3), 1, [](int a, int b)
//		{
//			if (b % 2 == 0)  //знач а буде число з параметра 3(тобто 1) а b буде число з конта
//			{
//				return a + b;
//			}
//			else
//			{
//				return a;
//			}
//		});
//	cout << rst2;
//
//	//задачка на стрінгу
//	auto str3 = accumulate(next(begin(v3)), end(v3), to_string(v3.front()), [](string a, int b)  //next відпов за перенесення ітер на некст елем
//		{
//			return a + "-" + to_string(b);
//		});
//	//cout << str3;
//
//
//	////////////EQUAL  MISMATCH//////////////////////////////
//
//	vector<int> vct = { 2,4,1,45,3,2,9 };
//	list<int> lst = { 3,4,1,45,3,2,9 };
//
//	bool resu = equal(begin(vct), end(vct), begin(lst), end(lst));
//
//	auto res = mismatch(begin(vct), end(vct), begin(lst), end(lst));  //якщо вони рівні, то пара ітераторів вказує на кінець
//	//cout << *res.first << "\t" << *res.second;
//
//
//	//////////FOR_EACH////////////////////
//	//ВПРИНЦИПІ ПРОСТО ПЕРЕБИРАЄ ЕЛЕМ(МОЖНА ВИВОДИТИ НА КОНСОЛЬ)
//
//	/*for_each(begin(vct), end(vct), [](auto& a)
//		{
//			cout << a << "\t";
//			++a;
//		});*/
//
//
//	////////////////////UNIQUE	UNIQUE_COPY////////////////////////////
//	//переставляє кінець дублікати
//	list<int> lst2 = { 3,3,4,6,6 };
//	auto value = unique(begin(lst2), end(lst2));
//	lst2.erase(value, end(lst2));
//	/*for_each(begin(lst2), end(lst2), [](auto& a)
//		{
//			cout << a << "\t";
//			++a;
//		});
//	cout << "\n";*/
//	vector<int> vect;
//	unique_copy(begin(lst2), end(lst2), back_inserter(vect));  //копіює унікальні в інший(будь який) контейнер
//	/*for_each(begin(vect), end(vect), [](auto& a)
//		{
//			cout << a << "\t";
//			++a;
//		});*/
//
//
//	/*std::vector<int> v1(5, 4);
//	v1.erase(v1.begin(), v1.begin() + 3);
//	for (int i = 0; i < v1.size(); i++)
//	{
//		std::cout << v1.at(i);
//	}
//	std::cout << std::endl;
//	std::list<char> q;
//	for(int i = 0; i < 5; i++)
//	{
//		q.push_front('a' + 1);
//	}
//	std::list<char>::reverse_iterator  it = q.rbegin();
//	for (it; it != q.rend(); it++)
//	{
//		std::cout << *it;
//	}
//	cout << endl;*/
//	/*unsigned u[10] = { 20,2,7,6,30,40,3,2,40,20 };
//	set<unsigned> a(u, u + 5), b(u + 3, u + 10);
//	list<unsigned> v(a.size() + b.size());
//	list<unsigned> un(v.begin(), set_difference(a.begin(), a.end(), b.begin(), b.end(), v.begin()));
//	list<unsigned>::iterator j;
//	for (j = un.begin(); j != un.end(); j++) 
//		cout << *j;*/
//
//	/*list < char> l(3, 'a');
//
//	char arr[5] = { 'a','b','c','d','e' };
//
//	l.insert(l.begin(), arr, arr + 3);
//
//	while (!l.empty())
//
//	{
//		cout << l.front();
//		l.pop_front();
//	}*/
//}
