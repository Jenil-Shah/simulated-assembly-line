// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 01 August 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<string>
#include<deque>

#include "Workstation.h"

using namespace std;

Workstation::Workstation()
{
	m_pNextStation = nullptr;
}

Workstation::Workstation(const std::string& str) : Station(str)
{
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os)
{
	if (!m_orders.empty() && !m_orders.back().isOrderFilled())
		m_orders.back().fillItem(*this, os);
}

bool Workstation::moveOrder()
{
	bool val = false;

	if (!m_orders.empty())
	{
		if (m_orders.front().isItemFilled(getItemName()) && m_pNextStation)
		{
			*this->m_pNextStation += std::move(m_orders.front());
			this->m_orders.pop_front();
		}

		val = true;
	}

	return val;
}

void Workstation::setNextStation(Station& station)
{
	m_pNextStation = static_cast<Workstation*>(&station);
}

const Workstation* Workstation::getNextStation() const
{
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order)
{
	bool val = false;

	if (m_orders.size() == 0)
		return false;

	if (m_orders.front().isOrderFilled())
	{
		order = std::move(m_orders.front());
		m_orders.pop_front();
		val = true;
	}

	return val;
}

void Workstation::display(std::ostream& os)
{
	if (m_pNextStation == nullptr)
		os << getItemName() << " --> END OF LINE";
	else
		os << getItemName() << " --> " << m_pNextStation->getItemName();

	os << endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& cs)
{
	m_orders.push_back(std::move(cs));

	return *this;
}
