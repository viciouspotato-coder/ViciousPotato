// Workshop 6 - STL Containers
// 2021/07/11 - Henry Tao

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds
{
    class Car : public Vehicle
    {
        std::string m_maker{};
        char m_condition{};
        double m_speed{};

    public:
        Car(){};
        ~Car(){};
        Car(std::istream &);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream &out) const;
    };
    std::string trim(std::string &str);
}

#endif
