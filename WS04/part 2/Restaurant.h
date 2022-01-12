// Workshop 4 - Containers
// 2021/10/10 - Henry Tao, ID: 118375203

#ifndef SDDS_RESTAURANT_H_
#define SDDS_RESTAURANT_H_
#include "Reservation.h"
namespace sdds
{
    class Restaurant
    {
        Reservation *m_reservations;
        size_t m_numOfReservations;

    public:
        Restaurant();
        Restaurant(const Reservation *reservations[], size_t cnt);
        Restaurant(const Restaurant &);
        Restaurant &operator=(const Restaurant &);
        Restaurant(Restaurant &&);
        Restaurant &operator=(Restaurant &&);
        ~Restaurant();
        void display(std::ostream &) const;
        size_t size() const;
    };
    std::ostream &operator<<(std::ostream &, const Restaurant &);
}
#endif