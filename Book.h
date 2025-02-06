
#ifndef SENEC_BOOK_H_
#define SENEC_BOOK_H_
#include "Publication.h"
namespace seneca
{
    class Book : public Publication
    {
        char* m_authorName; //holds an author's name Dynamically
    public:
        Book(); //default constructor
        //The rule of three
        //copy constructor
        Book(const Book& B);
        //copy assignment
        Book& operator=(const Book& B);
        //destructor
        ~Book();
        //Methods
        //
        //Returns the character "B".
        virtual char type()const;
        //Write method
        std::ostream& write(std::ostream& os) const;
        //Read method
        std::istream& read(std::istream& is);
        //set method
        void set(int memberId);
        //Operator bool method
        operator bool() const;
    };
}

#endif