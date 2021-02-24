// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 22 July 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _CUSTOMERORDER_H
#define _CUSTOMERORDER_H

#include<iostream>
#include<string>

#include "Utilities.h"
#include "Station.h"

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;

	static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(std::string& str);
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src) noexcept;
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
};
#endif