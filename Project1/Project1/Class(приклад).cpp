#include<iostream>
#include<Windows.h>
#include<ctime>
#include<ostream>
#include<fstream>
#include<string>
#include<locale>
#include<cmath>
using namespace std;
class Weather
{
	int temperature;
	int pressure;
	char wind;
	int opadu;
	string s_wind;
	string s_opadu;
public:
	Weather()
	{
		opadu = 0;
		pressure = 0;
		temperature = 0;
		wind = 'z';
	}
	Weather(int t, int o, int p, char w)
	{
		this->temperature = t;
		this->pressure = p;
		this->opadu = o;		
		this->wind = w;
		switch (w)
		{
		case 't':s_wind = "tyho";
			break;
		case 'l':s_wind = "legenko";
			break;
		case'p':s_wind = "pomirnyi";
			break;
		case's':s_wind = "sulnyi";
			break;
		default:
			break;
		}
	}
	friend istream& operator>>(istream& in, Weather& w)
	{
		cout << "Temperature: " << endl;
		in >> w.temperature;
		cout << "Pressure: " << endl;
		in >> w.pressure;
		cout << "Opadu: " << endl;
		in >> w.opadu;
		cout << "Wind: " << endl;
		in >> w.wind;
		return in;
	}
	int GetTemperature()
	{
		return temperature;
	}
	char GetWind()
	{
		return wind;
	}
	friend ostream& operator<<(ostream& out, Weather& w)
	{
		out << w.temperature << "C" << "\t\t";
		out << w.pressure << "\t";
		out << w.wind << "\t";
		out << w.opadu << endl;
		return out;
	}
};

void sort(Weather* mas, unsigned n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i].GetTemperature() > mas[j].GetTemperature())
			{
				swap(mas[i], mas[j]);
			}
		}
	}
}
int main()
{
	double sr_temp = 0;
	Weather* arr = new Weather[12];
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}
	sort(arr, 3);
	cout << "Temperature  Pressure  Wind_force  Opadu\n";
	for (int i = 0; i < 3; i++)
	{
		cout << arr[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (arr[i].GetWind() == 't')
		{
			sr_temp += arr[i].GetTemperature();
		}
	}
	cout << "Averange temperature of windless days = " << sr_temp / 3 << endl;
	return 0;
}





//class Paralelepiped
//{
//private:
//	double length;
//	double height;
//	double breadth;
//public:
//	Paralelepiped()
//	{
//		length = 0;
//		height = 0;
//		breadth = 0;
//	}
//
//	Paralelepiped(double length, double height, double breadth)
//	{
//		cout << "Hello" << endl;
//		this->breadth = breadth;
//		this->height = height;
//		this->length = length;
//
//	}
//	Paralelepiped(const Paralelepiped& prl)
//	{
//		this->breadth = prl.breadth;
//		this->height = prl.height;
//		this->length = prl.length;
//	}
//	void Print();
//	double volume();
//	short equalVolume(Paralelepiped& prl);
//};
//Paralelepiped read()
//{
//	int a, b, c;
//	cout << "Input a, b, c: " << endl;
//	cin >> a >> b >> c;
//	return Paralelepiped(a, b, c);
//}
//int main() 
//{ 
//	int const n = 3;
//	Paralelepiped arr[n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = read();	
//		cout << arr[i].volume() << endl;
//	}
//	for (int i = 0; i < n-1; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			if (arr[i].equalVolume(arr[j]) == -1)
//			{
//				Paralelepiped temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{		
//		cout << arr[i].volume() << endl;
//	}
//
//	
//}
//void Paralelepiped::Print()
//{
//	cout << breadth << height << length << endl;
//}
//
//double Paralelepiped::volume()
//{
//	return length * breadth * height;
//}
//short Paralelepiped::equalVolume(Paralelepiped& prl)
//{
//	if (this->volume() == prl.volume())
//	{
//		return 0;
//	}
//	else if (this->volume() < prl.volume())
//	{
//		return -1;
//	}
//	else
//	{
//		return 1;
//	}
//}


  //factorial
//int rFact(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * rFact(n - 1);
//	}
//
//}
//int fact(int n)
//{
//	int f = 1;
//	for (int i = 0; i < n; i++)
//	{
//		f *= i;
//	}
//	return f;
//}




