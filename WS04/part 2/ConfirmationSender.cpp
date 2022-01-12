// Workshop 4 - Containers
// 2021/10/10 - Henry Tao, ID: 118375203

#include "ConfirmationSender.h"
#include <iostream>

namespace sdds
{
	ConfirmationSender::ConfirmationSender()
		: m_reservationAddress{nullptr}, m_currentAddresses{0}
	{
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender &target)
	{
		*this = ConfirmationSender();
		*this = target;
	}

	ConfirmationSender &ConfirmationSender::
	operator=(const ConfirmationSender &target)
	{
		if (this != &target)
		{
			delete[] m_reservationAddress;
			m_reservationAddress =
				new const Reservation *[target.m_currentAddresses];
			m_currentAddresses = {target.m_currentAddresses};
			for (int i = 0; i < target.m_currentAddresses; i++)
			{
				m_reservationAddress[i] = target.m_reservationAddress[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender &&target)
	{
		*this = std::move(target);
	}

	ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&target)
	{
		if (this != &target)
		{
			m_reservationAddress = {target.m_reservationAddress};
			m_currentAddresses = {target.m_currentAddresses};
			target.m_reservationAddress = {nullptr};
			target.m_currentAddresses = {0};
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_reservationAddress;
		m_reservationAddress = {nullptr};
	}

	ConfirmationSender &ConfirmationSender::operator+=(const Reservation &target)
	{
		if (!m_currentAddresses)
		{
			m_reservationAddress = new const Reservation *[20];
			m_reservationAddress[m_currentAddresses] = {&target};
			m_currentAddresses++;
		}
		else
		{
			bool found{false};
			for (int i = 0; i < m_currentAddresses; i++)
			{
				if (m_reservationAddress[i] == &target)
				{
					found = {true};
				}
			}
			if (!found)
			{
				m_reservationAddress[m_currentAddresses] = {&target};
				m_currentAddresses++;
			}
		}
		return *this;
	}

	ConfirmationSender &ConfirmationSender::operator-=(const Reservation &target)
	{
		for (int i = 0; i < m_currentAddresses; i++)
		{
			if (m_reservationAddress[i] == &target)
			{
				m_reservationAddress[i] = {nullptr};
				for (; i < m_currentAddresses; i++)
				{
					m_reservationAddress[i] = {m_reservationAddress[i + 1]};
				}
				m_reservationAddress[i - 1] = {nullptr};
				m_currentAddresses--;
			}
		}
		return *this;
	}

	void ConfirmationSender::display(std::ostream &os) const
	{
		os << "--------------------------" << std::endl
		   << "Confirmations to Send" << std::endl
		   << "--------------------------" << std::endl;
		if (m_currentAddresses > 0)
		{
			for (int i = 0; i < m_currentAddresses; i++)
			{
				m_reservationAddress[i]->display(os);
			}
		}
		else
		{
			os << "There are no confirmations to send!" << std::endl;
		}
		os << "--------------------------" << std::endl;
	}

	size_t ConfirmationSender::size() const
	{
		return m_currentAddresses;
	}

	std::ostream &operator<<(std::ostream &os, ConfirmationSender &target)
	{
		target.display(os);
		return os;
	}
} // namespace sdds