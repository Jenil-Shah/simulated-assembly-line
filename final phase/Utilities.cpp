// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 01 August 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<string>

#include "Utilities.h"

char Utilities::m_delimiter = '\0';

using namespace std;

Utilities::Utilities()
{
	m_widthField = 1;
}

void Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	string token;
	size_t n = str.find(getDelimiter(), next_pos);

	if (n != string::npos)
	{
		token = str.substr(next_pos, n - next_pos);
		next_pos = n + 1;

		if (token == "")
			throw "Empty field";

		more = true;
	}

	else
		more = false;
	
	size_t width = token.length();
	if (width > getFieldWidth())
		setFieldWidth(width);

	return token;
}

void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter()
{
	return m_delimiter;
}
