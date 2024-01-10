#include<iostream>
#include<Windows.h>
#include<ctime>
#include<string>
#include<locale>
#include<cmath>
//#define e 2,71

using namespace std;
//задача для середнього арифметичного крім одного елемента
//int main()
//{
//	const int size = 5;
//	int i = 3;
//	int arr[size];
//	int sum = 0;
//	int numb = 0;
//	double average;
//	
//	for (int j = 0; j < size; j++)
//	{
//		arr[j] = rand() % 40 + 1;
//		cout << arr[j] << " " << endl;
//		
//		if (arr[j] != arr[i])
//		{
//			sum += arr[j];
//			numb++;
//		}
//		average = sum / numb;
//		
//	}
//	cout << endl;
//	cout << average;
//}

//заміна кожного члена остачею
//int main()
//{
//	const int size = 39;
//	int n = 3;
//	int arr[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 39 + 1;
//		cout << arr[i] << " ";
//		arr[i] = arr[i] % n;
//		cout << arr[i] << " ";
//		cout << endl;
//		
//	}
//}




//числа фібоначі
//int Fib(int i)
//{
//	int value = 0;
//	if (i < 1) return 0;
//	if (i == 1) return 1;
//	return Fib(i - 1) + Fib(i - 2);
//}
//int main()
//{
//	int i = 0;	
//	while (i < 5)
//	{
//		cout << Fib(i) << endl;
//		i++;
//	}
//	return 0;
//}



//int main()
//{
//	int a1 = 4;
//	int a2 = 8;
//	int a3 = 5;
//	int a4 = 7;
//	const int size = 10;
//	const int size2 = 10;
//	int arr[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 15 + 1;
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < size2; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			arr[i] = (pow(arr[j], 2) - arr[j] - a1) / (arr[j] - a1);
//			cout << arr[i] << " ";
//		}
//	}
//}

//int main()
//{
//	double x;
//	const int n = 5;
//	//int arr[n];
//	for (int k = 1; k < n; k++)
//	{
//		for (int a = 1; a < n; a++)
//		{
//			a = cos(pow(x, 2 * k));
//			int f = pow(e, a) * sin(pow(x, 3 * k));
//			cout << f << " ";
//		}
//		
//	}
//	
//}



//викидає цифри з числа
//int main()
//{
//    int i = 0, a = 0, k;
//    cin >> k;
//    while (k > 0)
//    {
//        if (k % 10 != 0 && k % 10 != 5) //ми вибираємо по одному елементу з кінця
//        {
//            a *= 10; //так як би виділяє місце під нову цифру
//            cout << a << endl;
//            a += k % 10;
//        }
//        k /= 10; //тут ми відкидаємо останнє число
//    }
//    while (a > 0)
//    {
//        cout << a % 10;
//        a /= 10;
//    }
//    
//    return 0;
//}

//рахує вираз
//int main()
//{
//	int a1 = 4;
//	int a2 = 2;
//	int a3 = 7;
//	int a4 = 3;
//	for (int i = 1; i <= 10; i++)
//	{
//		int b = (pow(i, 2) - i - a1) / (i - a1) * (pow(i, 2) - i - a2) / (i - a2) * (i - a3) - (pow(i, 4) - i + a4) / i + i * (i + a3);
//		cout << b << endl;
//	}	
//}

//рахує вираз
//int main()
//{
//	int const n = 6;
//	int x = 2;
//	int b1=0;
//	for (int k = 1; k <= n; k++)
//	{
//		int e = 2.71;		
//		int b = pow(e, cos(pow(x, 2 * k))) * sin(pow(x, 3 * k));
//		if (b1 < b)
//		{
//			cout << b;
//		}
//		
//	}
//	
//}

//функція чз числа фібоначчі
//int Fib(int i)
//{
//	if (i < 1) return 0;
//	if (i == 1) return 1;
//	return Fib(i - 1) + Fib(i - 2);
//}
//int F(int i)
//{
//	if (i < 1) return 0;
//	if (i == 1) return 1;
//	return F(i - 1) + F(i - 2);
//}
//int main()
//{
//	int i = 0;
//	int n;
//	cin >> n;
//	while (i < n)
//	{		
//		cout << Fib(i - 2) + F(i) << endl;
//		i++;
//	}
//	return 0;
//}


