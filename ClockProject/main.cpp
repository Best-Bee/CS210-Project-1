#include "Clock.h"
#include <iostream>
#include <iomanip>

//*************************************************
//
//  Author: Bee Best
//  Date: 1/28/2024
//  
//  Project: Clock
//  Purpose: To simulate both a 12 hour formatted 
//           clock and a 24 hour one simultaneously
//
//*************************************************


int main() {
    // init vars
    int initialHours, initialMinutes, initialSeconds;

    // prompt user and get user input for time
    std::cout << "Enter initial time (HH MM SS): ";
    std::cin >> initialHours >> initialMinutes >> initialSeconds;

    // create two clock objects with the time
    Clock clock12((int) initialHours, (int) initialMinutes, (int) initialSeconds);
    Clock clock24((int) initialHours, (int) initialMinutes, (int) initialSeconds);

    // display menu and do menu stuff
    int choice;
    do {
        // call function to display the menu
        clock12.displayMenu();
        // get user choice
        std::cin >> choice;

        // switch case to check what choice user made
        switch (choice) {
        case 1:
            // add one hour to the time before displaying the time in both formats
            clock12.addHour();
            clock24.addHour();
            clock12.trimmedTime();
            clock24.displayTime();
            break;
        case 2:
            // add one minute to the time before displaying the time in both formats
            clock12.addMinute();
            clock24.addMinute();
            clock12.trimmedTime();
            clock24.displayTime();
            break;
        case 3:
            // add one second to the time before displaying the time in both formats
            clock12.addSecond();
            clock24.addSecond();
            clock12.trimmedTime();
            clock24.displayTime();
            break;
        case 4:
            // exit text
            std::cout << "Exiting...\n";
            break;
        default:
            // invalid choice text
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);  // loop until user exits

    return 0;
}