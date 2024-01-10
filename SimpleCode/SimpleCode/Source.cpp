#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Apple
{
private:
	static int Count;
	int weight;
	string color;
	int id;
public:
	Apple(int weight, string color)
	{
		this->color = color;
		this->weight = weight;
		Count++;
		id = Count;
	}

	int GetId()
	{
		return id;
	}

	string GetColor()
	{
		return color;
	}

	static int GetCount()
	{
		return Count;
	}
	
	static void ChangeColor(Apple& apple, string color)
	{
		apple.color = color;
	}
};

int Apple::Count = 0;

///////////////////////////////////////////////////////////////////////////

class Image
{
private:
	class Pixel
	{
	private:
		int r;
		int b;
		int g;
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		string GetInfo()
		{
			return "Pixel: r = " + to_string(r) + " g = " + to_string(g) + " b = " + to_string(b);
		}
	};
	static const int LENGHT = 3;

	Pixel pixels[LENGHT]
	{
		Pixel(0,4,46),
		Pixel(5,2,67),
		Pixel(3,2,6)
	};
public:
	void GetInfoImage()
	{
		for (int i = 0; i < LENGHT; i++)
		{
			cout << "#" << i << " " << pixels[i].GetInfo() << endl;
		}
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                //�����������//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Weapon
{
public:
	virtual void Shoot() = 0;    //����������� ����� � �������� ���� ��� �����������
	//������ ������������ ����� �� �������� � �� ��������� ������
};

class Gun : virtual public Weapon
{
public:
	void Shoot()
	{
		cout << "BANG!" << endl;
	}
};

class SubmachineGun : virtual public Gun
{
public:
	void Shoot()
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};

class Bazooka : virtual public Weapon
{
public:
	void Shoot()
	{
		cout << "BADABOOM!!!" << endl;
	}
};

class Knife : virtual public Weapon
{
public:
	void Shoot()
	{
		cout << "VJUH!!!" << endl;
	}
};

class Player
{
public:
	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}
};

/////////////////////////////////////////////////////////////////

//class Human
//{
//private:
//	string name;
//	int age;
//	int weight;
//public:
//	Human(string name)
//	{
//		this->name = name;
//		this->age = 0;
//		this->weight = 0;
//	}
//
//	Human(string name, int age) :Human(name)
//	{
//		this->age = age;
//	}
//
//	Human(string name, int age, int weight) :Human(name, age)           //���������� �����������
//	{
//		this->weight = weight;
//	}
//};

////////////////////////////////////////////////

class Msg
{
private:
	string msg;
public:
	Msg(string msg)
	{
		this->msg = msg;
	}

	string GetMsg()
	{
		return msg;
	}
};

class BraketsMsg : virtual public Msg
{
public:
	BraketsMsg(string msg) : Msg(msg)
	{

	}

	string GetMsg()
	{
		return "[" + ::Msg::GetMsg() + "]";    // ��������� ���������� ����� �������� �����(������ ���� ������ �������)
	}
};

class Printer
{
public:
	void Print(Msg* msg)
	{
		cout << msg->GetMsg() << endl;
	}
};

///////////////////////////////////////////////////

class Car
{
public:
	void Use()
	{
		cout << "I go" << endl;
	}
};

class Airplain
{
	void Use()
	{
		cout << "I fly" << endl;
	}
};

class AirCar : public Car, public Airplain    //������������ �����������
{
                                              //������� ������� ������������ �������� �� ������� �� ���������� 
};

///////////////////////////////////////////////////////////////////
          //���������
///////////////////////////////////////////////////////////////////

class IBicycle
{
public:
	virtual void TwistTheWhell() = 0;
	virtual void Ride() = 0;
};

class SimpleBicycle :public IBicycle
{
public:
	void TwistTheWhell() override
	{
		cout << "TwistTheWhell() SimpleBicycle" << endl;
	}
	void Ride() override
	{
		cout << "Ride() SimpleBicycle" << endl;
	}
};

class Human
{
public:
	void RideOn(IBicycle& bicycle)
	{
		cout << "TwistTheWhell" << endl;
		bicycle.TwistTheWhell();
		cout << endl;
		cout << "Ride" << endl;
		bicycle.Ride();
	}
};

/////////////////////////////////////////////////////////////////
           //���������� � ��������� ����������� 
/////////////////////////////////////////////////////////////////

class Component
{
	
public:
	string companyName;
	Component(string companyName)
	{
		cout << "ctor Component" << endl;
		this->companyName = companyName;
	}
};

class GPU :public Component
{
public:
	GPU(string companyName):Component(companyName)
	{
		cout << "ctor GPU" << endl;
	}
};

class Memory :public Component
{
public:
	Memory(string companyName) :Component(companyName)
	{
		cout << "ctor Memory" << endl;
	}
};

class GraphicCard :public GPU, public Memory
{
public:
	GraphicCard(string GPUCompanyName, string MemoryCompanyName) :GPU(GPUCompanyName), Memory(MemoryCompanyName)
	{
		cout << "ctor GraphicCard" << endl;
	}
};

/////////////////////////////////////////(� ������� ���� ����� ��������������� ��� ������ ����� ��� �����)
//(��� ����� ���, ���� ��� �� ������� ��������������� ����� ���� ������� �����������)
//��������� ��� ���������� �����������
class Character
{
public:
	int HP;
	Character()
	{
		cout << "ctor Character" << endl;
	}
};

class Orc :public virtual Character          //virtual ����� �� ����������/��������� ����������� ��� ����, ��� �� ��������������� ������� ���� ������� ����
{
public:
	Orc()
	{
		cout << "ctor Orc" << endl;
	}
};

class Warrior :public virtual Character
{
public:
	Warrior()
	{
		cout << "ctor Warrior" << endl;
	}
};

class OrcWarrior :public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "ctor OrcWarrior" << endl;
	}
};

