// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 11/20/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"

namespace sdds {
size_t Station::m_widthField{0};
size_t Station::id_generator{0};

Station::Station(const std::string &str) {
	id_generator++;
	m_id = id_generator;
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;
	try {
		m_name = utility.extractToken(str, next_pos, more);
		m_serial = stoi(utility.extractToken(str, next_pos, more));
		m_stock = stoi(utility.extractToken(str, next_pos, more));
		if (utility.getFieldWidth() > m_widthField) {
			m_widthField = utility.getFieldWidth();
		}
		m_desc = utility.extractToken(str, next_pos, more);
	} catch (std::string &error) {
		std::cout << error;
	}
}

const std::string &Station::getItemName() const {
	return m_name;
}

unsigned int Station::getNextSerialNumber() {
	return m_serial++;
}

unsigned int Station::getQuantity() const {
	return m_stock;
}

void Station::updateQuantity() {
	if (m_stock > 0) {
		m_stock--;
	}
}

void Station::display(std::ostream &os, bool full) const {
	os << std::right << "[" << std::setw(3) << std::setfill('0') << m_id << "]"
	   << std::left << " Item: " << std::setw(m_widthField) << std::setfill(' ')
	   << m_name << std::right << " [" << std::setw(6) << std::setfill('0')
	   << m_serial << "]" << std::left;
	if (full != false) {
		os << " Quantity: " << std::setw(m_widthField) << std::setfill(' ')
		   << m_stock << " Description: " << m_desc;
	}
	os << std::endl;
}
} // namespace sdds