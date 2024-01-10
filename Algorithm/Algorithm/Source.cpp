#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

//void main() 
//{
//	vector<int> v1(5, 4); 
//	v1.erase(v1.begin(), v1.begin() + 3);
//	for (int i = 0; i < v1.size(); i++)
//		cout << v1.at(i);
//}

//void main()
//{
//	list<char> q;
//	for (int i = 0; i < 5; i++)
//		q.push_front('a' + i);
//	list<char>::reverse_iterator it = q.rbegin();
//	for (it; it != q.rend(); it++)
//		cout << *it; 
//}

//void main()
//{
//	unsigned u[10] = { 20,2,7,6,30, 40,3,2,40,20 };
//	set<unsigned> a(u, u + 5), b(u + 3, u + 10);
//	//a(2 6 7 20 30)
//	//b(2 3 6 20 30 40)
//	list<unsigned> v(a.size() + b.size());
//	list<unsigned> un(v.begin(),
//		set_difference(a.begin(), a.end(), b.begin(), b.end(), v.begin()));
//	list<unsigned>::iterator j;
//	for (j = un.begin(); j != un.end(); j++) cout << *j;
//}

//void main() 
//{
//	unsigned u[] = { 2,40,3,2,40 };
//	set<unsigned> a(u, u + 5);
//	set<unsigned>::iterator f = find(a.begin(), a.end(), 3);
//		unsigned s = 0;
//	while (f!= a.end())
//		s += *f++;
//	cout << s;
//}

//void main() 
//{
//	list <char> l(3, 'a');
//	char arr[5] = { 'a','b','c','d','e' };
//	l.insert(l.begin(), arr, arr + 3);
//	while (!l.empty())
//	{
//		cout << l.front();
//		l.pop_front();
//
//	}
//}

//class A {
//	int a;
//
//public:
//
//	A(int a) :a(a) {}
//
//int get() { return a; }
//};
//class B : public A {
//	int b;
//public:
//	int get() { return b; }
//
//};
//
//void F()
//
//{
//	A a(i);
//	B b;
//}

//class A {
//
//	int a;
//public:
//
//	A(int a) :a(a) {}
//	int get() { return a; }
//
//};
//
//class B : public A {
//	int b;
//
//public:
//	B(int b) :A(0) { b = b; }
//	int get() { return b; }
//
//};
//
//void F()
//{
//	B b(3);
//		}
		

//class A {
//	int x;
//public:
//	A(int i) :x(i) {}
//
//	string g(int i) {
//		if (i > x) throw string("Over");
//		if (i < x) throw string("Under");
//		return "Ok";
//
//	}
//};
//
//
//void r()
//{
//	try {
//		A a(20);
//		cout << a.g(-20);
//	}
//	catch (const char* e) { cout << "Out of range"; }
//	catch (const string& e) { cout << e; }
//	catch (...) { cout << "Fatal"; }
//	cout << ":)";
//}
//
//
//void main()
//{
//	r();
//}

