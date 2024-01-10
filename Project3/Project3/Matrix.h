#include<iostream>

using namespace std;

class Matrix
{
private:
	int** arr;
	int n;
	int m;
public:
	Matrix();

	Matrix(int n, int m);

	Matrix(const Matrix& matrix);

	Matrix& operator=(const Matrix& matrix);

	bool operator==(const Matrix& matrix);

	friend istream& operator>>(istream& is, Matrix& matrix);
	friend ostream& operator<<(ostream& os, const Matrix& matrix);

	double GetArrayElement(int i, int j);

	~Matrix();
};

class Point
{
private:
	double x;
	double y;
public:
	Point();

	Point(double x, double y);

	int GetX();
	int GetY();
};
