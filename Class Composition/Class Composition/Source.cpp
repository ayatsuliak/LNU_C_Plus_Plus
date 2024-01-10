#include<iostream>
#include<fstream>

using namespace std;

//Визначити базовий тип «телефон»(назва, фірма, ціна).Визначити 2 похідні від нього типи : 
//«мобільний телефон»(колір, об’єм пам’яті), «радіотелефон»(радіус дії, наявність автовідповідача).
//У двох текстових файлах задано дані про телефони двох різних фірм.Зчитати ці дані в один масив  
//і вивести у текстовий файл : 1)всі телефони, посортовані за ціною із зазначенням загальної суми; 
// 2) радіотелефони з автовідповідачем

class Phone
{
protected:
	string name;
	string brand;
	double price;
	char value;
public:
	Phone()
	{
		this->brand = "none";
		this->name = "none";
		this->price = 0;
	}

	Phone(string name, string brand, double price)
	{
		this->brand = brand;
		this->name = name;
		this->price = price;
	}

	double GetPrice()
	{
		return price;
	}

	friend fstream& operator>>(fstream& is, Phone& phone)
	{
		phone.input(is);
		//is >> phone.name >> phone.brand >> phone.price;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Phone& phone)
	{
		os << phone.name << " " << phone.brand << " " << phone.price;
		return os;
	}

	virtual void input(fstream& file)
	{
		file >> value >> name >> brand >> price;
	}
	virtual void print(fstream& file)
	{
		file << name << " " << brand << " " << price << endl;
	}
};

class MobilePhone :public Phone
{
protected:
	string color;
	double memory_capacity;
public:
	MobilePhone() :Phone()
	{
		this->color = "none";
		this->memory_capacity = 0;
	}

	MobilePhone(string color, double memory_capacity, string name, string brand, double price) :Phone(name, brand, price)
	{
		this->color = color;
		this->memory_capacity = memory_capacity;
	}

	friend istream& operator>>(istream& is, MobilePhone& mobile_phone)
	{
		is >> mobile_phone.color >> mobile_phone.memory_capacity;
		return is;
	}
	friend ostream& operator<<(ostream& os, const MobilePhone& mobile_phone)
	{
		os << mobile_phone.color << " " << mobile_phone.memory_capacity;
		return os;
	}

	virtual void input(fstream& file)
	{
		Phone::input(file);
		file >> color >> memory_capacity;
	}
	virtual void print(fstream& file)
	{
		Phone::print(file);
		file <<" "<< color << " " << memory_capacity << endl;;
	}
};

class RadioPhone :public Phone
{
protected:
	double range;
	bool answering_machine;
public:
	RadioPhone() :Phone()
	{
		this->range = 0;
		this->answering_machine = false;
	}

	RadioPhone(double range, bool answering_machine, string name, string brand, double price) :Phone(name, brand, price)
	{
		this->range = range;
		this->answering_machine = answering_machine;
	}

	bool GetAnsweringMachine()
	{
		return answering_machine;
	}

	friend istream& operator>>(istream& is, RadioPhone& radio_phone)
	{
		is >> radio_phone.range >> radio_phone.answering_machine;
		return is;
	}
	friend ostream& operator<<(ostream& os, const RadioPhone& radio_phone)
	{
		os << radio_phone.range << " " << radio_phone.answering_machine;
		return os;
	}

	virtual void input(fstream& file)
	{
		Phone::input(file);
		file >> range >> answering_machine;
	}
	virtual void print(fstream& file)
	{
		Phone::print(file);
		file << range << " " << answering_machine << endl;
	}
};

int main()
{
	fstream F1;
	fstream F2;
	fstream F3;

	F1.open("File1.txt");
	F2.open("File2.txt");
	F3.open("File3.txt", ofstream::app);

	int n, m, k;
	F1 >> n;
	F2 >> m;
	k = m + n;
	char ch;
	Phone** arr_phone = new Phone * [k];
	/*for (int i = 0; i < n; i++)
	{
		arr_phone[i] = new MobilePhone;
		arr_phone[i]->input(F1);
	}*/
	F1 >> ch;
	F2 >> ch;
	for (int i = 0; i < k; i++)
	{
		if (ch == 'p')
		{
			arr_phone[i] = new MobilePhone;	
			arr_phone[i]->input(F1);
		}
		else
		{
			arr_phone[i] = new RadioPhone;
			arr_phone[i]->input(F2);
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr_phone[i]->GetPrice() < arr_phone[j]->GetPrice())
			{
				swap(arr_phone[i], arr_phone[j]);
			}
		}
	}
	double sum_price = 0;
	for (int i = 0; i < n; i++)
	{
		sum_price += arr_phone[i][0].GetPrice();
	}
	for (int i = 0; i < n; i++)
	{
		arr_phone[i]->print(F3);
	}
	F3 <<"Total price: "<< sum_price << endl << endl;

	for (int i = 0; i < m; i++)
	{
		if(arr_phone[i])
		arr_phone[i]->print(F3);
	}
	
	F1.close();
	F3.close();
	F2.close();
	delete[] arr_phone;
	return 0;
}