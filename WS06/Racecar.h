// Workshop 6 - STL Containers
// 2021/07/11 - Henry Tao

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <istream>
#include "Car.h"

namespace sdds
{
    class Racecar : public Car
    {
        double m_booster{0};

    public:
        Racecar(std::istream &in);
        void display(std::ostream &out) const;
        double topSpeed() const;
    };
}
#endif