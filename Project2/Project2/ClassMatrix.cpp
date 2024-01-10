#include<iostream>
#include<Windows.h>
#include<fstream>

using namespace std;

int** InputMatrix(int n, int m)
{
	int** result = new int* [n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cout << "M[" << i << "," << j << "]=";
			cin >> result[i][j];
		}
	}
	return result;
}

void PrintMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

//int main()
//{
//	int n, m, k;
//	cout << "Input n, m, k";
//	cin >> n >> m >> k;
//	int** a, ** b;
//	cout << "Input matrix A " << n << "*" << m << endl;
//	a = InputMatrix(n, m);
//	cout << "Input matrix B " << m << "*" << k << endl;
//	b = InputMatrix(m, k);
//	PrintMatrix(a, n, m);
//	PrintMatrix(b, m, k);
//}


class Matrix
{
private:
	int** arr;
	int n;
	int m;
public:
	Matrix()
	{
		this->m = 0;
		this->n = 0;
		this->arr = new int* [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	Matrix(const Matrix& matrix)
	{
		this->m = matrix.m;
		this->n = matrix.n;
		this->arr = new int* [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				this->arr[i][j] = matrix.arr[i][j];
			}
		}
	}

	Matrix& operator=(const Matrix& matrix)
	{
		if (this != &matrix)
		{
			for (int i = 0; i < n; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;
		}
		this->m = matrix.m;
		this->n = matrix.n;
		this->arr = new int* [n];
		for (int i = 0; i < n; i++)
		{
			this->arr[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				this->arr[i][j] = matrix.arr[i][j];
			}
		}
		return*this;
	}

	bool operator==(const Matrix& matrix)
	{
		if (n != matrix.n || m != matrix.m)
		{
			return false;
		}
		for (int i = 0; i < matrix.n; i++)
		{
			for (int j = 0; j < matrix.m; j++)
			{
				if (arr[i][j] != matrix.arr[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	friend istream& operator>>(istream& is, Matrix& matrix)
	{
		is >> matrix.n >> matrix.m;
		matrix.arr = new int* [matrix.n];
		for (int i = 0; i < matrix.n; i++)
		{
			matrix.arr[i] = new int[matrix.m];
			for (int j = 0; j < matrix.m; j++)
			{
				is >> matrix.arr[i][j];
			}
			cout << endl;
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const Matrix& matrix)
	{
		
		for (int i = 0; i < matrix.n; i++)
		{
			for (int j = 0; j < matrix.m; j++)
			{
				os << matrix.arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return os;
	}

	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
};

void Enter(int** matr, int n, int m) 
{
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matr[i][j] = rand() % 100 - 20;
		}
	}
}

void PrintArray(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << "\n";
	}
}

int** FormMatr(int n, int m)
{
	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
	}
	return matr;
}

void Dell(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matr[i];
	}
	delete[]matr;
}

int** DeleteRows(int** matr, int& n, int m, int pos) {
	int** temp = FormMatr(n - 1, m);
	int t = 0;
	for (int i = 0; i < n - 1; i++)
	{
		matr[i] = new int[m];
		if (i != pos)
		{
			for (int j = 0; j < m; j++)
			{
				temp[t][j] = matr[i][j];
			}
			t++;
		}
	}
	Dell(matr, n, m);
	n--;
	return temp;
}

void FindNumber(int** mas, int n, int m, int number)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] == number)
			{
				cout << "Element: [" << i << "," << j << "]" << endl;
			}
		};
	}
}

void FindNumber2(int** mas, int n, int m) //доробити ф-цію
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] < 0)
			{
				temp = 1;
				cout << temp << " ";
				i++;
			}
			else if(mas[i][j] > 0)
			{
				temp = 0;
				cout << temp << " ";
				i++;
			}
		}
	}
}

void DeleteMatrix(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}

//int main()
//{
//	fstream F;
//	F.open("city.txt");
//	int n, m;
//	F >> n >> m;
//	
//	/*cout << "Matrix size: " << n << "*" << m << endl;
//	int** arr = new int* [n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[m];
//		for (int j = 0; j < m; j++)
//		{
//			F >> arr[i][j];
//		}
//	}*/
//	int size_rows;
//	int size_cols;
//	cout << "Cin size matrix:" << endl;
//	cout << "Size rows: ";
//	cout << endl;
//	cin >> size_rows;
//	cout << "Size cols: ";
//	cout << endl;
//	cin >> size_cols;
//	int** arr2 = new int* [size_rows];
//	Enter(arr2, size_rows, size_cols);
//	PrintArray(arr2, size_rows, size_cols);
//	//FindNumber(arr2, size_rows, size_cols, 0);
//	cout << endl << endl;
//
//
//	cout << "Zadacha numb 2" << endl << endl;
//
//	FindNumber2(arr2, n, m);
//
//	//PrintArray(arr2, size_rows, size_cols);
//	DeleteMatrix(arr2, size_rows, size_cols);
//}