// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 11/27/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include <algorithm>

namespace sdds {
size_t CustomerOrder::m_widthField{0};

CustomerOrder::CustomerOrder() {
	m_cntItem = 0;
	m_lstItem = nullptr;
};

CustomerOrder::CustomerOrder(std::string &str) {
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;
	m_cntItem = 0;
	m_lstItem = nullptr;
	try {
		m_name = utility.extractToken(str, next_pos, more);
		m_product = utility.extractToken(str, next_pos, more);
		std::string temp = str.substr(next_pos, str.length() - next_pos);
		m_cntItem =
			std::count(temp.begin(), temp.end(), utility.getDelimiter()) + 1;
		m_lstItem = new Item *[m_cntItem];
		for (size_t i = 0; i < m_cntItem && more; i++) {
			m_lstItem[i] = new Item(utility.extractToken(str, next_pos, more));
		}
		if (m_widthField < utility.getFieldWidth()) {
			m_widthField = utility.getFieldWidth();
		}
	} catch (std::string &error) {
		std::cout << error;
	}
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
}

CustomerOrder::CustomerOrder(const CustomerOrder &) {
	throw "ERROR: Cannot make copies.";
}

CustomerOrder::CustomerOrder(CustomerOrder &&src) noexcept {
	m_lstItem = nullptr;
	m_cntItem = 0;
	*this = std::move(src);
}

CustomerOrder &CustomerOrder::operator=(CustomerOrder &&src) noexcept {
	if (this != &src) {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_name = src.m_name;
		m_product = src.m_product;
		m_lstItem = src.m_lstItem;
		m_cntItem = src.m_cntItem;
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;
	}
	return *this;
}

bool CustomerOrder::isFilled() const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_isFilled) {
			return false;
		}
	}
	return true;
}

bool CustomerOrder::isItemFilled(const std::string &itemName) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			return m_lstItem[i]->m_isFilled;
		}
	}
	return true;
}

void CustomerOrder::fillItem(Station &station, std::ostream &os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled " << m_name << ", " << m_product << " ["
				   << m_lstItem[i]->m_itemName << "]";
			} else {
				os << "    Unable to fill " << m_name << ", " << m_product
				   << " [" << m_lstItem[i]->m_itemName << "]";
			}
			os << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream &os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << std::right
		   << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ')
		   << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName;
		if (m_lstItem[i]->m_isFilled) {
			os << " - FILLED";
		} else {
			os << " - TO BE FILLED";
		}
		os << std::endl;
	}
}
} // namespace sdds