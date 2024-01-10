#include "Action.h"
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
	fstream fileInput, F1;
	fileInput.exceptions(fstream::badbit | fstream::failbit);
	F1.exceptions(fstream::badbit | fstream::failbit);

	try
	{
		fileInput.open("input.txt");
		F1.open("File1.txt");
	}
	catch(const fstream::failure& ex)
	{
		cout << ex.what() << endl;
	}

	RoutineForTheWeek arr[2];
	
	for (size_t i = 0; i < 2; i++)
	{
		fileInput >> arr[i];
	}

	vector<size_t> v1 = arr[0].getCountActionWeek();
	vector<size_t> v2 = arr[1].getCountActionWeek();
	size_t maxElemInv1 = *max_element(begin(v1), end(v1));
	size_t maxElemInv2 = *max_element(begin(v2), end(v2));
	if (maxElemInv1 >= maxElemInv2)
	{
		cout << arr[0].getName() << endl;
		auto itr = find(begin(v1), end(v1), maxElemInv1);
		size_t position = 7 - (end(v1) - itr);
		Routine temp = arr[0][position];
		cout << temp;
	}
	else
	{
		cout << arr[1].getName() << endl;
		auto itr = find(begin(v2), end(v2), maxElemInv2);
		size_t position = 7 - (end(v2) - itr);
		Routine temp = arr[1][position];
		cout << temp;
	}

	/////////////////////////////////////////////////////////////////////////////////

	vector<double> time1 = arr[0].getAllTimeWeek();
	vector<double> time2 = arr[1].getAllTimeWeek();

	auto sum1 = accumulate(begin(time1), end(time1), 0.0);
	auto sum2= accumulate(begin(time2), end(time2), 0.0);

	F1 << arr[0].getName() << ": " << sum1 << endl;
	F1 << arr[1].getName() << ": " << sum2 << endl;

	fileInput.close();
	F1.close();
	return 0;
}