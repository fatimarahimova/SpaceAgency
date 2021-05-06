/* @Author
Student Name:<Fatima Rahimova>
Student ID :<150180905>
Date:<02.05.2021>*/

#pragma once

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include "Person.h"

class Mission
{
public:
	static int numMissions;
private:
	std::string name;
	Passenger* passengers;
	Astronaut* crew;
	int missionNumber;
	int cost;
	int faultProbability;
	int p_length;
	int c_length;
	bool completed;

	void p_realloc(int size1)
	{
		Passenger* newData = new Passenger[size1];
		for (int i = 0; i < p_length; i++)
			newData[i] = passengers[i];
		delete[] passengers;
		passengers = newData;
	}
	void c_realloc(int size1)
	{
		Astronaut* newData = new Astronaut[size1];
		for (int i = 0; i < c_length; i++)
			newData[i] = crew[i];
		delete[] crew;
		crew = newData;
	}

public:

	Mission(const std::string m_name = "AA-00", int m_cost = 0, int prob = 0)
		:name(m_name), missionNumber(++numMissions), cost(m_cost), faultProbability(prob), completed(false), crew(NULL), passengers(NULL), c_length(0), p_length(0)
	{
		size_t pos = name.find('-');
		std::string temp = m_name.substr(0, pos);
		std::string m_temp = m_name.substr(pos + 1);

		bool correct = temp.size() == 2 && m_temp.size() == 2;
		for (size_t i = 0; i < temp.size() && correct; i++)
			correct = isupper(temp[i]);

		for (size_t i = 0; i < m_temp.size() && correct; i++)
			correct = isdigit(m_temp[i]);

		if (!correct) {
			name = "AA-00";
			std::cerr << "Given name does not satisfy the mission naming convention. Please set a new name!\n";
		}

		if (prob < 0) prob = 0;
		else if (prob > 100) prob = 100;
		
	}
	Mission(const Mission& other)
		: passengers(NULL), crew(NULL)
	{
		
		*this = other;
	}
	
	~Mission() {
		delete[] passengers;
		delete[] crew;
	}
	const int& getCost() const;
	const int& getMissionnum() const;
	const std::string& getName() const;
	void setName(const std::string& temp);

	void operator+=(const Passenger* rhs);


	void operator+=(const Astronaut* rhs);


	bool executeMission();

	int calculatedProfit(int ticket) const;

	Mission& operator=(const Mission& other)
	{
		if (this != &other)
		{
			delete[] passengers;
			delete[] crew;

			name = other.name;
			passengers = new Passenger[other.p_length];
			crew = new Astronaut[other.c_length];
			missionNumber = other.missionNumber;
			cost = other.cost;
			faultProbability = other.faultProbability;
			p_length = other.p_length;
			c_length = other.c_length;
			completed = other.completed;
			for (int i = 0; i < p_length; i++)
				passengers[i] = other.passengers[i];
			for (int i = 0; i < c_length; i++)
				crew[i] = other.crew[i];
		}

		return *this;
	}
};