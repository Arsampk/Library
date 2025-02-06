#ifndef SENEC_LIBAPP_H
#define SENEC_LIBAPP_H
#include "Publication.h"
#include "Lib.h"
#include "Menu.h"
namespace seneca {
    class LibApp
    {
        bool m_changed;

        Menu m_mainMenu;

        Menu m_exitMenu;


        char m_filename[256]; //to hold the publication data file name

        Publication* m_ppa[SENEC_LIBRARY_CAPACITY]; //This array will be populated with all the records of the publication data file when the LibApp is instantiated.

        int m_nolp; //Add an integer to hold the number of Publications loaded into the PPA

        int m_llrn; //Add an integer to hold the last library reference number read from the data file.

        Menu m_pubTypeMenu; //publication typemenu




        //had this before
        bool confirm(const char* message); //Instantiate a Menu in this functionand initialize it with the message argument.
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        int search(int mode);  // prints: "Searching for publication"<NEWLINE>

        Publication* getPub(int libRef);
        void newPublication(); //prints "Adding new publication to library"+newline
        void removePublication(); //prints "Removing publication from library"+newline
        void checkOutPub(); //calls the search method
        void returnPub();



    public:
        //Constructor
        void run();

        LibApp(const char* filename);


        ~LibApp();

    };
}
#endif



