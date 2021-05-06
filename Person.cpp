/* @Author
Student Name:<Fatima Rahimova>
Student ID :<150180905>
Date:<02.05.2021>*/

#include<iostream>
#include<string>
#include"Person.h"


const std::string& Person::getName() const { return name; }
const std::string& Person::getSurname() const { return surname; }



void Passenger::buyTicket(int ticket_price) {
	if (cash >= ticket_price) {
		cash -= ticket_price;
		ticket = true;
	}
	else
		ticket = false;
}

bool Passenger::hasTicket() const { return ticket; }


int Astronaut::completeMission() {
	numMissions++;
	return numMissions;
}

