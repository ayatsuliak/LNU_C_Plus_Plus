#include<iostream>
#include<Windows.h>
#include<ctime>
#include<ostream>
#include<string>
#include<locale>
#include<cmath>
#include<fstream>
using namespace std;

      /*виводить ті які мали опади і рахує середній тиск*/
//class Weather
//{
//private:
//	int temperature;
//	int pressure;
//	char wind;
//	int opadu;
//	string s_wind;
//	string s_opadu;
//public:
//	Weather()
//	{
//		opadu = 0;
//		pressure = 0;
//		temperature = 0;
//		wind = 'z';
//	}
//	Weather(int t, int o, int p, char w)
//	{
//		this->temperature = t;
//		this->pressure = p;
//		this->opadu = o;		
//		this->wind = w;
//		switch (w)
//		{
//		case 't':s_wind = "tyho";
//			break;
//		case 'l':s_wind = "legenko";
//			break;
//		case'p':s_wind = "pomirnyi";
//			break;
//		case's':s_wind = "sulnyi";
//			break;
//		default:
//			break;
//		}
//	}
//	friend istream& operator>>(istream& in, Weather& w)
//	{
//		cout << "Temperature: " << endl;
//		in >> w.temperature;
//		cout << "Pressure: " << endl;
//		in >> w.pressure;
//		cout << "Opadu: " << endl;
//		in >> w.opadu;
//		cout << "Wind: " << endl;
//		in >> w.wind;
//		return in;
//	}
//	int GetTemperature()
//	{
//		return temperature;
//	}
//	char GetWind()
//	{
//		return wind;
//	}
//	int GetOpadu()
//	{
//		return opadu;
//	}
//	int GetPressure()
//	{
//		return pressure;
//	}
//	friend ostream& operator<<(ostream& out, Weather& w)
//	{
//		out << w.temperature << "C" << "\t\t";
//		out << w.pressure << "\t";
//		out << w.wind << "\t";
//		out << w.opadu << endl;
//		return out;
//	}
//};
//int main()
//{
//	double sr_pres = 0;
//	Weather* arr = new Weather[12];
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> arr[i];
//	}
//	cout << "Temperature  Pressure  Wind_force  Opadu\n";
//	for (int i = 0; i < 3; i++)
//	{
//		if (arr[i].GetOpadu() == 1)
//		{
//			cout << arr[i];
//		}
//		sr_pres += arr[i].GetPressure();
//	}	
//	
//	cout << "Averange pressure of windless days = " << sr_pres / 3 << endl;
//}


//class Country
//{
//private:
//    int number;
//    int area;
//    int population;
//    char mainland;
//    string s_mainland;
//public:
//    Country()
//    {
//        number = 0;
//        area = 0;
//        population = 0;
//        mainland = 'n';
//    }
//    Country(int n, int a, int p, char m)
//    {
//        this->number = n;
//        this->area = a;
//        this->population = p;
//        this->mainland = m;
//        switch (m)
//        {
//        case'e':s_mainland = "Europe";
//            break;
//        case'a':s_mainland = "Asia";
//            break;
//        case'f':s_mainland = "Africa";
//            break;
//        case'v':s_mainland = "Australia";
//            break;
//        case'm':s_mainland = "USA";
//            break;
//        default:
//            break;
//        }
//    }
//    int GetArea()
//    {
//        return area;
//    }
//    int GetMain()
//    {
//        return mainland;
//    }
//    int GetNumber()
//    {
//        return number;
//    }
//    int GetPopulation()
//    {
//        return population;
//    }
//    friend istream& operator>>(istream& in, Country& c)
//    {
//        cout << "Number: " << endl;
//        in >> c.number;
//        cout << "Area: " << endl;
//        in >> c.area;
//        cout << "Population: " << endl;
//        in >> c.population;
//        cout << "Mainland: " << endl;
//        in >> c.mainland;
//        return in;
//    }
//    friend ostream& operator<<(ostream& out, Country c)
//    {
//        out << c.number << "\t";
//        out << c.area << "\t";
//        out << c.population << "\t\t";
//        out << c.mainland << endl;
//        return out;
//    }
//    bool operator < (Country& c)
//    {
//        return this->number < c.number;
//    }
//};
//void sort(Country mas[], unsigned n)
//{
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            if (mas[i] < mas[j])
//            {
//                swap(mas[i], mas[j]);
//            }
//        }
//    }
//}
//int main()
//{
//    int sr_main = 0;
//    Country* arr = new Country[3];
//    for (int i = 0; i < 3; i++) 
//    {
//        cin >> arr[i];
//    }
//    sort(arr, 3);
//    cout << "Country  Area  Population  Mainland" << endl;
//    for (int i = 0; i < 3; i++)
//    {
//        cout << arr[i];
//    }
//    //площа країн європи
//    for (int i = 0; i < 3; i++)
//    {
//        if (arr[i].GetMain() == 'e')
//        {
//            sr_main += arr[i].GetPopulation();
//        }
//    }    
//    cout << "Sum Area: " << sr_main;
//
//   
//}






