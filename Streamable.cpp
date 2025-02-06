#include <iostream>
#include "Streamable.h"

using namespace std;

namespace seneca
{
    std::ostream& operator<<(std::ostream& os, const Streamable& stream)
    {
        if (stream)
            stream.write(os);
        // else
        //     os << "a";

        return os;
    }
    std::istream& operator >> (std::istream& is, Streamable& stream)
    {
        stream.read(is);

        return is;
    }

    Streamable::~Streamable()
    {

    }
}