// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 12/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

namespace sdds {
std::deque<sdds::CustomerOrder> pending{};
std::deque<sdds::CustomerOrder> completed{};
std::deque<sdds::CustomerOrder> incomplete{};

Workstation::Workstation(const std::string &str) : Station(str) {
}

void Workstation::fill(std::ostream &os) {
	if (!m_orders.empty()) {
		m_orders.begin()->fillItem(*this, os);
	}
}

bool Workstation::attemptToMoveOrder() {
	if (m_orders.empty()) {
		return false;
	}
	if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0) {
		if (m_pNextStation != nullptr) {
			*m_pNextStation += std::move(m_orders.front());
		} else {
			if (m_orders.front().isFilled()) {
				completed.push_back(std::move(m_orders.front()));
			} else {
				incomplete.push_back(std::move(m_orders.front()));
			}
		}
		m_orders.pop_front();
	}
	return true;
}

void Workstation::setNextStation(Workstation *station) {
	m_pNextStation = station;
}

Workstation *Workstation::getNextStation() const {
	return m_pNextStation;
}

void Workstation::display(std::ostream &os) const {
	os << getItemName() << " --> ";
	if (m_pNextStation == nullptr) {
		os << "End of Line";
	} else {
    os << m_pNextStation->getItemName();
	}
	os << std::endl;
}

Workstation &Workstation::operator+=(CustomerOrder &&newOrder) {
	m_orders.push_back(std::move(newOrder));
	return *this;
}
} // namespace sdds