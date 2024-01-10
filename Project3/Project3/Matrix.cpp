#include <iostream> 
#include <string> 
#include <ctime> 
#include <fstream> 
#include<cmath>
#include<cstdlib>
#define tg(x) (sin(x)/cos(x))
using namespace std;

//template<typename T>
//constexpr auto tg(T x) { return sin(x) / cos(x);; }

//Matrix::Matrix()
//{
//	m = 0;
//	n = 0;
//	arr = new int* [n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[m];
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = 0;
//		}
//	}
//}
//
//Matrix::Matrix(int n, int m)
//{
//	this->m = m;
//	this->n = n;
//	this->arr = new int* [n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[m];
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = arr[i][j];
//		}
//	}
//}
//
//Matrix::Matrix(const Matrix& matrix)
//{
//	m = matrix.m;
//	n = matrix.n;
//	arr = new int* [n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[m];
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = matrix.arr[i][j];
//		}
//	}
//}
//
//bool Matrix::operator==(const Matrix& matrix)
//{
//	if (n != matrix.n || m != matrix.m)
//	{
//		return false;
//	}
//	for (int i = 0; i < matrix.n; i++)
//	{
//		for (int j = 0; j < matrix.m; j++)
//		{
//			if (arr[i][j] != matrix.arr[i][j])
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//Matrix& Matrix::operator=(const Matrix& matrix)
//{
//	if (this != &matrix)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			delete[] arr[i];
//		}
//		delete[] arr;
//	}
//	this->m = matrix.m;
//	this->n = matrix.n;
//	this->arr = new int* [n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[m];
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = matrix.arr[i][j];
//		}
//	}
//	return*this;
//}
//
//istream& operator>>(istream& is, Matrix& matrix)
//{
//	//is >> matrix.n >> matrix.m;
//	matrix.arr = new int* [matrix.n];
//	for (int i = 0; i < matrix.n; i++)
//	{
//		matrix.arr[i] = new int[matrix.m];
//		for (int j = 0; j < matrix.m; j++)
//		{
//			is >> matrix.arr[i][j];
//		}
//		cout << endl;
//	}
//	return is;
//}
//
//ostream& operator<<(ostream& os, const Matrix& matrix)
//{
//
//	for (int i = 0; i < matrix.n; i++)
//	{
//		for (int j = 0; j < matrix.m; j++)
//		{
//			os << matrix.arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	return os;
//}
//
//double Matrix::GetArrayElement(int i, int j)
//{
//	return arr[i][j];
//}
//
//Matrix::~Matrix()
//{
//	for (int i = 0; i < n; i++)
//	{
//		delete[] arr[i];
//	}
//	delete[] arr;
//}
//
//Point::Point()
//{
//	x = 0;
//	y = 0;
//}
//
//Point::Point(double x, double y)
//{
//	this->x = x;
//	this->y = y;
//}
//
//int Point::GetX()
//{
//	return x;
//}
//
//int Point::GetY()
//{
//	return y;
//}
//
//double LenghtOfSegment(Point p1, Point p2)
//{
//	double to_return = sqrt(pow(p1.GetX() - p2.GetX(), 2) + pow(p1.GetY() - p2.GetY(), 2));
//	return to_return;
//}
//
//int main()
//{
//	int n;
//	cout << "Enter number of columns: ";
//	cin >> n;
//	Matrix A(2, n);
//	cin >> A;
//	cout << "Matrix A: " << endl;
//	cout << A;
//
//	cout << "=========================" << endl;
//
//	Point* points = new Point[n];
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Points: " << endl;
//		cout << i << "\t";
//		points[i] = Point(A.GetArrayElement(0, i), A.GetArrayElement(1, i));
//	}
//
//	double max_length = LenghtOfSegment(points[0], points[1]);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i != j && LenghtOfSegment(points[i], points[j]) > max_length)
//			{
//				max_length = LenghtOfSegment(points[i], points[j]);
//			}
//		}
//	}
//
//	cout << "max length of segment = " << max_length << endl;
//
//	delete[]points;
//	return 0;
//}
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A";
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		cout << "B";
//	}
//};
//
//class E :public A, public B
//{
//public:
//	E()
//	{
//		cout << "E";
//	}
//};
//
//void F()
//{
//	A a;
//	B b;
//	E e;
//}
//
//int main()
//{
//	F();
//}

class MyException :public exception
{
private:
	int data_state;
public:
	MyException(char* msg) :exception(msg)
	{

	}

	int GetDataState()
	{
		return data_state;
	}
};

class Point
{
private:
	int a;
	int b;
public:
	Point(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	int Sum(int a, int b)
	{
		if (b == 0)
		{
			throw exception("Error");
			//exit(EXIT_FAILURE);
		}
		return (a / b);
	}
	

};

//int main()
//{
//	/*Point p(3, 0);
//	p.Sum(3, 0);
//	try
//	{
//		p.Sum(3, 0);
//	}
//	catch (exception& ex)
//	{
//		cout << ex.what() << endl;
//	}*/
//
//	cout << tg(5) << endl;
//
//}




