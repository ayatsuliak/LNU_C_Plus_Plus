#include<iostream>
#include<string>
#include<fstream>
#include<memory>

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////
                       //Enum
///////////////////////////////////////////////////////////////////////////////////////////////
enum PCState
{
	OFF,
	ON,
	SLEEP
};

class PC
{
private:
	PCState state;
public:
	
	PCState GetState()
	{
		return state;
	}
	void SetState(PCState state)
	{
		this->state = state;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////
                        //Класи шаблони
//////////////////////////////////////////////////////////////////////////////////////////////////

class Point
{
private:
	int a, b, c;
public:
	Point()
	{
		a = b = c = 0;
	}
	Point(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

template<typename T1>  //typename==class
class TypeSize
{
protected:
	T1 value;
public:
	TypeSize(T1 value)
	{
		this->value = value;
	}

	void DataTypeSize()
	{
		cout << "value: " << sizeof(value)<< endl;
	}
};

template<typename T1>  //потрібно створювати новий тип для наслідуваного класу
class TypeInfo :public TypeSize<T1>  //буде використовувати той тип, який ми введемо в TypeInfo
{
public:
	TypeInfo(T1 value):TypeSize(value)
	{

	}

	void ShowTypeName()
	{
		//cout << "Type name: " << typeid(value).name() << endl;
	}
};

///////////////////////////////////////////////////
        //Спеціалізація шаблону
///////////////////////////////////////////////////

template<typename T>
class Printer
{
private:
	T value;
public:
	void Print(T value)
	{
		cout << value << endl;
	}
};

template<>  //спеціалізований шаблон, потрібний для того, щоб обробляти якусь конкретну ситуації(string)
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << "_______" << value << "_______" << endl;
	}
};

//int main()
//{
//	PC pc;
//	pc.SetState(PCState::OFF);
//
//	switch (pc.GetState())
//	{
//	case PCState::OFF: cout << "OFF" << endl;
//		break;
//	case PCState::ON: cout << "ON" << endl;
//		break;
//	case PCState::SLEEP: cout << "SLEEP" << endl;
//		break;
//	}
//
//	//////////////////////////////////////////////////////////////////////////////////////////////////
//						//Класи шаблони
//	//////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Point p(2, 4, 6);
//	int a = 9;
//
//	TypeInfo<Point> type_info(p);  //шаблоном може бути клас, можемо передавати декілька шаблонів
//	type_info.DataTypeSize();
//	type_info.ShowTypeName();  //показує який тип ми викорис
//
//	///////////////////////////////////////////////////
//		//Спеціалізація шаблону
//	///////////////////////////////////////////////////
//
//	Printer<string> pr;
//	pr.Print("Hello World");
//
//	///////////////////////////////////////////////////
//		//Smart pointers
//	///////////////////////////////////////////////////
//	       
//	shared_ptr<int> p1(new int(5));  //найбільш підходячий розумний вказівник, бо в ньому гарно працює реалізація видалення
//
//	shared_ptr<int> p2(p1);  //підключити бібліотеку memory
//
//	unique_ptr<int> p1(new int(6));
//
//	unique_ptr<int> p2;
//
//	int* p = p1.get();  //присвоюємо за допомогою get
//	p1.reset();  //видаляє дані
//	
//
//	p2 = move(p1);  //тобто присвоює вказівник за допомогою move
//	p2.swap(p1);  //те саме
//
//	int SIZE;
//	cin >> SIZE;
//	shared_ptr<int[]> ptr(new int[SIZE]);  //потрібно вказувати в <> [] аби вказати що це масив. А де ptr то ми можемо це реаліз окремо
//	for (size_t i = 0; i < SIZE; i++)
//	{
//		ptr[i] = rand() % 10;
//		cout << ptr[i] << " ";
//	}
//}