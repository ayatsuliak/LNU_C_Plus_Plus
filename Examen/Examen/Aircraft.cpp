#include "Aircraft.h"

void IAircraft::input(fstream& file)
{
	file >> typeOfAircraft >> maxHeight;
}

void IAircraft::print(fstream& file)
{
	file << typeOfAircraft << " " << maxHeight << " ";
}

double IAircraft::getMaxHeight()
{
	return maxHeight;
}

void Plane::input(fstream& file)
{
	IAircraft::input(file);
	file >> speed;
}

void Plane::print(fstream& file)
{
	IAircraft::print(file);
	file << speed << endl;
}

double Plane::getSpeed()
{
	return speed;
}

void Balloon::input(fstream& file)
{
	IAircraft::input(file);
	file >> maxFlightTime;
}

void Balloon::print(fstream& file)
{
	IAircraft::print(file);
	file << maxFlightTime << endl;
}

fstream& operator>>(fstream& is, Plane& _plane)
{
	_plane.input(is);
	return is;
}

fstream& operator<<(fstream& os, Plane& _plane)
{
	_plane.print(os);
	return os;
}

fstream& operator>>(fstream& is, Balloon& _balloon)
{
	_balloon.input(is);
	return is;
}

fstream& operator<<(fstream& os, Balloon& _balloon)
{
	_balloon.print(os);
	return os;
}
