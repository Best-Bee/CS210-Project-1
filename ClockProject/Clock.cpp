#include "Clock.h"
#include <iostream>
#include <iomanip>

// constructor to init a clock object
Clock::Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

// adds hours to the clock, ensuring the value does not exceed 24
void Clock::addHour() {
    hours ++;
    hours %= 24;
}

// adds minutes to the clock, ensuring the value does not exceed 60, if it does, adjust hours as necessary
void Clock::addMinute() {
    minutes ++;
    hours += minutes / 60;
    minutes %= 60;
    hours %= 24;
}

// adds seconds to the clock, ensuring the value does not exceed 60, if it does, adjust hours and minutes as necessary
void Clock::addSecond() {
    seconds ++;
    minutes += seconds / 60;
    seconds %= 60;
    hours += minutes / 60;
    minutes %= 60;
    hours %= 24;
}

// display time in 24H HH:MM:SS format
void Clock::displayTime() {
    std::cout << "*";
    for (int i = 0; i < 23; ++i) {
        std::cout << "*";
    }
    std::cout << "*\n";
    
    // formatting (I'll explain one line of it, it would be super repettitive if I explained every line)
    std::cout << "*";
    // this line sets the width of text to 18, blank space to " ", alighnment to right, before finally printing "     24-Hour Clock"
    std::cout << std::setw(18) << std::setfill(' ') << std::right << "24-Hour Clock"; // 13 (length of text, used when centering)
    std::cout << std::setw(7) << std::setfill(' ') << std::right << "*\n";

    // formatting
    std::cout << "*";
    std::cout << std::setfill(' ') << std::setw(8) << std::right << " ";
    std::cout << std::setw(2) << std::right << std::setfill('0') << hours << ":";
    std::cout << std::setw(2) << std::right << std::setfill('0') << minutes << ":";
    std::cout << std::setw(2) << std::right << std::setfill('0') << seconds << " ";
    std::cout << std::setw(8) << std::setfill(' ') << std::right << "*\n";

    std::cout << "*";
    for (int i = 0; i < 23; ++i) {
        std::cout << "*";
    }
    std::cout << "*\n";
}

// display time in 12H HH:MM:SS __ format where __ is AM or PM
void Clock::trimmedTime() {

    // checks what the displayed num would be (1 - 12)
    int displayHours = hours % 12;
    // checks the time of day (morning or afternoon for AM or PM)
    std::string period = (hours < 12) ? "AM" : "PM";

    // checks for midnight
    if (displayHours == 0) {
        displayHours = 12;
    }
    
    std::cout << "*";
    for (int i = 0; i < 23; ++i) {
        std::cout << "*";
    }
    std::cout << "*\n";

    // formatting
    std::cout << "*";
    std::cout << std::setw(18) << std::setfill(' ') << std::right << "12-Hour Clock"; //13
    std::cout << std::setw(7) << std::setfill(' ') << std::right << "*\n";

    // formatting
    std::cout << "*";
    std::cout << std::setfill(' ') << std::setw(6) << std::right << " ";
    std::cout << std::setw(2) << std::right << std::setfill('0') << displayHours << ":";
    std::cout << std::setw(2) << std::right << std::setfill('0') << minutes << ":";
    std::cout << std::setw(2) << std::right << std::setfill('0') << seconds << " " << period;
    std::cout << std::setw(8) << std::setfill(' ') << std::right << "*\n";

    std::cout << "*";
    for (int i = 0; i < 23; ++i) {
        std::cout << "*";
    }
    std::cout << "*\n";
}

void Clock::displayMenu() {
    std::cout << "\n********************\n";
    std::cout <<   "* 1-Add Hour       *\n";
    std::cout <<   "* 2-Add Minute     *\n";
    std::cout <<   "* 3-Add Second     *\n";
    std::cout <<   "* 4-Exit           *\n";
    std::cout <<   "********************\n";
}