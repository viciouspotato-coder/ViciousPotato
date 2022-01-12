// Workshop 6 - STL Containers
// 2021/07/11 - Henry Tao

#include "Car.h"
#include <iomanip>
#include <string>
#include <exception>

namespace sdds
{
    Car::Car(std::istream &istr)
    {
        std::string line;
        std::getline(istr, line, ',');
        m_maker = trim(line);
        std::getline(istr, line, ',');
        line = trim(line);
        if (line.empty())
            m_condition = 'n';
        else
        {
            m_condition = line[0];
            if (m_condition != 'u' && m_condition != 'n' && m_condition != 'b')
            {
                throw std::invalid_argument("Invalid Record!");
            }
        }
        try
        {
            std::getline(istr, line, ',');
            m_speed = stod(trim(line));
        }
        catch (...)
        {
            throw std::invalid_argument("Invalid Record!");
        }
    }

    std::string Car::condition() const
    {
        std::string condition;
        switch (m_condition)
        {
        case 'n':
            condition = "new";
            break;
        case 'u':
            condition = "used";
            break;
        case 'b':
            condition = "broken";
            break;
        }
        return condition;
    }

    double Car::topSpeed() const
    {
        return m_speed;
    }

    void Car::display(std::ostream &out) const
    {
        out << "| " << std::setw(10) << std::right << m_maker
            << " | " << std::setw(6) << std::left << condition()
            << " | " << std::fixed << std::setw(6) << std::setprecision(2) << topSpeed() << " |";
    }

    std::string trim(std::string &str)
    {
        std::string line;
        line = str.substr(0, str.find(","));
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        str.erase(0, str.find(",") + 1);
        return line;
    }
} // namespace sdds