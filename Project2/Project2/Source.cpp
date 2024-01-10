#include<iostream>
#include<ostream>
#include<fstream>
using namespace std;
//class Apple 
//{
//private:
//	int weight;
//	string color;
//public:
//	static int s_value;
//	Apple(int weight, string color)
//	{
//		this->color = color;
//		this->weight = weight;
//		s_value++;
//	}
//};
//int main()
//{
//	Apple apple(200, "red");
//	Apple apple(150, "yellow");
//	cout << apple.s_value << endl;
//}


//class Vector
//{
//private:
//	int* array;
//	unsigned size;
//public:
//	//це перший варіант але не знаю чи правильний
//
//	/*Vector(int* array, unsigned size)
//	{
//		this->array = array;
//		this->size = size;
//	}*/
//
//	//це інший варіант так як в презентації
//	Vector() :array(0), size(0) {};
//
//	Vector(int* a, unsigned s)
//	{
//		array = new int[size];
//		this->size = s;
//		for (int i = 0; i < s; i++)
//		{
//			array[i] = a[i];
//		}
//		cout << "It's work" << endl;
//	}
//	~Vector()
//	{
//		if (array != 0)
//		{
//			delete[] array;
//		}
//	}
//	Vector(const Vector& v);
//	void input();
//	Vector& operator=(const Vector& v);
//	const Vector& operator[](size_t pos);
//	friend istream& operator>>(istream& is, Vector& v);
//	friend ostream& operator<<(ostream& os, const Vector& v);
//};
//Vector& Vector::operator=(const Vector& v)
//{
//	if (this != &v)
//	{
//		this->size = v.size;
//		if (array != 0)
//		{
//			delete[] array;
//			array = new int[v.size];
//			for (int i = 0; i < v.size; i++)
//			{
//				array[i] = v.array[i];
//			}
//		}
//	}
//	return *this;
//}
//Vector::Vector(const Vector& v)
//{
//	this->size = v.size;
//	this->array = new int[v.size];
//	for (int i = 0; i < v.size; i++)
//	{
//		array[i] = v.array[i];
//	}
//}
//void Vector::input()
//{
//	cin >> size;
//	array = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		cin >> array[i];
//	}
//}
//istream& operator>>(istream& is, Vector& v)
//{
//	if (v.array != 0)
//	{
//		delete[] v.array;
//	}
//	is >> v.size;
//	v.array = new int[v.size];
//	for (int i = 0; i < v.size; i++)
//	{
//		is >> v.array[i];		
//	}
//	return is;
//}
//ostream& operator<<(ostream& os, const Vector& v)
//{
//	os << "\nVector size = " << v.size << endl;
//	os << "Vector elements : \n";
//	for (int i = 0; i < v.size; i++)
//	{
//		os << v.array[i] << " ";
//	}
//	return os;
//}
//int& Vector::operator[](size_t pos)
//{
//	if (pos < size)
//	{
//		return array[pos];
//	}
//}
//void main()
//{
//	Vector v1, v2;
//	cin >> v1 >> v2;
//	cout << "vector1" << v1;
//}


//class One
//{
//public:
//	One()
//	{
//		cout << "It's One";
//	}
//};
//class Two
//{
//public:
//	Two(const Two& t)
//	{
//		cout << "It's const Two";
//	}
//	Two(const One&)
//	{
//		cout << "It's Two which is One";
//	}
//};
//void f(Two)
//{
//	cout << "It's f";
//}
//void main()
//{
//	One one;
//	f(one);
//}


//class Complex 
//{
//    double Re, Im;    
//public:
//    Complex(){}
//    Complex(double r, double i) 
//    {
//        Re = r;
//        Im = i;
//    }
//    Complex(Complex& c) 
//    {
//        Re = c.Re;
//        Im = c.Im;
//    }
//
//    ~Complex() {}
//    Complex& operator = (Complex& c) 
//    {
//        Re = c.Re;
//        Im = c.Im;
//
//        return *this;
//    }
//    Complex operator + (Complex& c) 
//    {
//        Complex temp;
//        temp.Re = Re + c.Re;
//        temp.Im = Im + c.Re;
//        return temp;
//    }
//    Complex operator - (Complex& c) 
//    {
//        Complex temp;
//        temp.Re = Re - c.Re;
//        temp.Im = Im - c.Re;
//        return temp;
//    }
//    Complex operator * (Complex& c) 
//    {
//        Complex temp;
//        temp.Re = Re * c.Re;
//        temp.Im = Re * c.Im;
//        return temp;
//    }
//    Complex operator / (Complex& c) 
//    {
//        Complex temp;
//        double r = c.Re * c.Re + c.Im * c.Im;
//        temp.Re = (Re * c.Re + Im * c.Im) / r;
//        temp.Re = (Im * c.Re - Re * c.Im) / r;
//        return temp;
//    }
//    friend ostream& operator<<(ostream& os, Complex&); 
//    friend istream& operator>>(istream& is, Complex&); 
//    operator double();    
//    Complex& operator<(Complex& c)
//    {
//        this->Re < c.Re;
//        return *this;
//    }
//};
//ostream& operator<<(ostream& os, Complex& c)
//{
//    os << "(" << c.Re << ") + I (" << c.Im << "\n";
//    return os;
//}
//istream& operator>>(istream& is, Complex& c)
//{
//    is >> c.Re >> c.Im;
//    return is;
//}
//Complex::operator double()
//{
//    return Re, Im;
//}
//int main()
//{
//    cout << "Size: " << endl;
//    int n;
//    cin >> n;
//    Complex* arr = new Complex[n];
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        sum = sum + arr[i];
//    }
//    double average;
//    average = sum / n;
//    double product = 1;
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[n] < arr[i])
//        {
//            product = product * arr[i];
//        }
//    }
//    cout << "Sum: " << sum << endl;
//    cout << "Average: " << average << endl;
//    cout << "Product: " << product << endl;
//}

