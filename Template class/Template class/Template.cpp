#include<iostream>
#include<ctime>
#include<fstream>

using namespace std;

//Визначити шаблонний клас для зберігання даних про деякий об’єкт, дату його виготовлення та термін придатності(в днях).
//В класі визначити оператори << I >> , метод, який повертає дату кінцевого терміну придатності.Також визначити структуру Молоко з полями назва та жирність, 
//оператори << I >> .Використати шаблонний клас з двома типами – string та Молоко, утворити відповідні масиви.
//Ввести дані про декілька таких об’єктів і видрукувати для кожного кінцевий термін придатності.

struct Milk
{
	string name;
	double fat_content;

	friend istream& operator>>(istream& is, Milk& milk)
	{
		is >> milk.name >> milk.fat_content;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Milk& milk)
	{
		os << milk.name << " " << milk.fat_content;
		return os;
	}
};

template<typename T>
class Object
{
private:
	T object;
	tm date_of_manufacture;
	tm expiration_date;
public:
	friend istream& operator>>(istream& is, Object& object)
	{
		is >> object.object >> object.date_of_manufacture.tm_mday >> object.date_of_manufacture.tm_mon >> object.date_of_manufacture.tm_year;
		is >> object.expiration_date.tm_mday >> object.expiration_date.tm_mon >> object.expiration_date.tm_year;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Object& object)
	{
		char fulldate[50];
		os << object.object << " ";
		if (strftime(fulldate, sizeof(fulldate), "%d/%m/%y", &object.date_of_manufacture));
		os << fulldate << " ";
		if (strftime(fulldate, sizeof(fulldate), "%d/%m/%y", &object.expiration_date));
		os << fulldate << endl;
		return os;
	}

	tm GetExpirationDate()
	{
		return expiration_date;
	}

	T GetObject()
	{
		return object;
	}

	~Object(){}
};

int main() 
{ 
	int n;
	fstream F1;
	fstream F2;
	fstream F3;
	F1.open("File1.txt");
	F2.open("File2.txt");
	F3.open("File3.txt");
	F1 >> n;
	Object<string>* arr = new Object<string>[n];
	for (size_t i = 0; i < n; i++)
	{
		F1 >> arr[i];
	}

	for (size_t i = 0; i < n; i++)
	{
		F3 << arr[i].GetObject() << ": " << arr[i].GetExpirationDate().tm_mday << "/" << arr[i].GetExpirationDate().tm_mon << "/" << arr[i].GetExpirationDate().tm_year << endl;
	}

	F3 << "\t---Milk---" << endl;

	int m;
	F2 >> m;
	Object<Milk>* arr2 = new Object<Milk>[m];
	for (size_t i = 0; i < m; i++)
	{
		F2 >> arr2[i];
	}

	for (size_t i = 0; i < m; i++)
	{
		F3 << arr2[i].GetObject().name << ": " << arr2[i].GetExpirationDate().tm_mday << "/" << arr2[i].GetExpirationDate().tm_mon << "/" << arr2[i].GetExpirationDate().tm_year << endl;		
	}

	delete[] arr;
	delete[] arr2;
	F1.close();
	F2.close();
	F3.close();
		
	return 0;
}