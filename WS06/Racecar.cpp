// Workshop 6 - STL Containers
// 2021/07/11 - Henry Tao

#include "Racecar.h"
#include <string>

namespace sdds
{
    Racecar::Racecar(std::istream &in) : Car(in)
    {
        std::string line;
        std::getline(in, line, ',');
        m_booster = std::stod(trim(line));
    }

    void Racecar::display(std::ostream &out) const
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const
    {
        return Car::topSpeed() * (1 + m_booster);
    }
} // namespace sdds