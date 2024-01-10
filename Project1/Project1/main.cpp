#include<iostream>
#include<Windows.h>
#include<ctime>
#include<string>
#include<locale>
using namespace std;
//class MyClass
//{
//private:
//	int* data;
//	int Size;
//public:
//	MyClass(int size)
//	{
//		this->Size = size;
//		cout << "Konstructor" << this << endl;
//		this->data = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			data[i] = i;
//			
//		}
//		
//		cout << endl << endl;
//	}
//	MyClass(const MyClass &other)
//	{
//		this->Size = other.Size;
//		this->data = new int[other.Size];
//		for (int i = 0; i < other.Size; i++)
//		{
//			this->data[i] = other.data[i];
//			
//		}
//		
//	}
//	MyClass& operator=(const MyClass& other)
//	{
//		this->Size = other.Size;
//		this->data = new int[other.Size];
//		if (this->data != nullptr)
//		{
//			delete[] this->data;
//		}
//		for (int i = 0; i < other.Size; i++)
//		{
//			this->data[i] = other.data[i];
//			
//		}
//		cout << "Copy" << this << endl;
//		return *this;
//	}
//	~MyClass()
//	{
//		cout << "dystructor" << this << endl;
//		delete[] data;
//	}
//};
//
//
//class Point
//{
//private:
//	int x;
//	int y;
//public:
//	Point()
//	{
//		x = 0;
//		y = 0;
//	}
//	
//
//	Point(int ivaluex, int ivaluey)
//	{
//		this->x = ivaluex;
//		this->y = ivaluey;
//	}
//	bool operator > (const Point& other)
//	{
//		return (this->x > other.x && this->y > other.y);
//	}
//	bool operator < (const Point& other)
//	{
//		return !(this->x > other.x && this->y > other.y);
//	}
//	Point operator +(const Point& other)
//	{
//		Point temp;
//		temp.x = this->x + other.x;
//		temp.y = this->y + other.y;
//
//	}
//
//	//c=a+b
//};
//
//
//
//
//int main()
//{
//	Point a(4, 5);
//	Point b(5, 10);
//	bool result = a < b;
//	if (result == true)
//		cout << "true";
//	else
//		cout << "false";
//
//}
//

//class Human;
//class Apple;
//
//class Human
//{
//public:
//	void TakeApple(Apple& apple);
//};
//
//class Apple
//{
//public:
//	Apple(int weight, string color)
//	{
//		this->weight = weight;
//		this->color = color;
//	}
//	friend void Human::TakeApple(Apple& apple);
//private:
//	int weight;
//	string color;
//};



//int main()
//{
//	Apple apple(200, "Yellow");
//	Human human;
//	human.TakeApple(apple);	
//	return 0;
//}

/*void Human::TakeApple(Apple& apple)
{
	cout << "TakeApple " << "\tweight = " << apple.weight << "\tcolor = " << apple.color << endl;
}
void foo()
{
	cout << sizeof(short int);
}
int main()
{
	foo();
}*/
//int main()
//{
//	/*const size_t colums = 4;
//	const size_t rows = 2;
//	int arr[rows][colums];
//	int s = 0;
//	int max = 0;
//	for (int i = 0; i < rows; i++)
//	{		
//		
//		for (int j = 0; j < colums; j++)
//		{
//			arr[i][j] = rand() % 20;
//			cout << arr[i][j] << " ";
//			s += arr[i][j];
//			if (max < arr[i][j])
//			{
//				max = arr[i][j];
//				
//			}
//			
//		}
//		cout << endl;
//		
//	}
//	
//	cout << "Max =  " << max;*/
//
//	/*cout << endl;
//	cout << s << endl;*/
//	//int x(4);
//	//cout << typeid(&x).name();
//}


