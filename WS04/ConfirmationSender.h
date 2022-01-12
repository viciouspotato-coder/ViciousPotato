// Workshop 4 - Containers
// 2021/10/10 - Henry Tao, ID: 118375203

#ifndef SDDS_CONFIRMATIONSENDER_H_
#define SDDS_CONFIRMATIONSENDER_H_
#include <iostream>
#include "Reservation.h"
namespace sdds
{
    class ConfirmationSender
    {
        const Reservation **m_reservationAddress;
        int m_currentAddresses;

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender &);
        ConfirmationSender &operator=(const ConfirmationSender &);
        ConfirmationSender(ConfirmationSender &&);
        ConfirmationSender &operator=(ConfirmationSender &&);
        ~ConfirmationSender();
        ConfirmationSender &operator+=(const Reservation &);
        ConfirmationSender &operator-=(const Reservation &);
        void display(std::ostream &) const;
        size_t size() const;
    };
    std::ostream &operator<<(std::ostream &, ConfirmationSender &);
}
#endif