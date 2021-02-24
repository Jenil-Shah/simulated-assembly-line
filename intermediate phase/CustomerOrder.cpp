// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 22 July 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<string>
#include<vector>
#include<utility>

#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

using namespace std;

CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string& str)
{
	size_t tempLength = 0;
	size_t pos = 0;
	bool flag = true;

	Utilities utils;

	while (flag)
	{
		string temp;
		temp = utils.extractToken(str, pos, flag);

		if (!flag)
			temp = str.substr(pos);

		tempLength++;

		if (m_widthField < utils.getFieldWidth())
			m_widthField = temp.length();
	}

	m_cntItem = tempLength - 2;
	pos = 0;

	m_name = utils.extractToken(str, pos, flag);
	m_product = utils.extractToken(str, pos, flag);

	m_lstItem = new Item * [m_cntItem];

	for (size_t i = 0; i < m_cntItem - 1; i++)
	{
		m_lstItem[i] = new Item(utils.extractToken(str, pos, flag));
	}

	m_lstItem[m_cntItem - 1] = new Item(str.substr(pos));
}

CustomerOrder::CustomerOrder(const CustomerOrder& src)
{
	throw "";
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
{
	m_lstItem = src.m_lstItem;
	m_cntItem = src.m_cntItem;
	m_name = src.m_name;
	m_product = src.m_product;

	src.m_lstItem = nullptr;
	src.m_cntItem = 0;
	src.m_name = "";
	src.m_product = "";
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
{
	if (this != &src)
	{
		for (size_t i = 0; i < m_cntItem; i++)
			delete m_lstItem[i];
		delete[] m_lstItem;
		m_lstItem = src.m_lstItem;
		m_cntItem = src.m_cntItem;

		m_name = src.m_name;
		m_product = src.m_product;

		src.m_lstItem = nullptr;
		src.m_cntItem = 0;
		src.m_name = "";
		src.m_product = "";
	}

	return *this;
}

CustomerOrder::~CustomerOrder()
{
	for (size_t i = 0; i < m_cntItem; i++)
	{
		delete m_lstItem[i];
		m_lstItem[i] = nullptr;
	}
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isOrderFilled() const
{
	bool val = true;

	for (size_t i = 0; i < m_cntItem && val != false; i++)
	{
		if (!m_lstItem[i]->m_isFilled)
			val = false;
	}

	return val;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	bool val = true;

	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == itemName)
			return m_lstItem[i]->m_isFilled;
	}

	return val;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() >= 1)
		{
			station.updateQuantity();
			m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			m_lstItem[i]->m_isFilled = true;
			os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
		}

		if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() == 0)
		{
			os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << endl;
	for (size_t i = 0; i < m_cntItem; i++)
	{
		os.fill('0');
		os << "[";
		os.width(6);
		os << m_lstItem[i]->m_serialNumber;
		os << "] ";
		os.fill(' ');
		os << std::left;
		os.width(m_widthField);
		os << m_lstItem[i]->m_itemName;
		os << std::right;
		os << " - ";
		if (m_lstItem[i]->m_isFilled)
			os << "FILLED";
		else
			os << "MISSING";
		os << endl;
	}
}
