// Name: Jenil Shah
// Seneca Student ID: 102381191
// Seneca email: jshah43@myseneca.ca
// Date of completion: 01 August 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<fstream>
#include<algorithm>

#include "LineManager.h"

using namespace std;

LineManager::LineManager()
{
	m_cntCustomerOrder = 0;
	startingStation = 0;
	endingStation = 0;
}

LineManager::LineManager(const std::string& str, std::vector<Workstation*>& work, std::vector<CustomerOrder>& co)
{
	m_cntCustomerOrder = 0;

	Utilities utils;
	string token;
	std::vector<string> temp;

	fstream file(str);

	while (std::getline(file, token))
	{
		size_t pos = 0;
		bool flag = true;

		string extr = utils.extractToken(token, pos, flag);
		temp.push_back(extr);
		
		if (flag)
		{
			string extr1 = token.substr(pos);
			temp.push_back(extr1);

			for (size_t i = 0; i < work.size(); i++)
			{
				if (work[i]->getItemName() == extr)
				{
					for (size_t j = 0; j < work.size(); j++)
					{
						if (work[j]->getItemName() == extr1)
							work[i]->setNextStation(*work[j]);
					}
				}
			}
		}
	}

	auto startingItem = std::find_if(work.begin(), work.end(), [=](Workstation* w) {return w->getItemName() == temp[0]; });
	startingStation = (unsigned int)std::distance(work.begin(), startingItem);
	
	auto endingItem = std::find_if(work.begin(), work.end(), [=](Workstation* w) {return w->getItemName() == temp[temp.size() - 2]; });
	endingStation = (unsigned int)std::distance(work.begin(), endingItem);
	

	for (size_t i = 0; i < co.size(); i++)
	{
		ToBeFilled.push_back(std::move(co[i]));
	}

	for (size_t i = 0; i < work.size(); i++)
	{
		AssemblyLine.push_back(work[i]);
	}
}

bool LineManager::run(std::ostream& os)
{
	os << "Line Manager Iteration: " << ++m_cntCustomerOrder << endl;

	bool val = true;

	if (!ToBeFilled.empty())
	{
		*this->AssemblyLine[startingStation] += std::move(this->ToBeFilled.front());

		this->ToBeFilled.pop_front();
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->runProcess(os);
	}

	CustomerOrder co;

	if (this->AssemblyLine[endingStation]->getIfCompleted(co))
	{
		this->Completed.push_back(std::move(co));
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		if (AssemblyLine[i]->moveOrder())
			val = false;
	}

	return val;
}

void LineManager::displayCompletedOrders(std::ostream& os) const
{
	for (size_t i = 0; i < Completed.size(); i++)
	{
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const
{
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->display(cout);
	}
}

void LineManager::displayStationsSorted() const
{
	std::deque<Workstation*> Assemble;
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{
			Assemble.push_back(AssemblyLine[i]);
		}
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		for (size_t j = 0; j < AssemblyLine.size(); j++)
		{
			if (AssemblyLine[j]->getNextStation() == Assemble[0])
				Assemble.push_front(AssemblyLine[j]);
		}	
	}

	for (size_t i = 0; i < Assemble.size(); i++)
	{
		Assemble[i]->display(cout);
	}
}
