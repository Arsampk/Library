#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "LibApp.h"
#include "Date.h"
#include "Menu.h"
using namespace seneca;

// Function to run the application with the given filename
void runApp(const char* filename) {
    size_t i{};
    char ch;
    char original[31] = "orig";
    // Creating the original file name by appending "orig" to the given filename
    while (filename[i]) original[4u + i] = filename[i++];
    original[4u + i] = char(0);

    // Copying original values to data file;
    std::ofstream outFile(filename);
    std::ifstream inFile(original);
    while (inFile.get(ch)) {
        outFile << ch;
    }
    outFile.close();
    inFile.close();

    // Setting test values
    seneca::seneca_day = 10;
    seneca::seneca_mon = 8;
    seneca::seneca_year = 2023;
    seneca::seneca_test = true;

    // Creating and running the LibApp with the provided filename
    seneca::LibApp app(filename);
    app.run();

    // Displaying the content of the file after the application run
    std::cout << "Content of " << filename << "\n=========>\n";
    inFile.open(filename);
    while (inFile.get(ch)) std::cout << ch;
    std::cout << "<=========\n";
}

int main() {
    // Creating a menu to select the data file
    Menu outFile("Select Data File");
    outFile << "LibRecsSmall.txt" << "LibRecs.txt";

    // Running the selected test based on the user's choice
    switch (outFile.run()) {
        case 1:
            std::cout << "Test started using small data: " << std::endl;
            runApp("LibRecsSmall.txt");
            break;
        case 2:
            std::cout << "Test started using big data: " << std::endl;
            runApp("LibRecs.txt");
            break;
        default:
            std::cout << "Aborted by user! " << std::endl;
            break;
    }

    return 0;
}