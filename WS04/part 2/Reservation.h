// Workshop 4 - Containers
// 2021/10/10 - Henry Tao, ID: 118375203

#ifndef SDDS_RESERVATION_H_
#define SDDS_RESERVATION_H_
#include <string>
namespace sdds
{
    class Reservation
    {
        std::string m_id;
        std::string m_name;
        std::string m_email;
        int m_noOfPeople;
        int m_day;
        int m_hour;

    public:
        void trim(std::string &);
        Reservation();
        void update(int day, int time);
        Reservation(const std::string &res);
        std::ostream &display(std::ostream &ostr) const;
        ~Reservation();
    };
    std::ostream &operator<<(std::ostream &ostr, const Reservation &D);
}
#endif