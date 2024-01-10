#include<iostream>
#include<string>
#include<list>
#include<ctime>
#include<algorithm>
#include<fstream>
#include<memory>

using namespace std;

//В текстовому файлі знаходяться дані про витрати матеріалів бригад деякої будівельної фірми.
//Це номер бригади, дані про бригадира, список витрачених матеріалів з зазначенням дати, назви матеріалу, об’єму, вартості.
//Дані у файлі можуть повторюватися(для однієї бригади – декілька записів.
//	зчитати дані з файлу у контейнер і  відобразити їх на екрані(і записати у відповідні файли) у зростаючому порядку номерів бригад.
//При цьому декілька даних про витрати для кожної бригади об’єднуються в одну.
//Вивести загальний список використовуваних матеріалів(без повторів) із зазначенням загального їх об’єму і вартості.відобразити це у файлі

class Materials
{
private:
	string name_material;
	int volume_of_materials;
	int price_material;
	tm date_of_expended_materials;
public:
	void input(fstream& F)
	{
		F >> name_material >> volume_of_materials >> price_material;
		F >> date_of_expended_materials.tm_mday >> date_of_expended_materials.tm_mon >> date_of_expended_materials.tm_year;
	}
	void print(fstream& F)
	{
		F << " " << name_material << " " << volume_of_materials << " " << price_material << " ";
		char fulldate[50];
		if (strftime(fulldate, sizeof(fulldate), "%d/%m/%y", &date_of_expended_materials));
		F << fulldate << endl;
	}

	friend ostream& operator<<(ostream& os, Materials& materials)
	{
		os << " " << materials.name_material << " " << materials.volume_of_materials << " " << materials.price_material << " ";
		char fulldate[50];
		if (strftime(fulldate, sizeof(fulldate), "%d/%m/%y", &materials.date_of_expended_materials));
		os << fulldate << endl;
		return os;
	}

	string GetNameMaterial()
	{
		return name_material;
	}

	int GetVolumeOfMaterials()
	{
		return volume_of_materials;
	}

	int GetPriceMaterial()
	{
		return price_material;
	}

	Materials operator+(const Materials& materials)
	{
		Materials temp;
		temp.price_material = this->price_material + materials.price_material;
		return temp;
	}
};

class Brigade
{
private:
	int number_brigade;
	int the_amount_of_materials_used;
	string first_name_brigadier;
	string second_name_brigadier;
	Materials* materials;
public:
	void input(fstream& F)
	{
		F >> number_brigade >> first_name_brigadier >> second_name_brigadier >> the_amount_of_materials_used;
		if (materials != 0)
		{
			delete[]materials;
		}
		materials = new Materials[the_amount_of_materials_used];
		for (int i = 0; i < the_amount_of_materials_used; i++)
		{
			materials[i].input(F);
		}
	}

	void print(fstream& F)
	{
		F << "Number brigade: " << number_brigade << " Brigadier: " << first_name_brigadier << " " << second_name_brigadier;
		for (int i = 0; i < the_amount_of_materials_used; i++)
		{
			materials[i].print(F);
		}
	}

	friend ostream& operator<<(ostream& os, const Brigade& brigade)
	{
		os << "Number brigade: " << brigade.number_brigade << ". Brigadier: " << brigade.first_name_brigadier << " " << brigade.second_name_brigadier;
		for (size_t i = 0; i < brigade.the_amount_of_materials_used; i++)
		{
			os << ". Materials: " << brigade.materials[i] << " ";
		}
		return os;
	}

	int GetNumberBrigade()
	{
		return number_brigade;
	}

	string GetName()
	{
		return materials->GetNameMaterial();
	}

	int GetVolume()
	{
		return materials->GetVolumeOfMaterials();
	}

	int GetPrice()
	{
		return materials->GetPriceMaterial();
	}

	bool operator==(const Brigade& brigade)
	{
		if (brigade.number_brigade == 0)
		{
			throw exception("Error: number brigade = 0");
		}
		return (this->number_brigade == brigade.number_brigade);
	}

	Brigade operator+(const Brigade& other)
	{
		Brigade temp;
		temp.materials->GetNameMaterial() = this->materials->GetNameMaterial() += other.materials->GetNameMaterial();
		return temp; 
	}
};

int main()
{
	fstream F1;
	fstream F2;
	F1.open("File1.txt");
	F2.open("File2.txt");
	list<Brigade> brigade;
	auto itr = brigade.begin();

	while (!F1.eof())
	{
		Brigade temp;
		temp.input(F1);
		brigade.push_back(temp);
		for (auto itr = brigade.begin(); itr != brigade.end(); itr++)
		{
			for (auto itr2 = itr; itr2 != brigade.end(); itr2++)
			{
				if (itr->GetNumberBrigade() > itr2->GetNumberBrigade())
				{
					swap(*itr, *itr2);
				}
			}
		}
	}

	for (auto itr = brigade.begin(); itr != brigade.end(); itr++)
	{
		for (auto itr2 = itr; itr2 != brigade.end(); itr2++)
		{
			if (itr->GetNumberBrigade() == itr2->GetNumberBrigade())
			{
				itr = itr + itr2;
			}
		}
	}

	for (auto itr = brigade.begin(); itr != brigade.end(); itr++)
	{
		itr->print(F2);
		cout << *itr;
	}

	F1.close();
	F2.close();
	return 0;
}