//задача про працівників
//enum class Type
//{
//    Junior = 1,
//    Senior = 2,
//    Teamlead = 3,
//    Cheff = 4
//};
//class Employee
//{
//private:
//    string firstname;
//    string lastname;
//    string type;
//    int size;
//public:
//    Employee()
//    {
//        this->firstname = "none";
//        this->lastname = "none";
//        this->type = "Junior";
//        this->size = 0;
//    }
//    Employee(string firstname, string lastname, string type, int size)
//    {
//        this->firstname = firstname;
//        this->lastname = lastname;
//        this->type = type;
//        this->size = size;
//    }
//    Employee(const Employee& employee)
//    {
//        this->firstname = employee.firstname;
//        this->lastname = employee.lastname;
//        this->type = employee.type;
//        this->size = employee.size;
//    }
//    friend istream& operator>>(istream& in, Employee& employee)
//    {
//        in >> employee.type >> employee.lastname >> employee.firstname >> employee.size;
//        return in;
//        
//    }
//    friend ostream& operator<<(ostream& out, Employee& employee)
//    {
//        out << employee.type << " " << employee.lastname << " " << employee.firstname << " " << employee.size;
//        return out;
//    }
//    bool operator==(Employee& employee)
//    {        
//        this->type == employee.type;        
//    }
//    bool operator<(Employee& employee)
//    {
//        this->type < employee.type;
//        this->lastname < employee.lastname;
//    } 
//    string GetType()
//    {
//        return type;
//    }
//    string SetType(string type)
//    {
//        this->type = type; 
//        return type;
//    }
//    int GetSize()
//    {
//        return size;
//    }
//    string GetLastName()
//    {
//        return lastname;
//    }
//    string GetFirstName()
//    {
//        return firstname;
//    }
//};
//void Sort(Employee* mas, unsigned n)
//{
//    Employee temp = mas[0];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (mas[i].GetType() < mas[j].GetType())
//            {
//                temp = mas[i];
//                mas[i] = mas[j];
//                mas[j] = temp;
//            }
//            else if(mas[i].GetType() == mas[j].GetType()&& mas[j].GetLastName() < mas[i].GetLastName())
//            {
//                temp = mas[i];
//                mas[i] = mas[j];
//                mas[j] = temp;
//            }
//        }        
//        cout << mas[i] << endl;
//    }
//}
//void MinSize(Employee* mas, unsigned n)
//{
//    Employee temp = mas[0];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (mas[i].GetSize() < mas[j].GetSize())
//            {
//                temp = mas[i];
//                mas[i] = mas[j];
//                mas[j] = temp;
//            }
//        }        
//    }
//    cout << temp;
//}
//void Type(Employee* mas, unsigned n)
//{
//    for (int i = 0; i < n-1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (mas[i].GetType() != mas[j].GetType())
//            {
//                cout << mas[i].GetType() << endl;
//                i++;
//                break;
//            }
//        }
//    }
//    cout << endl;
//}
//int main()
//{     
//    fstream F; 
//    F.open("file.txt");
//    int n;
//    F >> n;      
//    Employee* arr = new Employee[n];
//    for (int i = 0; i < n; i++)
//    {
//        F >> arr[i];        
//    }    
//    Employee emp1("Vitalii", "Horlatch", "Junior", 1200);
//    Employee emp2(emp1);
//    Employee emp3("Petro", "Fritsak", "Senior", 2500);
//    arr[3] = emp1;
//    arr[4] = emp3;
//    arr[5] = emp2;    
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << endl;
//    }
//    cout << endl;
//    Sort(arr, n);
//    cout << endl;
//    Type(arr, n);
//    cout << "Choose Type: ";
//    string a;
//    cin >> a;
//    for (int i = 0; i < n; i++)
//    {
//        if (a == arr[i].GetType())
//        {
//            cout << arr[i].GetLastName() << " " << arr[i].GetFirstName() << endl;
//        }       
//    }
//    cout << endl;
//    cout << "Min size: ";
//    MinSize(arr, n);
//}






