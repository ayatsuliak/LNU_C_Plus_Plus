#include"Jewelry.h"
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
	fstream fileInput, F1, F2;
	fileInput.exceptions(fstream::badbit | fstream::failbit);
	F1.exceptions(fstream::badbit | fstream::failbit);
	F2.exceptions(fstream::badbit | fstream::failbit);

	try
	{
		fileInput.open("input.txt");
		F1.open("File1.txt");
		F2.open("File2.txt");
	}
	catch (const fstream::failure& ex)
	{
		cout << ex.what() << endl;
	}

	size_t countShop;
	fileInput >> countShop;
	Shop* arr = new Shop[countShop];
	for (size_t i = 0; i < countShop; i++)
	{
		fileInput >> arr[i];
	}

	double sum1 = arr[0].GetPriceShop();
	double sum2 = arr[1].GetPriceShop();

	vector<string> res1 = arr[0].GetNameShop();
	vector<string> res2 = arr[1].GetNameShop();

	return 0;
}