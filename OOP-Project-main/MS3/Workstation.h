// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 12/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include "CustomerOrder.h"
#include "Station.h"
#include <iostream>
#include <deque>

namespace sdds {
extern std::deque<sdds::CustomerOrder> pending;
extern std::deque<sdds::CustomerOrder> completed;
extern std::deque<sdds::CustomerOrder> incomplete;

class Workstation : public Station {
	std::deque<CustomerOrder> m_orders;
	Workstation *m_pNextStation{nullptr};

public:
	Workstation(const std::string &);
	void fill(std::ostream &os);
	bool attemptToMoveOrder();
	void setNextStation(Workstation *station);
	Workstation *getNextStation() const;
	void display(std::ostream &os) const;
	Workstation &operator+=(CustomerOrder &&newOrder);
};
} // namespace sdds

#endif