// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 01 August 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _STATION_H
#define _STATION_H

#include<iostream>
#include<string>

#include "Utilities.h"

class Station
{
	int stationId;
	std::string stationItem;
	std::string stationDesc;
	unsigned int serialNo;
	unsigned currentStock;

	static size_t m_widthField;
	static unsigned id_generator;

	public:
		Station();
		Station(const std::string str);
		const std::string& getItemName() const;
		unsigned int getNextSerialNumber();
		unsigned int getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
};
#endif
