/* @Author
Student Name:<Fatima Rahimova>
Student ID :<150180905>
Date:<02.05.2021>*/

#pragma once

#include<iostream>
#include<string>
#include<cstdlib>
#include "Mission.h"

class Agency {
private:
	std::string name;
	int cash;
	int ticketPrice;
	Mission* completedMissions;
	Mission* nextMissions;
	size_t cm_length;
	size_t nm_length;

	void nm_realloc(size_t size1)
	{
		Mission* newData = new Mission[size1];
		Mission::numMissions -= size1;
		size_t lower = nm_length < size1 ? nm_length : size1;
		for (size_t i = 0; i < lower; i++)
			newData[i] = nextMissions[i];
		delete[] nextMissions;
		nextMissions = newData;
	}


	void cm_realloc(size_t size1)
	{
		Mission* newData = new Mission[size1];
		size_t lower = cm_length < size1 ? cm_length : size1;
		for (size_t i = 0; i < lower; i++)
			newData[i] = completedMissions[i];
		delete[] completedMissions;
		completedMissions = newData;
	}

public:
	Agency(const std::string& m_name, int m_cash, int m_tick)
		:name(m_name), cash(m_cash), ticketPrice(m_tick), completedMissions(NULL), nextMissions(NULL), cm_length(0), nm_length(0)
	{
		if (m_tick < 0) {
			ticketPrice = 0;
			std::cerr << "Ticket price can't be negative. It is set to 0.\n";
		}
		else
			ticketPrice = m_tick;
	}

	Agency(const Agency& other)
		: completedMissions(NULL), nextMissions(NULL)
	{
		*this = other;
	}

	void addMission(const Mission& t);
	void setTicketPrice(int m_ticket);
	int getTicketPrice();
	void executeNextMission();

	friend std::ostream& operator<<(std::ostream& os, const Agency& m_agency)
	{
		os << "Agency name: " << m_agency.name << ", Total cash: " << m_agency.cash
			<< ", Ticket Price: " << m_agency.ticketPrice << "\n";
		
		os << "Next Missions:\n";
		if (m_agency.nm_length == 0)
			os << "No missions available.\n";
		else {
			for (size_t i = 0; i < m_agency.nm_length; i++) {
				os << "Mission number: " << m_agency.nextMissions[i].getMissionnum() << " Mission name: " << m_agency.nextMissions[i].getName()
					<< " Cost: " << m_agency.nextMissions[i].getCost() << "\n";
			}
		}
		os << "Completed Missions:\n";
		if (m_agency.cm_length == 0)
			os << "No missions completed before.\n";

		else {
			for (size_t i = 0; i < m_agency.cm_length; i++) {
				os << "Mission number: " << m_agency.completedMissions[i].getMissionnum() << " Mission name: " << m_agency.completedMissions[i].getName()
					<< " Cost: " << m_agency.completedMissions[i].getCost() << "\n";
			}
		}
		return os;
	}

	Agency& operator=(const Agency& other)
	{
		if (this != &other)
		{
			delete[] this->nextMissions;
			delete[] this->completedMissions;

			name = other.name;
			cash = other.cash;
			ticketPrice = other.ticketPrice;
			nm_length = other.nm_length;
			nextMissions = new Mission[nm_length];
			for (size_t i = 0; i < nm_length; i++)
				nextMissions[i] = other.nextMissions[i];
			cm_length = other.cm_length;
			completedMissions = new Mission[cm_length];
			for (size_t i = 0; i < cm_length; i++)
				completedMissions[i] = other.completedMissions[i];
		}

		return *this;
	}
};

