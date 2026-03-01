/*
Madison Cox
01/30/25
Chada Tech Clock Project - Module 3
*/

#include <iostream>
using namespace std;

// Time options
int hour;
int minute;
int second;

// Function to add one hour to the current time

void addHour() {
    hour = hour + 1;
    if (hour == 24) {
        hour = 0;
    }
}

// Function to add one minute to the current time
void addMinute() {
    minute = minute + 1;
    if (minute == 60) {
        minute = 0;
        addHour();
    }
}

// Function to add one second to the current time
void addSecond() {
    second = second + 1;
    if (second == 60) {
        second = 0;
        addMinute();
    }
}

// Function to display both clocks at once
void displayClocks() {

    
    int hour12;
    string period;

    if (hour >= 12) {
        period = "PM";
    } else {
        period = "AM"; 
    }

    hour12 = hour % 12;
    if (hour12 == 0) {
        hour12 = 12;
    }

    cout << "**************************    **************************" << endl;
    cout << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl;
   
    cout << "*         "
         << hour12 << ":" << minute << ":" << second << "       *    ";
    
    cout << "*            "
         << hour << ":" << minute << ":" << second << "    *\n";

    cout << "**************************    **************************" << endl;
}

    // The Options Menu
    void displayMenu() {
        cout << "\n************** MENU **************\n" << endl;
        cout << "1 - Add One Hour" << endl;
        cout << "2 - Add One Minute" << endl;
        cout << "3 - Add One Second" << endl;
        cout << "4 - Exit Chada Clock Program" << endl;
        cout << "**********************************\n";
    }
    
    int main() {
        int choice = 0;

        // Get Users Current Time Input
        cout << "Enter the current hour (0-23): ";
        cin >> hour;
        cout << "Enter the current minute (0-59): ";
        cin >> minute;
        cout << "Enter the current second (0-59): ";
        cin >> second;

        while (choice != 4) {
            displayClocks();
            displayMenu();

            cout << "Select an option: ";
            cin >> choice;

            if (choice == 1) {
                addHour();
            } else if (choice == 2) {
                addMinute();
            } else if (choice == 3) {
                addSecond();
            } else if (choice == 4) {
                cout << "You are Exiting Chada Clock Program. Goodbye!" << endl;
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        }

        return 0;
    }