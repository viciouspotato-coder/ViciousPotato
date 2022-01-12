// Workshop 4 - Containers
// 2021/10/10 - Henry Tao, ID: 118375203

#include "Reservation.h"
#include <iomanip>
#include <iostream>

namespace sdds
{
    void Reservation::trim(std::string &str)
    {
        auto start = str.begin();
        while (start != str.end() && std::isspace(*start))
        {
            start++;
        }
        auto end = str.end();
        do
        {
            end--;
        } while (std::distance(start, end) > 0 && std::isspace(*end));
        str = {std::string(start, end + 1)};
    }

    Reservation::Reservation()
        : m_id{""}, m_name{""}, m_email{""}, m_noOfPeople{0}, m_day{0}, m_hour{0}
    {
    }

    void Reservation::update(int day, int time)
    {
        this->m_day = {day};
        this->m_hour = {time};
    }

    Reservation::Reservation(const std::string &res)
    {
        std::string line = res;
        int position;
        position = line.find(":");
        m_id = {line.substr(0, position)};
        line.erase(0, position + 1);
        position = line.find(",");
        m_name = {line.substr(0, position)};
        line.erase(0, position + 1);
        position = line.find(",");
        m_email = {line.substr(0, position)};
        line.erase(0, position + 1);
        position = line.find(",");
        m_noOfPeople = {stoi(line.substr(0, position))};
        line.erase(0, position + 1);
        position = line.find(",");
        m_day = {stoi(line.substr(0, position))};
        line.erase(0, position + 1);
        position = line.find(",");
        m_hour = {stoi(line.substr(0, position))};
        line.erase(0, position + 1);
        trim(m_id);
        trim(m_name);
        trim(m_email);
    }

    std::ostream &Reservation::display(std::ostream &ostr) const
    {
        ostr << "Reservation " << std::right << std::setw(10) << m_id << ":"
             << std::right << std::setw(21) << m_name << "  " << std::left
             << std::setw(24) << ("<" + m_email + ">");
        if (m_hour >= 6 && m_hour <= 9)
        {
            ostr << "Breakfast";
        }
        else if (m_hour >= 11 && m_hour <= 15)
        {
            ostr << "Lunch";
        }
        else if (m_hour >= 17 && m_hour <= 21)
        {
            ostr << "Dinner";
        }
        else
        {
            ostr << "Drinks";
        }
        ostr << " on day " << m_day << " @ " << m_hour << ":00 for "
             << m_noOfPeople << " ";
        if (m_noOfPeople == 1)
        {
            ostr << "person." << std::endl;
        }
        else
        {
            ostr << "people." << std::endl;
        }
        return ostr;
    }

    Reservation::~Reservation()
    {
    }

    std::ostream &operator<<(std::ostream &ostr, const Reservation &D)
    {
        return D.display(ostr);
    }
} // namespace sdds