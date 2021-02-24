// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 01 August 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _WORKSTATION_H
#define _WORKSTATION_H

#include<iostream>
#include<string>
#include<deque>

#include "Station.h"
#include "CustomerOrder.h"

class Workstation :public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;

	public:
		Workstation();
		Workstation(const std::string& str);
		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;
		void runProcess(std::ostream& os);
		bool moveOrder();
		void setNextStation(Station& station);
		const Workstation* getNextStation() const;
		bool getIfCompleted(CustomerOrder& order);
		void display(std::ostream& os);
		Workstation& operator+=(CustomerOrder&& cs);
};
#endif
