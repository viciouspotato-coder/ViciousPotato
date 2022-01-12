// Workshop 7 - STL Algorithms
// 2021/14/11 - Henry Tao

#include "SongCollection.h"

namespace sdds {
SongCollection::SongCollection(std::string filename) {
	m_total = 0;
	std::fstream file(filename);
	while (file) {
		Song input;
		std::string line;
		getline(file, line, '\n');
		input.m_title = line.substr(0, 25);
		trim(input.m_title);
		line.erase(0, 25);
		input.m_artist = line.substr(0, 25);
		trim(input.m_artist);
		line.erase(0, 25);
		input.m_album = line.substr(0, 25);
		trim(input.m_album);
		line.erase(0, 25);
		input.m_year = line.substr(0, 5);
		trim(input.m_year);
		line.erase(0, 5);
		std::string temp;
		temp = line.substr(0, 5);
		std::stringstream length(temp);
		length >> input.m_length;
		line.erase(0, 5);
		temp = line.substr(0, 5);
		std::stringstream price(temp);
		price >> input.m_price;
		m_songs.push_back(input);
	}
	m_songs.pop_back();
	// for (auto &i : m_songs) {
	// 	m_total += i.m_length;
	// }
	m_total = std::accumulate(
		m_songs.begin(), m_songs.end(), 0, [](int i, const Song &list) {
			return list.m_length + i;
		}
	);
}

void SongCollection::display(std::ostream &out) const {
	for (auto &i : m_songs) {
		out << i << std::endl;
	}
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
	std::string string =
		"Total Listening Time: " + std::to_string(m_total / 3600) + ":" +
		std::to_string((m_total / 60) % 60) + ":" +
		std::to_string(m_total % 60);
	out << "|" << std::right << std::setw(85) << std::setfill(' ') << string
		<< " |" << std::endl;
}

void SongCollection::sort(std::string option) {
	if (option == "title") {
		std::sort(m_songs.begin(), m_songs.end(), [](Song first, Song second) {
			return first.m_title < second.m_title;
		});
	} else if (option == "artist") {
		std::sort(m_songs.begin(), m_songs.end(), [](Song first, Song second) {
			return first.m_artist < second.m_artist;
		});
	} else if (option == "album") {
		std::sort(m_songs.begin(), m_songs.end(), [](Song first, Song second) {
			return first.m_album < second.m_album;
		});
	} else if (option == "length") {
		std::sort(m_songs.begin(), m_songs.end(), [](Song first, Song second) {
			return first.m_length < second.m_length;
		});
	}
}

void SongCollection::cleanAlbum() {
	for (auto &i : m_songs) {
		if (i.m_album == "[None]") {
			i.m_album = "";
		}
	}
	// std::replace_if(
	// 	m_songs.begin(),
	// 	m_songs.end(),
	// 	[](const Song &list) { return list.m_album == "[None]"; },
	// 	"");
}

bool SongCollection::inCollection(std::string artist) const {
	auto found =
		find_if(m_songs.begin(), m_songs.end(), [&artist](const Song &list) {
			return list.m_artist == artist;
		});
	return found != m_songs.end();
}

std::list<Song> SongCollection::getSongsForArtist(std::string artist) const {
	// for (auto &i : m_songs) {
	// 	if (i.m_artist == artist) {
	// 		artistSongs.push_back(i);
	// 	}
	// }
	size_t size =
		count_if(m_songs.begin(), m_songs.end(), [&artist](const Song &list) {
			return list.m_artist == artist;
		});
	std::list<Song> artistSongs(size);
	copy_if(
		m_songs.begin(),
		m_songs.end(),
		artistSongs.begin(),
		[&artist](const Song &list) { return list.m_artist == artist; });
	return artistSongs;
}

std::ostream &operator<<(std::ostream &out, const Song &theSong) {
	out << "| " << std::left << std::setw(20) << theSong.m_title << " | "
		<< std::left << std::setw(15) << theSong.m_artist << " | " << std::left
		<< std::setw(20) << theSong.m_album << " | " << std::right
		<< std::setw(6) << theSong.m_year << " | " << theSong.m_length / 60
		<< ":" << std::setw(2) << std::setfill('0') << theSong.m_length % 60
		<< std::setfill(' ') << " | " << theSong.m_price << " |";
	return out;
}

void trim(std::string &str) {
	auto start = str.begin();
	while (start != str.end() && std::isspace(*start)) {
		start++;
	}
	auto end = str.end();
	do {
		end--;
	} while (std::distance(start, end) > 0 && std::isspace(*end));
	str = {std::string(start, end + 1)};
}
} // namespace sdds