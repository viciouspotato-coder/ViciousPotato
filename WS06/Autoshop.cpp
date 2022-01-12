// Workshop 6 - STL Containers
// 2021/07/11 - Henry Tao

#include "Autoshop.h"

namespace sdds
{
    Autoshop &Autoshop::operator+=(Vehicle *theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    Autoshop::~Autoshop()
    {
        for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++)
        {
            delete *i;
        }
    }

    void Autoshop::display(std::ostream &out) const
    {
        out << "--------------------------------" << std::endl
            << "| Cars in the autoshop!        |" << std::endl
            << "--------------------------------" << std::endl;
        for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++)
        {
            (*i)->display(out);
            out << std::endl;
        }
        out << "--------------------------------" << std::endl;
    }
} // namespace sdds