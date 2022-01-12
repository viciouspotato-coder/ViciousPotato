// Workshop 4 - Containers
// 2021/10/10 - Henry Tao, ID: 118375203

#include "Reservation.h"
#include "Restaurant.h"
#include <iostream>

namespace sdds
{
    Restaurant::Restaurant() : m_reservations{nullptr}, m_numOfReservations{0}
    {
    }

    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt)
    {
        if (cnt > 0 && reservations != nullptr)
        {
            m_numOfReservations = {cnt};
            m_reservations = new Reservation[cnt];
            for (unsigned int i = 0; i < cnt; i++)
            {
                if (reservations[i] != nullptr)
                {
                    m_reservations[i] = *reservations[i];
                }
            }
        }
    }

    Restaurant::Restaurant(const Restaurant &target)
    {
        *this = Restaurant();
        *this = target;
    }

    Restaurant &Restaurant::operator=(const Restaurant &target)
    {
        if (this != &target)
        {
            delete[] m_reservations;
            m_reservations = new Reservation[target.m_numOfReservations];
            m_numOfReservations = {target.m_numOfReservations};
            for (unsigned int i = 0; i < m_numOfReservations; i++)
            {
                m_reservations[i] = {target.m_reservations[i]};
            }
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant &&target)
    {
        *this = std::move(target);
    }

    Restaurant &Restaurant::operator=(Restaurant &&target)
    {
        if (this != &target)
        {
            m_reservations = target.m_reservations;
            m_numOfReservations = target.m_numOfReservations;
            target.m_reservations = {nullptr};
            target.m_numOfReservations = {0};
        }
        return *this;
    }

    Restaurant::~Restaurant()
    {
        delete[] m_reservations;
        m_reservations = {nullptr};
    }

    void Restaurant::display(std::ostream &os) const
    {
        static int counter = 1;
        os << "--------------------------" << std::endl
           << "Fancy Restaurant (" << counter << ")" << std::endl
           << "--------------------------" << std::endl;
        counter++;
        if (m_numOfReservations > 0)
        {
            for (unsigned int i = 0; i < m_numOfReservations; i++)
            {
                m_reservations[i].display(os);
            }
            os << "--------------------------" << std::endl;
        }
        else
        {
            os << "This restaurant is empty!" << std::endl
               << "--------------------------" << std::endl;
        }
    }

    size_t Restaurant::size() const
    {
        return size_t(m_numOfReservations);
    }

    std::ostream &operator<<(std::ostream &os, const Restaurant &target)
    {
        target.display(os);
        return os;
    }
} // namespace sdds