/*
Name: Tim Harris
Date: May 19, 2026
Project: Chada Tech Clocks - Dual Clock Program

Description:
This program displays both a 12-hour and 24-hour clock.
Users can add hours, minutes, or seconds through a menu system.
The program demonstrates modular programming, input validation,
and proper time rollover logic.
*/

#include <iostream>
#include <string>

using namespace std;

// Formats numbers as two digits (07, 12, etc.)
string formatTwoDigits(int number) {
    if (number < 10) {
        return "0" + to_string(number);
    }

    return to_string(number);
}

// Displays the 24-hour clock
void display24Hour(int hour, int minute, int second) {

    cout << formatTwoDigits(hour) << ":"
        << formatTwoDigits(minute) << ":"
        << formatTwoDigits(second);
}

// Displays the 12-hour clock
void display12Hour(int hour, int minute, int second) {

    string period = "AM";
    int displayHour = hour;

    if (hour == 0) {
        displayHour = 12;
    }
    else if (hour == 12) {
        period = "PM";
    }
    else if (hour > 12) {
        displayHour = hour - 12;
        period = "PM";
    }

    cout << formatTwoDigits(displayHour) << ":"
        << formatTwoDigits(minute) << ":"
        << formatTwoDigits(second)
        << " " << period;
}

// Adds one hour
void addHour(int& hour) {

    hour = (hour + 1) % 24;
}

// Adds one minute and handles rollover
void addMinute(int& minute, int& hour) {

    minute++;

    // Reset minutes and increment hours when minutes exceed 59
    if (minute > 59) {
        minute = 0;
        addHour(hour);
    }
}

// Adds one second and handles rollover
void addSecond(int& second, int& minute, int& hour) {

    second++;

    // Reset seconds and increment minutes when seconds exceed 59
    if (second > 59) {
        second = 0;
        addMinute(minute, hour);
    }
}

// Displays both clock formats in a side-by-side layout
void displayBothClocks(int hour, int minute, int second) {

    cout << endl;

    cout << "*************************    *************************" << endl;
    cout << "*     12-Hour Clock    *    *     24-Hour Clock    *" << endl;

    cout << "*      ";
    display12Hour(hour, minute, second);

    cout << "       *    *       ";
    display24Hour(hour, minute, second);

    cout << "          *" << endl;

    cout << "*************************    *************************" << endl;
}

// Displays menu options for user interaction
void printMenu() {

    cout << endl;

    cout << "***********************" << endl;
    cout << "* 1 - Add One Hour    *" << endl;
    cout << "* 2 - Add One Minute  *" << endl;
    cout << "* 3 - Add One Second  *" << endl;
    cout << "* 5 - Reset Clock     *" << endl;
    cout << "* 4 - Exit Program    *" << endl;
    cout << "***********************" << endl;

    cout << "Select an option: ";
}

// Processes user menu input
void processMenuInput(int& hour, int& minute, int& second, bool& running) {

    int choice;

    // Validates that the user entered a numeric menu option
    if (!(cin >> choice)) {

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    switch (choice) {

    case 1:
        addHour(hour);
        break;

    case 2:
        addMinute(minute, hour);
        break;

    case 3:
        addSecond(second, minute, hour);
        break;

    case 5:
        hour = 0;
        minute = 0;
        second = 0;

        cout << "Clock reset to 00:00:00." << endl;
        break;

    case 4:
        running = false;
        cout << "Goodbye!" << endl;
        break;

    default:
        cout << "Invalid option. Please select 1-5." << endl;
        break;
    }
}

int main() {

    int hour = 12;
    int minute = 0;
    int second = 0;

    bool running = true;

    cout << "Welcome to the Chada Tech Dual Clock Program!" << endl;

    // Main program loop continues until user chooses to exit
    while (running) {

        displayBothClocks(hour, minute, second);

        printMenu();

        processMenuInput(hour, minute, second, running);
    }

    return 0;
}