#include "Action.h"

fstream& operator>>(fstream& is, Action& _action)
{
	is >> _action.name >> _action.time;
	return is;
}

ostream& operator<<(ostream& os, const Action& _action)
{
	os << " | " << _action.name << " " << _action.time << " | ";
	return os;
}

fstream& operator>>(fstream& is, Routine& _routine)
{
	is >> _routine.date.tm_mday >> _routine.date.tm_mon >> _routine.countAction;
	_routine.actionList.resize(_routine.countAction);
	for (size_t i = 0; i < _routine.countAction; i++)
	{
		is >> _routine.actionList[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const Routine& _routine)
{
	char fulldate[10];
	if (strftime(fulldate, sizeof(fulldate), "%d/%m", &_routine.date));
	os << fulldate << " ";
	for (size_t i = 0; i < _routine.countAction; i++)
	{
		os << _routine.actionList[i] << " ";
	}
	return os;
}

fstream& operator>>(fstream& is, RoutineForTheWeek& _routineForTheWeek)
{
	is >> _routineForTheWeek.personName;
	_routineForTheWeek.routineList.resize(7);
	for (size_t i = 0; i < 7; i++)
	{
		is >> _routineForTheWeek.routineList[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const RoutineForTheWeek& _routineForTheWeek)
{
	os << _routineForTheWeek.personName << " ";
	for (size_t i = 0; i < 7; i++)
	{
		os << _routineForTheWeek.routineList[i] << endl;
	}
	os << endl;
	return os;
}

size_t Routine::getCountAction()
{
	return countAction;
}

string RoutineForTheWeek::getName()
{
	return personName;
}

Routine RoutineForTheWeek::operator[](size_t pos)
{
	return routineList.at(pos);
}

string Action::getName()
{
	return name;
}

double Action::getTime()
{
	return time;
}
