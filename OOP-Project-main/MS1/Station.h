// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 11/20/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include "Utilities.h"
#include <iomanip>

namespace sdds {
class Station {
	int m_id;
	std::string m_name;
	std::string m_desc;
	int m_serial;
	int m_stock;
	static size_t m_widthField;
	static size_t id_generator;

public:
	Station(const std::string &);
	const std::string &getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream &os, bool full) const;
};
} // namespace sdds

#endif