#include"Aircraft.h"
#include<numeric>
#include<vector>

using namespace std;

double calculateTime(double speed)
{
	return 600000 / speed;
}

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
	catch (const fstream::failure& ex)
	{
		cout << ex.what() << endl;
	}

	size_t size;
	fileInput >> size;
	istream_iterator<IAircraft*> begin(fileInput), end;

	vector<IAircraft> aircraft;
	aircraft.resize(size);
	copy(begin, end, back_inserter(aircraft));
	double x = 3500.0;
	for (auto itr = aircraft.begin(); itr != aircraft.end(); ++itr)
	{
		if (itr->getMaxHeight() > x)
		{
			itr->print(F1);
		}
	}

	fileInput.close();
	F1.close();
	return 0;
}