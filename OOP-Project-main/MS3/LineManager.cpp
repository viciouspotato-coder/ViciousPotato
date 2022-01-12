// Name: Henry Tao
// Seneca Student ID: 118375203
// Seneca email: htao7@myseneca.ca
// Date of completion: 12/03/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

namespace sdds {
LineManager::LineManager(
	const std::string &file,
	const std::vector<Workstation *> &stations) {
	std::ifstream theFile(file);
	std::string str;
	std::string current;
	std::string next;
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;
	Workstation *station;
	Workstation *nextStation;
	m_cntCustomerOrder = pending.size();
	while (getline(theFile, str)) {
		current = utility.extractToken(str, next_pos, more);
		if (more) {
			next = utility.extractToken(str, next_pos, more);
		} else {
			next = "";
		}
		nextStation = nullptr;
		std::for_each(stations.begin(), stations.end(), [&](Workstation *ws) {
			if (ws->getItemName() == current) {
				station = ws;
			}
			if (next != "" && ws->getItemName() == next) {
				nextStation = ws;
			}
		});
		if (nextStation != nullptr) {
			station->setNextStation(nextStation);
		}
		activeLine.push_back(std::move(station));
	}
}

void LineManager::linkStations() {
	std::vector<Workstation *> newActive;
	std::for_each(
		activeLine.begin(), activeLine.end(), [&](Workstation *i) {
			if (newActive.empty()) {
                std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation *ws) {
                    if (!ws->getNextStation()) {
                        newActive.push_back(ws);
                    }
                });
			} else {
				std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation *ws) {
                    if (ws->getNextStation()) {
                        if (newActive[0]->getItemName() == ws->getNextStation()->getItemName()) {
                            newActive.insert(newActive.begin(), ws);
                        }
                    }
                });
			}
		});
	activeLine = newActive;
	m_firstStation = activeLine.front();
}

bool LineManager::run(std::ostream &os) {
	static size_t line{1};
	os << "Line Manager Iteration: " << line++ << std::endl;
	size_t record = completed.size() + incomplete.size();
	if (!pending.empty()) {
		*activeLine.front() += std::move(pending.front());
		pending.pop_front();
	}
	std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation *ws) {
		ws->fill(os);
	});
	std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation *ws) {
		ws->attemptToMoveOrder();
	});
	m_cntCustomerOrder -= completed.size() + incomplete.size() - record;
	return m_cntCustomerOrder <= 0;
}

void LineManager::display(std::ostream &os) const {
	std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation *ws) {
		ws->display(os);
	});
}
} // namespace sdds