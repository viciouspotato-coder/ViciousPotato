// Workshop 6 - STL Containers
// 2021/07/11 - Henry Tao

#include "Racecar.h"
#include "Utilities.h"
#include <sstream>

namespace sdds
{
    Vehicle *createInstance(std::istream &in)
    {
        char temp, dummy;
        std::string substr = "";
        getline(in, substr);
        std::stringstream input(substr);
        input >> temp >> dummy;
        if (input)
        {
            if (temp == 'c' || temp == 'C')
            {
                return new Car(input);
            }
            else if (temp == 'r' || temp == 'R')
            {
                return new Racecar(input);
            }
            else
                throw temp;
        }
        return nullptr;
    }
} // namespace sdds