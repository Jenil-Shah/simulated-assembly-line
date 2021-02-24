// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 01 August 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _LINEMANAGER_H
#define _LINEMANAGER_H

#include<iostream>
#include<string>
#include<vector>
#include<deque>

#include "Workstation.h"

class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	unsigned int startingStation;
	unsigned int endingStation;

	public:
		LineManager();
		LineManager(const std::string& str, std::vector<Workstation*>& work, std::vector<CustomerOrder>& co);
		bool run(std::ostream& os);
		void displayCompletedOrders(std::ostream& os) const;
		void displayStations() const;
		void displayStationsSorted() const;
};
#endif
