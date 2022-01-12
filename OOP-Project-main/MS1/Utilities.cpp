// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 11/20/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
char Utilities::m_delimiter{' '};

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string
Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more) {
	size_t pos = next_pos;
	std::string token = "";
	next_pos = str.find(m_delimiter, pos);
	if (pos == next_pos) {
		more = false;
		throw "No token.";
	} else if (next_pos == std::string::npos) {
		token = str.substr(pos);
		m_widthField = std::max(token.length(), m_widthField);
		more = false;
	} else {
		token = str.substr(pos, next_pos - pos);
		m_widthField = std::max(token.length(), m_widthField);
		more = true;
	}
	next_pos++;
	return token;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}
} // namespace sdds