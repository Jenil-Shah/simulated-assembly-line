// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 22 July 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _UTILITIES_H
#define _UTILITIES_H

#include<iostream>
#include<string>

class Utilities
{
	size_t m_widthField;
	static char m_delimiter;

	public:
		Utilities();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
};
#endif