//class Student
//{
//    string firstName;
//    string lastName;
//public:
//    Student() 
//    {
//
//    }
//    Student(string firstName, string lastName) 
//    {
//        this->firstName = firstName;
//        this->lastName = lastName;
//    }
//    friend istream& operator>> (istream& in, Student& student)
//    {
//        in >> student.firstName >> student.lastName;
//        return in;
//    }
//    friend ostream& operator<< (ostream& out, Student& student)
//    {
//        out << student.firstName << " " << student.lastName;
//        return out;
//    }
//    string getFirstName() 
//    {
//        return firstName;
//    }
//    void setFirstName(string firstName) 
//    {
//        this->firstName = firstName;
//    }
//    string getLastName() 
//    {
//        return lastName;
//    }
//    void setLastName(string lastName) 
//    {
//        this->lastName = lastName;
//    }
//};
//
//class Group
//{
//    Student* students;
//    int size;
//    string name;
//    int year;
//public:
//    Group() 
//    {
//        this->size = 0;
//        this->name = "";
//        this->year = 1970;
//        this->students = new Student[size];
//    }
//    Group(Student* students, int size, string name, int year) 
//    {
//        this->size = size;
//        this->name = name;
//        this->year = year;
//        this->students = new Student[size];
//        for (int i = 0; i < size; i++) 
//        {
//            this->students[i] = students[i];
//        }
//    }
//    Group(const Group& group)
//    {
//        this->size = group.size;
//        this->name = group.name;
//        this->year = group.year;
//        this->students = new Student[size];
//        for (int i = 0; i < size; i++) 
//        {
//            this->students[i] = group.students[i];
//        }
//    }
//    Group& operator=(const Group group) 
//    {
//        this->size = group.size;
//        this->name = group.name;
//        this->year = group.year;
//        this->students = new Student[size];
//        for (int i = 0; i < size; i++) 
//        {
//            this->students[i] = group.students[i];
//        }
//        return*this;
//    }
//    Student& operator[](int n)
//    {
//        return students[n];
//    }
//    ~Group()
//    {
//        delete[] students;
//    }
//    friend istream& operator>> (istream& in, Group& group)
//    {
//        in >> group.name >> group.size >> group.year;
//        group.students = new Student[group.size];
//        for (int i = 0; i < group.size; i++) 
//        {
//            in >> group.students[i];
//        }
//        return in;
//    }
//    friend ostream& operator<< (ostream& out, Group& group)
//    {
//        out << group.name << " " << group.size << " " << group.year << endl;
//        for (int i = 0; i < group.size; i++) 
//        {
//            out << "\t" << group.students[i] << endl;
//        }
//        return out;
//    }
//    int getSize() 
//    {
//        return size;
//    }
//    string getName() 
//    {
//        return name;
//    }
//    int getYear() 
//    {
//        return year;
//    }
//    Student* getStudents() 
//    {
//        return students;
//    }
//    int setSize(int size)
//    {
//        this->size = size;
//    }
//    string setName(string name) 
//    {
//        this->name = name;
//    }
//    int setYear() 
//    {
//        this->year = year;
//    }
//    Student setStudents(Student* students) 
//    {
//        this->students = students;
//    }
//};
//void main()
//{
//    fstream F;
//    F.open("Groups.txt");
//    int sizeS;
//    F >> sizeS;
//    Group* groups = new Group[sizeS];
//    for (int i = 0; i < sizeS; i++)
//    {
//        F >> groups[i];
//    }
//
//    cout << "Sorted groups by name: " << endl;
//    for (int i = 0; i < sizeS - 1; i++)
//    {
//        for (int j = i + 1; j < sizeS; j++)
//        {
//            if (groups[j].getName() < groups[i].getName())
//            {
//                swap(groups[i], groups[j]);
//            }
//        }
//    }
//    for (int i = 0; i < sizeS; i++)
//    {
//        cout << groups[i];
//    }
//    cout << "Sorted groups by year: " << endl;
//    for (int i = 0; i < sizeS - 1; i++)
//    {
//        for (int j = i + 1; j < sizeS; j++)
//        {
//            if (groups[j].getYear() > groups[i].getYear())
//            {
//                swap(groups[i], groups[j]);
//            }
//        }
//    }
//    for (int i = 0; i < groups[0].getSize(); i++)
//    {
//        /*cout << groups[0].getStudents()[i]<< endl;*/
//        cout << groups[0][i] << endl;
//    }
//    cout << "Sorted groups by size: " << endl;
//    for (int i = 0; i < sizeS - 1; i++)
//    {
//        for (int j = i + 1; j < sizeS; j++)
//        {
//            if (groups[j].getSize() < groups[i].getSize())
//            {
//                swap(groups[i], groups[j]);
//            }
//        }
//    }
//    Group newGroup = groups[0];
//    cout << newGroup << endl;
//}