//////////////////////////////////////////////////////////////////////////////////
                       //���� ���� �������� � ����
//////////////////////////////////////////////////////////////////////////////////

class Point
{
private:
	int x, y, z;
public:
	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Print()
	{
		cout << "X: " << x << "\tY: " << y << "\tZ: " << z << endl;
	}
};

template <typename T>
const T& max(const T& a, const T& b)  //������� ��� ����������� �����
{
	return (a > b) ? a : b;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                   //Exception
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MyException :public exception
{
private:
	int data_state;
public:
	MyException(char* msg, int data_state) :exception(msg)
	{
		this->data_state = data_state;
	}

	int GetDataState()
	{
		return data_state;
	}
};

void Foo(int value)
{
	if (value < 0)
	{
		throw exception("Error");   //throw "����" ���� ������� � catch
	}                               //� catch �� ���� ���������� ��� ���, ���� �� �������(int), ��� �����������
	if (value == 1)
	{
		//throw MyException("Number is 1", value);
	}
	cout << value << endl;          //���� ����� ������ exeption
}

//int main()
//{
//	//OrcWarrior orcw;
//
//	//////////////////////////////////////////////////////////////
//
//	/*GraphicCard gc("AMD", "Samsung");*/
//
//	//////////////////////////////////////////////////////////////
//
//	/*SimpleBicycle sb;
//	Human h;
//	h.RideOn(sb);*/
//
//	///////////////////////////////////////////////////////////
//
//
//	/*Apple a1(150, "green");
//	Apple a2(100, "yellow");
//	Apple a3(200, "Red");
//
//	Apple::ChangeColor(a1, "Red");
//	cout << a1.GetColor() << endl;
//
//	cout << Apple::GetCount() << endl;*/
//
//	//////////////////////////////////////////////////////
//
//	/*Image img;
//	img.GetInfoImage();*/
//
//	////////////////////////////////////////////////
//
//	//Gun gun;
//	//SubmachineGun subgun;
//	//Bazooka bazooka;
//
//	////Gun* weapon = &gun;
//	////weapon->Shoot();
//	//cout << "===========================" << endl;
//	//Gun* weapon = &subgun;
//	////weapon->Shoot();
//	//
//	//Player player;
//	//player.Shoot(&subgun);
//
//	//////////////////////////////////////////////////
//
//	/*Msg m1("Hello!");
//	Printer print;
//	print.Print(&m1);
//	cout << "===============================" << endl;
//	BraketsMsg m2("Hello!");
//	print.Print(&m2);*/
//
//	/////////////////////////////////////////////////////
//
//	//AirCar ar;
//	//((Car)ar).Use();        //������������� ���� ��� �������������� �����������(���� � ������� ������ �� ��� ������� ����� ����� ������� ��)
//
//	////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////
//
//
//	////////////////////////////////////////////////////////////////
//				//������ � �������
//	////////////////////////////////////////////////////////////////
//	
//	//string path = "MyFile.txt";     
//	//������ ���������� ���� � ���� �� �������� ���(����� ������ �/� cin)
//	//ofstream fout;
//	//fout.open(path, ofstream::app);    //ofstream::app ������� ��� ��, �� ��� ������ ������� �������� ��� �����
//	//if (!fout.is_open())  //is_open ������� �� �������� ����
//	//{
//	//	cout << "Error" << endl;
//	//}
//	//else
//	//{
//	//	int a;
//	//	for (int i = 0; i < 5; i++)
//	//	{
//	//		cout << "Write number! ";
//	//		cout << endl;
//	//		cin >> a;
//	//		fout << a;        //fout �� ����� ������� ��� � ����
//	//		fout << "\t";
//	//	}  
//	//}
//	//fout.close();    //��������� ��� ����, ��� ����� �� �������� ��� �����
//
//	//ifstream fin;
//	//fin.open(path);
//	//if (!fin.is_open())
//	//{
//	//	cout << "Error" << endl;
//	//}
//	//else
//	//{
//	//	//char ch;
//	//	//while (fin.get(ch))  //get ������ �������� � ���������� � char
//	//	//{
//	//	//	cout << ch;      //��� ����������� ����������
//	//	//}
//	//	string str;
//	//	while (!fin.eof())   //eof ���� ����� �����
//	//	{
//	//		str = "";   //��� �������� ����� eof ��������� ����� ������� ����� str
//	//		getline(fin, str);   //� fin ����� � ������ � str
//	//		cout << str << endl;
//	//	}
//	//}
//	//fin.close();
//
//	Point point(3, 23, 66);
//
//	//ofstream fout;
//	//fout.open("myFile.txt", ofstream::app);
//	//if (!fout.is_open())  //is_open ������� �� �������� ����
//	//{
//	//	cout << "error" << endl;
//	//}
//	//else
//	//{
//	//	int a;
//	//	for (int i = 0; i < 5; i++)
//	//	{
//	//		fout.write((char*)&point, sizeof(Point));   //������ ��������� ������������ ������ ��'���� � ������ ���, ������ ����� ����� ������ �����
//	//	}  
//	//}
//	//fout.close();
//
//
//	////////�������/////////////////
//
//	//ifstream fin;
//	//string path = "myFile.tx";
//	//fin.exceptions(ifstream::badbit | ifstream::failbit);
//	//
//	//try                                            //��� ���� �������� ���� ����������            
//	//{                                              //���� ��� ��, �� ���� ���������� ���� ������
//	//	cout << "We probyem open file" << endl;    //� ���� �, �� ���� ���� �����, � ����� � �������
//	//	                                           //������� � catch � ������ �������
//	//	fin.open(path);
//
//	//	cout << "We open this file" << endl;
//	//}
//	//catch (const std::exception& ex)
//	//{
//	//	cout << ex.what() << endl;
//	//	cout << "Error open file";
//	//}
//
//	//388 �����
//	//try
//	//{
//	//	Foo(1);
//	//}
//	//catch (MyException& ex)  //�������� � ���� �-���
//	//{
//	//	cout << ex.what() << endl;    //� � ��� what ���������� �� �������, ��� � ����� �-��� ���������
//	//}
//	//catch (...)                       //���� ������� ��� ����, ��� ��������� �������, ��� ���� �� �� �����
//	//{                                 //���� ��� ��� ����������(��������� ������� ������������)
//	//	cout << "Error, but we don't know what a type" << endl;
//	//}
//	
//	try
//	{
//		Foo(1);
//	}
//	//�������� ������� ����������
//	catch (MyException& ex)  //�������� � ���� �-���
//	{
//		cout << "Block 1" << ex.what() << endl;    //� � ��� what ���������� �� �������, ��� � ����� �-��� ���������
//		cout << "Value" << ex.GetDataState() << endl;
//	}
//	catch (exception& ex)
//	{
//		cout << "Block 1" << ex.what() << endl;
//	}
//	catch (...)                       //���� ������� ��� ����, ��� ��������� �������, ��� ���� �� �� �����
//	{                                 //���� ��� ��� ����������(��������� ������� ������������)
//		cout << "Error, but we don't know what a type" << endl;
//	}
//	catch (exception& ex)
//	{
//		throw;  //������� �����(�������� �������� ������)
//	}
//	
//
//	return 0;
//}

