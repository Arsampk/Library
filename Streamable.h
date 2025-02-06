#ifndef SENEC_ISTREAMABLE_H
#define SENEC_ISTREAMABLE_H
#include <iostream>

namespace seneca
{
    class Streamable
    {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(std::ios& ios) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
        friend std::ostream& operator<<(std::ostream& os, const Streamable& stream);
        friend std::istream& operator >> (std::istream& is, Streamable& stream);

    };
}

#endif