/* @Author
Student Name:<Fatima Rahimova>
Student ID :<150180905>
Date:<02.05.2021>*/


#include<iostream>
#include<string>
#include "Agency.h"

void Agency::setTicketPrice(int m_ticket) { ticketPrice = m_ticket; }
int Agency::getTicketPrice() { return ticketPrice; }

void Agency::addMission(const Mission& t) {
	nm_realloc(nm_length + 1);
	nextMissions[nm_length++] = t;
}



void Agency::executeNextMission() {
	if (nextMissions == NULL) {
		std::cerr << "No available mission to execute!";
	}
	else {
		bool success = nextMissions[0].executeMission();
		cash += nextMissions[0].calculatedProfit(ticketPrice);
		if (success)
		{
			cm_realloc(cm_length + 1);
			completedMissions[cm_length++] = nextMissions[0];
			for (size_t i = 0; i < nm_length - 1; i++)
				nextMissions[i] = nextMissions[i + 1];
			nm_realloc(nm_length);
			nm_length--;
		}
		else
		{
			Mission temp = nextMissions[0];
			for (size_t i = 0; i < nm_length - 1; i++)
				nextMissions[i] = nextMissions[i + 1];
			nextMissions[nm_length - 1] = temp;
		}
	}
}