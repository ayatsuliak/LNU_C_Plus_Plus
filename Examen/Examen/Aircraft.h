#pragma once
#include<iostream>
#include<fstream>

using namespace std;

//¬изначити абстрактний тип л≥тальний апарат, та два пох≥дних типи Ц л≥так та пов≥тр€на кул€.
// лас л≥тальний апарат м≥стить поле вид л≥тального апарату та максимальну висоту, на €ку в≥н може п≥дн€тис€, 
//клас л≥так - поле швидк≥сть, клас пов≥тр€на кул€ Ц поле максимальний час польоту.
//¬ текстовому файл≥ задано дан≥ про дек≥лька л≥тальних апарат≥в.¬вести дан≥ у один контейнер ≥ 
//а) вивести у ≥нший файл т≥ л≥тальн≥ апарати, €к≥ можуть п≥дн€тис€ на висоту x.
//б) ¬изначити дл€ кожного л≥така за ск≥льки часу в≥н долетить з  иЇва до Ћьвова(600 км)

class IAircraft
{
protected:
	string typeOfAircraft;
	double maxHeight;
public:
	void input(fstream& file);
	void print(fstream& file);

	double getMaxHeight();

	virtual ~IAircraft(){}
};

class Plane :public IAircraft
{
protected:
	double speed;
public:
	void input(fstream& file);
	void print(fstream& file);

	friend fstream& operator>>(fstream& is, Plane& _plane);
	friend fstream& operator<<(fstream& os, Plane& _plane);

	double getSpeed();

	virtual ~Plane() {}
};

class Balloon :public IAircraft
{
protected:
	double maxFlightTime;
public:
	void input(fstream& file);
	void print(fstream& file);

	friend fstream& operator>>(fstream& is, Balloon& _balloon);
	friend fstream& operator<<(fstream& os, Balloon& _balloon);

	virtual ~Balloon() {}
};

