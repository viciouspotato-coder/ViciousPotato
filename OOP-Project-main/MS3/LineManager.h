// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 12/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include "LineManager.h"
#include "Utilities.h"
#include "Workstation.h"
#include <algorithm>
#include <fstream>
#include <vector>

namespace sdds {
class LineManager {
	std::vector<Workstation *> activeLine;
	size_t m_cntCustomerOrder{0};
	Workstation *m_firstStation{nullptr};

public:
	LineManager(
		const std::string &file,
		const std::vector<Workstation *> &stations);
  void linkStations();
	bool run(std::ostream &os);
	void display(std::ostream &os) const;
};

} // namespace sdds

#endif