//class Goods
//{
//private:
//    int code;
//    double price;
//    int number;
//public:
//    Goods()
//    {
//        this->code = 0;
//        this->number = 0;
//        this->price = 0;
//    }
//    Goods(int code, double price, int number)
//    {
//        this->code = code;
//        this->number = number;
//        this->price = price;
//    }
//    Goods(const Goods& goods)
//    {
//        this->code = goods.code;
//        this->number = goods.number;
//        this->price = goods.price;
//    }
//    friend istream& operator>>(istream& in, Goods& goods)
//    {
//        in >> goods.code >> goods.price >> goods.number;
//        return in;
//    }
//    friend ostream& operator<<(ostream& out, Goods& goods)
//    {
//        out << goods.code << "code" << " " << goods.price << "grn" << " " << goods.number << "numb";
//        return out;
//    }
//    int GetPrice()
//    {
//        return price;
//    }
//    bool operator<(Goods& goods)
//    {
//        this->price < goods.price;
//    }
//};
//void Sort(Goods* mas, unsigned n)
//{
//    for (int i = 0; i < n-1; i++)
//    {
//        for (int j = i + 1; i < n; j++)
//        {
//            if (mas[j].GetPrice() < mas[i].GetPrice())
//            {
//                swap(mas[i], mas[j]);
//            }            
//        } 
//    }  
//}
//void MinElem(Goods* mas, unsigned n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        cout << mas[i].GetPrice() << endl;
//    }    
//}
//int main()
//{
//    int n;
//    fstream F;
//    F.open("File2.txt");
//    F >> n;
//    Goods* arr = new Goods[n];
//    for (int i = 0; i < n; i++)
//    {
//        F >> arr[i];
//    }
//    cout << "Code\t" << "Price\t" << "Number" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << endl;
//    }
//    cout << endl;
//    Sort(arr, n);
//    MinElem(arr, n);
//    
//    
//    /*cout << "How many min elem?: ";
//    int m;
//    cin >> m;    
//    cout << "Min Price: "; 
//    
//    MinElem(arr, m);*/
//
//}



void Sort(int* mas, unsigned n)
{
    int temp = mas[0];
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < temp) 
        {
            temp = mas[i];
        }
        else if(mas[i]>temp)        
        {
            mas[i] = 0.5;
        }
        cout << mas[i] << " ";
    }
}
int main()
{
    srand(time(NULL));
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
        cout << arr[i] << " ";            
    }
    cout << endl;
    Sort(arr, n);
}




//рахує сусідні елементи
//void Sort(int* mas, unsigned n)
//{
//    int temp = mas[0];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (mas[i] < mas[j])
//            {
//                swap(mas[i], mas[j]);
//            }
//        }
//    }    
//}
//int Funk(int* mas, unsigned n)
//{
//    int ival = 0;    
//    for (int i = 0; i < n; i++)
//    {
//        if (mas[i + 1] > mas[i]);
//        {
//            ival++;
//        }
//    }
//    return ival;
//}
//int main()
//{
//    srand(time(NULL));
//    int n;
//    cin >> n;
//    int* arr = new int[n];
//    for (int i = 0; i < n; i++)
//    {
//        arr[i] = rand() % 20 - 7;        
//        if (arr[i] == 0)
//        {            
//            arr[i] = rand() % 20 - 7;
//        }        
//    }
//    cout << endl;
//    Sort(arr, n);
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    Funk(arr, n);
//    cout << "Ival: " << Funk(arr, n);    
//}



//void Func(int* mas, unsigned n)
//{
//    srand(time(NULL));
//    for (int i = 0; i < n; i++)
//    {
//        if (mas[0] >= 0)
//        {
//            mas[i] = rand() % 20 - 2;
//        }
//        if (mas[i] < 0)
//        {
//            break;
//        }
//        
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << mas[i] << " ";
//    }
//}
//int main()
//{
//    int n;
//    cin >> n;
//    int* arr = new int[n];
//    Func(arr, n);
//}