//constexpr int sum(int a, int b)
//{
//	return a + b;
//}
//
//void func()
//{
//	constexpr int c = sum(5, 12); 
//}
//void main()
//{
//	void func();
//}

//class Street
//{
//private:
//	string name_street;
//	int number;
//public:
//	Street(){}
//	friend istream& operator>>(istream& is, Street& street)
//	{
//		is >> street.name_street;
//		cout << endl;
//		is >> street.number;
//		cout << endl;
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, const Street& street)
//	{
//		os << "Street name - " << street.name_street << endl;
//		os << "House number - " << street.number << endl;	
//		return os;
//	}
//	string SetNameStreet(string name_street)
//	{
//		this->name_street = name_street;
//	}
//	void SetNumber(int number)
//	{
//		this->number = number;
//	}
//	string GetNameStreet()
//	{
//		return name_street;
//	}
//	int GetNumber()
//	{
//		return number;
//	}
//};
//
//class City
//{
//private:
//	Street* array;
//	string city_name;
//	int number_street;
//public:
//	City(){}
//	City(const City& city)
//	{
//		this->number_street = city.number_street;
//		this->city_name = city.city_name;
//		this->array = new Street[number_street];
//		for (int i = 0; i < number_street; i++)
//		{
//			this->array[i] = city.array[i];
//		}
//	}
//	City(Street* array, int number_street, string city_name)
//	{
//		this->number_street = number_street;
//		this->city_name = city_name;
//		this->array = new Street[number_street];
//		for (int i = 0; i < number_street; i++)
//		{
//			this->array[i] = array[i];
//		}
//	}
//	Street& operator[](int pos)
//	{
//		return array[pos];
//	}
//	City& operator=(const City& city)
//	{
//		if (this != &city)
//		{
//			delete[] array;
//		}
//		this->number_street = city.number_street;
//		this->city_name = city.city_name;
//		this->array = new Street[number_street];
//		for (int i = 0; i < number_street; i++)
//		{
//			this->array[i] = city.array[i];
//		}
//		return *this;
//	}
//	~City()
//	{
//		delete[] array;
//	}
//	friend istream& operator>>(istream& is, City& city)
//	{
//		is >> city.city_name;
//		is >> city.number_street;
//		city.array = new Street[city.number_street];
//		for (int i = 0; i < city.number_street; i++)
//		{
//			is >> city.array[i];
//		}
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, const City& city)
//	{
//		os << "City name - " << city.city_name << endl;
//		os << "Number street - " << city.number_street << endl;
//		os << "Name street: ";
//		for (int i = 0; i < city.number_street; i++)
//		{
//			os << city.array[i] << " ";
//		}
//		return os;
//	}
//	void SetNumberStreet(int number_street)
//	{
//		this->number_street = number_street;
//	}
//	int GetNumberStreet()
//	{
//		return number_street;
//	}
//	string SetCityName(string city_name)
//	{
//		this->city_name = city_name;
//	}
//	string GetCityName()
//	{
//		return city_name;
//	}
//	Street* GetStreetName()
//	{
//		return array;
//	}
//	void SetStreetName(Street* array)
//	{
//		this->array = array;
//	}
//};
//int main()
//{
//	fstream F;
//	F.open("city.txt");
//	City arr[2];
//	for (int i = 0; i < 2; i++)
//	{
//		F >> arr[i];
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	//сортує за кількістю вулиць
//	if (arr[0].GetNumberStreet() < arr[1].GetNumberStreet())
//	{
//		swap(arr[0], arr[1]);
//	}
//	else
//	{
//		cout << arr[0];
//		cout << arr[1];
//	}
//	//виводить вулиці
//	if (arr[0].GetCityName() > arr[1].GetCityName())
//	{
//		cout << arr[0].GetStreetName();
//	}
//	else
//	{
//		cout << arr[1].GetStreetName();
//	}
//	City city;
//	//новий об'єкт який копіює місто з найменшою кількістю вулиць
//	if (arr[0].GetNumberStreet() < arr[1].GetNumberStreet())
//	{
//		city = arr[0];
//	}
//	else
//	{
//		city = arr[1];
//	}
//	delete[] arr;
//}