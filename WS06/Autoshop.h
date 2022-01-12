// Workshop 6 - STL Containers
// 2021/07/11 - Henry Tao

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include "Vehicle.h"
#include <vector>
#include <list>

namespace sdds
{
    class Autoshop
    {
        std::vector<Vehicle *> m_vehicles;

    public:
        Autoshop &operator+=(Vehicle *theVehicle);
        ~Autoshop();
        void display(std::ostream &out) const;
        template <typename T>
        void select(T test, std::list<const Vehicle *> &vehicles)
        {
            for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++)
            {
                if (test(*i))
                {
                    vehicles.push_back(*i);
                }
            }
        }
    };
} // namespace sdds

#endif