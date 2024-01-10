#include<iostream>
#include<Windows.h>
#include<ctime>
#include<ostream>
#include<string>
#include<locale>
#include<cmath>
using namespace std;
//int gsd(int a, int b, int c)
//{
//	if (b=0);
//	return 0;
//}
int Count(char c, string text, int i)
{
	//if (i == text.length()) // умова закінчення рекурсивного процесу - увесь рядок пройдено
	//	cout << "The End";
	
	if (c == text[i]) // якщо символ знайдено
		i++; // збільшити кількість знайдених символів на 1		
		
	return i;
}



//медіани трикутника
//int tryk(int a, int b, int c)
//{	
//	int a1;
//	int b1;
//	int c1;
//	if (a <= 0 || b <= 0 || c <= 0)
//	{
//		cout << "Error";
//	}
//	else if (a + b > c && a + c > b && b + c > a)
//	{
//		a1 = 0.5 * sqrt(2 * pow(b, 2) + 2 * pow(c, 2) - pow(a, 2));
//		b1= 0.5 * sqrt(2 * pow(a, 2) + 2 * pow(c, 2) - pow(b, 2));
//		c1 = 0.5 * sqrt(2 * pow(a, 2) + 2 * pow(b, 2) - pow(c, 2));
//		cout << a1 << " " << b1 << " " << c1;
//	}
//	else
//	{
//		cout << "Tryk ne isnuye" << endl;
//	}
//	return 0;		
//}




//можна порахувати добуток 2 факторіалів
//int fact1(int m)
//{
//	int f = 1;
//	for (int i = 1; i < m; i++)
//	{
//		f *= i;
//	}
//	
//	return f;
//
//}




//int sum(const int** arr, size_t size1, size_t size2)
//{
//	int sum = 0;
//	int sum2;
//	for (int i = 1; i < size1; i++)
//	{
//		for (int j = 0; j < size2; j++)
//		{
//			sum = +arr[i][j] * arr[i][j];
//		}
//	}
//}
//int main()
//{
//	const int size = 10;
//	
//}


//рахує площу трикутника за координтами 
//int Area(const int numb)
//{
//	double a, b, c;
//	double x1, y1, x2, y2, x3, y3;
//	cout << "Koordunaty1: ";
//	cin >> x1 >> y1;
//	cout << "Koordunaty2: ";
//	cin >> x2 >> y2;
//	cout << "Koordunaty3: ";
//	cin >> x3 >> y3;
//	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
//	b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
//	c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
//	double p = (a + b + c) / 2;
//	double S = sqrt(p * (p - a) * (p - b) * (p - c));
//	cout << "Area =  " << S << endl << endl;
//	return 0;
//}




//рахує мінімальний і середнє арифметичне
//int min_ellement(const int* arr, size_t size)
//{
//	int min_el = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] < min_el)
//		{
//			min_el = arr[i];
//		}		
//	}
//	cout << min_el;
//	return 0;
//}
//int Average(const int* arr, size_t size)
//{
//	int offset = 0;
//	int sum = 0;
//	double average = 0;
//	for (int i = 0; i < size; i++)
//	{
//		sum += arr[i];
//		offset++;
//		
//	}
//	
//	average = sum / offset;
//	cout << average;
//	return 0;
//}
//int main()
//{
//	srand(time(NULL));
//	const int size = 10;
//	int arr[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 20 + 1;
//	}
//	min_ellement(arr, 10);
//}