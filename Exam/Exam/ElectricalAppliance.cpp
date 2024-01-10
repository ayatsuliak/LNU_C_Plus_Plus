#include "ElectricalAppliance.h"

void IElectricalAppliance::Input(fstream& file)
{
	file >> name >> company >> price;
}

void IElectricalAppliance::Print(fstream& file)
{
	file << name << " " << company << " " << price<<" ";
}

string IElectricalAppliance::nameElectricalAppliance()
{
	return name;
}

string IElectricalAppliance::nameCompanyElectricalAppliance()
{
	return company;
}

double IElectricalAppliance::priceElectricalAppliance()
{
	return price;
}

bool IElectricalAppliance::operator<(IElectricalAppliance& _electricalAppliance)
{
	if (this->nameElectricalAppliance() < _electricalAppliance.nameElectricalAppliance())
	{
		return true;
	}
	if (this->nameElectricalAppliance() == _electricalAppliance.nameElectricalAppliance())
	{
		return this->nameCompanyElectricalAppliance() < _electricalAppliance.nameCompanyElectricalAppliance();
	}
	if (this->nameCompanyElectricalAppliance() == _electricalAppliance.nameCompanyElectricalAppliance())
	{
		return this->priceElectricalAppliance() < _electricalAppliance.priceElectricalAppliance();
	}
}

void Steamer::Input(fstream& file)
{
	IElectricalAppliance::Input(file);
	file >> powerSteamer >> colorSteamer;
}

void Steamer::Print(fstream& file)
{
	IElectricalAppliance::Print(file);
	file << powerSteamer << " " << colorSteamer << endl;
}

void WashingMachine::Input(fstream& file)
{
	IElectricalAppliance::Input(file);
	file >> countProgramInWashingMachine >> volumeWashingMachine;
}

void WashingMachine::Print(fstream& file)
{
	IElectricalAppliance::Print(file);
	file << countProgramInWashingMachine << " " << volumeWashingMachine << endl;
}

void Combine::Input(fstream& file)
{
	IElectricalAppliance::Input(file);
	file >> powerCombine >> countFunctionCombine;
}

void Combine::Print(fstream& file)
{
	IElectricalAppliance::Print(file);
	file << powerCombine << " " << countFunctionCombine << endl;
}

fstream& operator>>(fstream& is, Steamer& _steamer)
{
	_steamer.Input(is);
	return is;
}

fstream& operator<<(fstream& os, Steamer& _steamer)
{
	_steamer.Print(os);
	return os;
}

fstream& operator>>(fstream& is, WashingMachine& _washingMachine)
{
	_washingMachine.Input(is);
	return is;
}

fstream& operator<<(fstream& os, WashingMachine& _washingMachine)
{
	_washingMachine.Print(os);
	return os;
}

fstream& operator>>(fstream& is, Combine& _combine)
{
	_combine.Input(is);
	return is;
}

fstream& operator<<(fstream& os, Combine& _combine)
{
	_combine.Print(os);
	return os;
}

string Steamer::getType()
{
	return "Steamer";
}

string WashingMachine::getType()
{
	return "WashingMachine";
}

string Combine::getType()
{
	return "Combine";
}
