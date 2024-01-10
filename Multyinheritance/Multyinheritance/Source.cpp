#include<iostream>

using namespace std;

class Person
{
protected:
	string name;
public:
	Person()
	{
		this->name = "";
	}
	Person(string name)
	{
		this->name = name;
	}

	virtual void print()
	{
		cout << name<<" ";
	}

	virtual ~Person() {};
};

class Worker :virtual public Person
{
protected:
	string first_name;
	float salary;
public:
	Worker()
	{
		this->first_name = "";
		this->salary = 0;
	}
	Worker(string name, string first_name, float salary) :Person(name)
	{
		this->first_name = first_name;
		this->salary = salary;
	}

	float income()
	{
		return salary;
	}

	void print()
	{
		cout << first_name << " " << salary << " ";
	}
};

class Student :virtual public Person
{
protected:
	string group;
	float styp;
public:
	Student()
	{
		this->group = "";
		this->styp = 0;
	}
	Student(string name, string group, float styp) :Person(name)
	{
		this->group = group;
		this->styp = styp;
	}

	float income()
	{
		return styp;
	}

	void print()
	{
		cout << group << " " << styp << " ";
	}
};

class Student_Worker :public Student, public Worker
{
protected:
	string hours_work;
	string hours_study;
public:
	Student_Worker() {};
	Student_Worker(string name, string group, float styp, string first_name, float salary, string hours_work, string hours_study) :Person(name), Student(name, group, styp), Worker(name, first_name, salary)
	{
		this->hours_study = hours_study;
		this->hours_work = hours_work;
	}

	void print()
	{
		Person::print();
		Worker::print();
		Student::print();
		cout << hours_study << " " << hours_work;
	}
};

int main()
{
	Person* arr[3];
	arr[0] = new Student("Petriv", "PMi-23", 900);
	arr[1] = new Worker("Octapiv", "IT-best", 9000);
	arr[2] = new Student_Worker("Krasiv", "PMi=51", 0, "IT-best", 5000, "17:00-20:00", "8:30-15:00");
	for (int i = 0; i < 3; i++)
	{
		arr[i]->print();
		cout << endl;
	}
}