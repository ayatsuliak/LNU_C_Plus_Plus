﻿#include <iostream> 
#include <string> 
#include <ctime> 
#include <fstream> 

using namespace std;

//Розробити ієрархію класів для ромбовидного  наслідування: 
//автомобіль (об’єм двигуна, назва, марка) 1) бензиновий 
//автомобіль (об”єм баку), 2)електромобіль (max час пробігу, час 
//зарядки). Від 1) і 2) комбінований (пробіг на різних типах).
//Ввести дані про різні автомобілі різних марок в один масив, 
//видрукувати дані про них у файл. Посортувати їх за об’ємом 
//двигуна, далі за маркою. Знайти марку, яка містить авто всіх 
//трьох типів.

class Car
{
    string mark;
    string name;
    double volume;
public:
    virtual string getType() = 0;
    string getMark()
    {
        return mark;
    }
    double getVolume()
    {
        return volume;
    }
    bool operator< (Car& car)
    {
        if (this->getVolume() < car.getVolume())
        {
            return true;
        }
        if (this->getVolume() == car.getVolume())
        {
            return this->getMark() < car.getMark();
        }
    }
    virtual void input(fstream& f)
    {
        f >> mark >> name >> volume;
    }
    virtual void print(fstream& f)
    {
        f << mark << " " << name << " " << volume << " ";
    }
};

class Diesel : virtual public Car
{
    int volume_of_tank;
public:
    virtual string getType()
    {
        return "Diesel";
    }
    int getVolumeOfTank()
    {
        return volume_of_tank;
    }
    virtual void input(fstream& f)
    {
        Car::input(f);
        f >> volume_of_tank;
    }
    virtual void print(fstream& f)
    {
        Car::print(f);
        f << volume_of_tank;
    }
    friend fstream& operator>>(fstream& f, Diesel& car)
    {
        car.input(f);
    }
    friend fstream& operator<<(fstream& f, Diesel& car)
    {
        car.print(f);
    }
};

class Electrocar : virtual public Car
{
    double max_time_of_run;
    double time_of_charge;
public:
    virtual string getType()
    {
        return "Electrocar";
    }
    double GetTimeOfRun()
    {
        return max_time_of_run;
    }
    double GetTimeOfCharge()
    {
        return time_of_charge;
    }
    virtual void input(fstream& f)
    {
        Car::input(f);
        f >> max_time_of_run >> time_of_charge;
    }
    virtual void print(fstream& f)
    {
        Car::print(f);
        f << max_time_of_run << " " << time_of_charge << endl;
    }
    friend fstream& operator>>(fstream& f, Electrocar& car)
    {
        car.input(f);
    }
    friend fstream& operator<<(fstream& f, Electrocar& car)
    {
        car.print(f);
    }
};

class Hybrid : public Diesel, public Electrocar
{
    int run_on_diesel;
    int run_on_electro;
public:
    virtual string getType()
    {
        return "Hybrid";
    }
    int GetRunOnDiesel()
    {
        return run_on_diesel;
    }
    int GetRunOnElectro()
    {
        return run_on_electro;
    }
    virtual void input(fstream& f)
    {
        Diesel::input(f);
        Electrocar::input(f);

        f >> run_on_diesel >> run_on_electro;
    }
    virtual void print(fstream& f)
    {
        Diesel::print(f);
        Electrocar::print(f);

        f << " " << run_on_diesel << " " << run_on_electro << endl;
    }
    friend fstream& operator>>(fstream& f, Hybrid& car)
    {
        car.input(f);
    }
    friend fstream& operator<<(fstream& f, Hybrid& car)
    {
        car.print(f);
    }
};

int main()
{

    fstream f;
    fstream f2;
    fstream f3;
    f.open("Cars.txt");
    f2.open("Cars2.txt");
    int n = 3;
    Car** cars = new Car* [n];
    int temp;
    int i = 0;
    while (i != n)
    {
        f >> temp;
        switch (temp)
        {
        case 1: cars[i] = new Diesel;
            break;
        case 2: cars[i] = new Electrocar;
            break;
        case 3: cars[i] = new Hybrid;
            break;
        }
        cars[i]->input(f);
        i++;
    }
    
    for (int j = 0; j < n; j++)
    {
        cars[j]->print(f2);
        f << endl;
    }
    for (int j = 0; j < n; j++)
    {
        if (dynamic_cast<Hybrid*>(cars[j]) != 0)
        {
            Hybrid* hybrid = dynamic_cast<Hybrid*>(cars[j]);
            cout << hybrid->GetRunOnDiesel() << endl;
            cout << hybrid->GetRunOnElectro() << endl;

        }
    }
    f.close();
    f2.close();
    return 0;
}