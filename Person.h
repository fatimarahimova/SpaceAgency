/* @Author
Student Name:<Fatima Rahimova>
Student ID :<150180905>
Date:<02.05.2021>*/

#pragma once

#include<iostream>
#include<string>

class Person
{
private:
	std::string name;
	std::string surname;
public:
	Person(const std::string& m_name = "", const std::string& m_surname = "")
		: name(m_name), surname(m_surname)
	{}

	const std::string& getName() const;
	const std::string& getSurname() const;
};

class Passenger : public Person
{
private:
	int cash;
	bool ticket;
public:
	Passenger(const std::string& my_name = "", const std::string& my_surname = "",
		int my_cash = 0, bool my_ticket = false)
		:Person(my_name, my_surname),
		cash(my_cash), ticket(my_ticket)
	{
		if (my_cash < 0) {
			cash = 0;
			std::cerr << "Passenger cash can’t be negative. It is set to 0.\n";
		}
	}
	void buyTicket(int ticket_price);
	bool hasTicket() const;
};


class Astronaut : public Person
{
private:
	int numMissions;

public:
	Astronaut(const std::string& my_name1 = "", const std::string& my_surname1 = "",
		int number = 0)
		:Person(my_name1, my_surname1),
		numMissions(number)
	{
		if (numMissions < 0) {
			numMissions = 0;
			std::cerr << "Number of missions that astronaut completed can't be negative. It is set to 0.";
		}
	}
	int completeMission();
};


