// Workshop 7 - STL Algorithms
// 2021/14/11 - Henry Tao

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <numeric>

namespace sdds {
struct Song {
	std::string m_artist, m_title, m_album, m_year;
	int m_length;
  double m_price;
};

class SongCollection {
	int m_total{0};
	std::vector<Song> m_songs;

public:
	SongCollection(std::string);
	void display(std::ostream &) const;
	void sort(std::string);
	void cleanAlbum();
	bool inCollection(std::string) const;
	std::list<Song> getSongsForArtist(std::string) const;
};
std::ostream &operator<<(std::ostream &, const Song &);
void trim(std::string &);
} // namespace sdds

#endif