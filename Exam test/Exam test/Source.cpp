#include<algorithm>
#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

template<typename V>
vector<V> Func(vector<V> v, V elem1, V elem2)
{
	auto itr1 = find(v.begin(), v.end(), elem1);
	auto itr2 = find(v.begin(), v.end(), elem2);
	if (itr1 == v.end() || itr2 == v.end())
	{
		auto first = v.begin();
		auto last = v.begin() + v.size() / 2;
		vector<V> newV(first, last);
		return newV;
	}
	else
	{
		vector<V> newV(itr1, itr2 + 1);
		return newV;
	}
}

int main()
{
	vector<double>v1{ 3.5, 5.0, 2.0, 7.8, 1.4,6 };
	vector<string>v2{ "Hello", "Walk", "Football", "Mama", "File"};

	vector<double>result1 = Func(v1, 5.0, 1.4);
	vector<string>result2 = Func(v2, (string)"Norm", (string)"Yes");

	copy(result1.begin(), result1.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
	copy(result2.begin(), result2.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	return 0;
}