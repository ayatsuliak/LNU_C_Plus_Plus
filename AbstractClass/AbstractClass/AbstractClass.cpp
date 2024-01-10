#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Визначити абстрактний клас Телепередача(поля назва, тип та час), похідні абстрактні класи 
//Розважальна передача(поле - обмеження по віку), Науково - інформаційна передача(поле - рівень).
//Та відповідні похідні : МультФільм(поле - студія) і Шоу(поле - автор)  з базовим класом 
//Розважальна передача, та Новини(поле - агенція) і Документальний фільм(поле - компанія) з базовим класом 
//Науково - інформаційна передача.Ввести дані про 10 різних передач і вивести їх посортовані  у часовому порядку.
//Вивести ті інформаційні програми, які будуть проходити до вказаного часу.Введення - виведення здійснювати з файлу

class ITVShow
{
protected:
	string name;
	string type;
	string time;
public:
	ITVShow()
	{
		this->name = "";
		this->type = "";
		this->time = "";
	}
	ITVShow(string name, string type, string time)
	{
		this->name = name;
		this->type = type;
		this->time = time;
	}

	virtual void input(fstream& file)
	{
		file >> name >> type >> time;
	}
	virtual void print(fstream& file)
	{
		file << name << " " << type << " " << time << " ";
	}

	string GetTime()
	{
		return time;
	}
	virtual ~ITVShow() {}
};

class IEntertainmentShow :public ITVShow  //Розважальний
{
protected:
	string age_restrictions;
public:
	IEntertainmentShow() :ITVShow()
	{
		this->age_restrictions = "";
	}
	IEntertainmentShow(string name, string type, string time, string age_restrictions) :ITVShow(name, type, time)
	{
		this->age_restrictions = age_restrictions;
	}

	void input(fstream& file)
	{
		ITVShow::input(file);
		file >> age_restrictions;
	}
	void print(fstream& file)
	{
		ITVShow::print(file);
		file << age_restrictions << " ";
	}
};

class IScientificAndInformationalProgram :public ITVShow  //Науково-інформаційний
{
protected:
	string level;
public:
	IScientificAndInformationalProgram() :ITVShow()
	{
		this->level = "";
	}
	IScientificAndInformationalProgram(string name, string type, string time, string level) :ITVShow(name, type, time)
	{
		this->level = level;
	}

	void input(fstream& file)
	{
		ITVShow::input(file);
		file >> level;
	}
	void print(fstream& file)
	{
		ITVShow::print(file);
		file << level << " ";
	}
};

class Cartoons :public IEntertainmentShow
{
protected:
	string studio;
public:
	Cartoons() :IEntertainmentShow()
	{
		this->studio = "";
	}
	Cartoons(string name, string type, string time, string age_restrictions, string studio) :IEntertainmentShow(name, type, time, age_restrictions)
	{
		this->studio = studio;
	}

	void input(fstream& file) 
	{
		IEntertainmentShow::input(file);
		file >> studio;
	}
	void print(fstream& file) 
	{
		IEntertainmentShow::print(file);
		file << studio << endl;
	}
};

class Show :public IEntertainmentShow
{
protected:
	string autor;
public:
	Show() :IEntertainmentShow()
	{
		this->autor = "";
	}
	Show(string name, string type, string time, string age_restrictions, string autor) :IEntertainmentShow(name, type, time, age_restrictions)
	{
		this->autor = autor;
	}

	void input(fstream& file)
	{
		IEntertainmentShow::input(file);
		file >> autor;
	}
	void print(fstream& file)
	{
		IEntertainmentShow::print(file);
		file << autor << endl;
	}
};

class News :public IScientificAndInformationalProgram
{
protected:
	string agency;
public:
	News() :IScientificAndInformationalProgram()
	{
		this->agency = "";
	}
	News(string name, string type, string time, string level, string agency) :IScientificAndInformationalProgram(name, type, time, level)
	{
		this->agency = agency;
	}

	void input(fstream& file)
	{
		IScientificAndInformationalProgram::input(file);
		file >> agency;
	}
	void print(fstream& file) 
	{
		IScientificAndInformationalProgram::print(file);
		file << agency << endl;
	}
};

class Documentary :public IScientificAndInformationalProgram
{
protected:
	string company;
public:
	Documentary() :IScientificAndInformationalProgram()
	{
		this->company = "";
	}
	Documentary(string name, string type, string time, string level, string company) :IScientificAndInformationalProgram(name, type, time, level)
	{
		this->company = company;
	}

	void input(fstream& file)
	{
		IScientificAndInformationalProgram::input(file);
		file >> company;
	}
	void print(fstream& file)
	{
		IScientificAndInformationalProgram::print(file);
		file << company << endl;
	}
}; 

void SortTime(ITVShow** mas, unsigned n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j]->GetTime() > mas[i]->GetTime())
			{
				swap(mas[i], mas[j]);
			}
		}
	}
}

int main()
{
	fstream F1;
	fstream F2;
	F1.open("File1.txt");
	F2.open("File2.txt", fstream::app);

	int n;
	char t;
	F1 >> n;
	ITVShow** arr = new ITVShow * [n];
	for (int i = 0; i < n; i++)
	{
		F1 >> t;
		switch (t)
		{
		case 'c': arr[i] = new Cartoons;
			break;
		case 's': arr[i] = new Show;
			break;
		case 'n': arr[i] = new News;
			break;
		case 'd': arr[i] = new Documentary;
			break;
		}
		arr[i]->input(F1);
	}

	SortTime(arr, n);

	for (int i = 0; i < n; i++)
	{
		if (arr[i]->GetTime() < "17:00")
		{
			F2 << "TV program:" << endl;
			F2 << i + 1 << ") ";
			arr[i]->print(F2);
		}
	}
	
	F2.close();
	F1.close();
	delete[] arr;
}