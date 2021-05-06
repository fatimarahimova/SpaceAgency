/* @Author
Student Name:<Fatima Rahimova>
Student ID :<150180905>
Date:<02.05.2021>*/

#include<string>
#include<cstdlib>
#include<ctime>
#include"Mission.h"

const int& Mission::getCost() const { return cost; }
const int& Mission::getMissionnum() const { return missionNumber; }
const std::string& Mission::getName() const { return name; }
void Mission::setName(const std::string& temp) { name = temp; }

void Mission::operator+=(const Passenger* rhs)
{
	if (rhs->hasTicket())
	{
		p_realloc(p_length + 1);
		passengers[p_length++] = *rhs;
	}
	else
	{
		std::cerr << "Passenger " << rhs->getName() << " " << rhs->getSurname() << " does not have a valid ticket!";

	}
}

void Mission::operator+=(const Astronaut* rhs)
{
	c_realloc(c_length + 1);
	crew[c_length++] = *rhs;
}



bool Mission::executeMission() {
	if (faultProbability == 100)
		return false;

	int random = std::rand() % 100;
	if (random > faultProbability) {
		completed = true;
		std::cout << "MISSION " << name <<" SUCCESSFUL!" << std::endl;

		for (int i = 0; i < c_length; i++) {
			int compmission = crew[i].completeMission();
			std::cout << "Astronaut " << crew[i].getName() << " " << crew[i].getSurname() << " successfully completed " << compmission << " missions." << std::endl;
		}
	}
	else {
		std::cout << "MISSION " << name << " FAILED!" << std::endl;
		std::cerr << "Agency reschedules the mission.\n";
	}
	return completed;
}

int Mission::calculatedProfit(int ticket) const
{
	return (completed ? p_length * ticket : 0) - cost;
}

