// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 01 August 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<string>

#include "Station.h"

size_t Station::m_widthField = 0;
unsigned Station::id_generator = 0;

using namespace std;

Station::Station()
{
	stationId = 0;
	stationItem = "";
	stationDesc = "";
	serialNo = 0;
	currentStock = 0;
}

Station::Station(const string str)
{
	size_t pos = 0;
	size_t i = 0;
	bool flag = false;
	string token[3];
	
	Utilities utils;

	while (i < 3)
	{
		token[i] = utils.extractToken(str, pos, flag);

		if (token[i].length() > m_widthField)
			m_widthField = token[i].length();

		i++;
	}

	stationId = ++id_generator;
	stationItem = token[0];
	serialNo = stoi(token[1]);
	currentStock = stoi(token[2]);
	stationDesc = str.substr(pos);
}

const string& Station::getItemName() const
{
	return stationItem;
}

unsigned int Station::getNextSerialNumber()
{
	return serialNo++;
}

unsigned int Station::getQuantity() const
{
	return currentStock;
}

void Station::updateQuantity()
{
	if (currentStock - 1 >= 0)
		currentStock--;
}

void Station::display(ostream& os, bool full) const
{
	os << "[";
	os.fill('0');
	os.width(3);
	os << stationId;
	os << "] ";
	os << "Item: ";
	os.fill(' ');
	os << std::left;
	os.width(m_widthField);
	os << getItemName();
	os << std::right;
	os << " [";
	os.fill('0');
	os.width(6);
	os << serialNo;
	os.fill(' ');
	os << "]";

	if (full)
	{
		os << " Quantity: ";
		os.width(m_widthField);
		os << std::left;
		os << getQuantity();
		os << std::right;
		os << " Description: " << stationDesc;
	}

	os << endl;
}
