// Week05_Programming_Assignment.cpp

// This program prompts the user for information related to creative writing.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

// This defines the various function prototypes.
void changeColor(int color);
void displayBanner();
void displayMenu();

string getValidString(string prompt);
int getValidInt(string prompt, int min, int max);
double getValidDouble(string prompt, double min, double max);

double calculateAverage(double totalHours, int writingDays);
void saveReport(string favoriteBook, string favoriteAuthor, int writingDays, double totalHours, double averageHours);

int main()
{
    int menuChoice;

    // These are variables that store user input.
    string favoriteBook = "";
    string favoriteAuthor = "";
    int writingDays = 0;

    // These are variables used for calculations.
    double totalHours = 0.0;
    double averageHours = 0.0;

    // This is a do...while loop that allows the user to run the menu repeatedly until they wish to quit.
    do
    {
        // This calls the displayBanner and displayMenu functions.
        displayBanner();
        displayMenu();

        menuChoice = getValidInt("Enter choice: ", 1, 4);

        switch (menuChoice)
        {
        case 1:
        {
            totalHours = 0.0;

            // This prompts the user about what their favorite book is.
            favoriteBook = getValidString("What is your favorite book? ");

            // This prompts the user about who their favorite author is.
            favoriteAuthor = getValidString("Who is your favorite author? ");

            // This prompts the user about how many days they wrote this week.
            writingDays = getValidInt("How many days did you write this week? Please enter a number between 1 and 7. ", 1, 7);

            // This is a for loop that runs a fixed number of times depending on writingDays.
            for (int day = 1; day <= writingDays; day++)
            {
                double sessionHours =
                    getValidDouble("Hours written on day " + to_string(day) + ": ", 0.0, 24.0);

                totalHours += sessionHours; // This expression is equivalent to totalHours = totalHours + sessionHours.
            }

            // This calculates the average number of hours by calling the calculateAverage function.
            averageHours = calculateAverage(totalHours, writingDays);

            changeColor(10); // Green

            // This compound boolean comments on the user's writing habits.
            if (writingDays >= 5 && averageHours >= 2.0)
            {
                cout << "\nYou have a strong writing routine.\n";
            }
            else
            {
                cout << "\nKeep building your writing habit.\n";
            }

            // This compound boolean also comments on the user's writing habits.
            if (writingDays >= 3 && totalHours >= 10.0)
            {
                cout << "You are showing excellent commitment.\n";
            }
            else
            {
                cout << "Try increasing your weekly writing time.\n";
            }

            changeColor(7); // Default Gray

            // This displays all the information the user input in a well-formatted summary table.
            cout << "\n";
            cout << "------------- CREATIVE WRITING REPORT -------------\n";

            cout << left << setw(25) << "Favorite Book:"
                << favoriteBook << endl;

            cout << left << setw(25) << "Favorite Author:"
                << favoriteAuthor << endl;

            cout << left << setw(25) << "Writing Days:"
                << writingDays << endl;

            cout << left << setw(25) << "Total Hours:" << fixed << setprecision(2)
                << totalHours << endl;

            cout << left << setw(25) << "Average Hours/Day:"
                << averageHours << endl;

            cout << "---------------------------------------------------\n";

            saveReport(favoriteBook, favoriteAuthor, writingDays, totalHours, averageHours);

            break;
        }

        case 2:
        {
            cout << "\n------------- WRITING REPORT -------------\n";

            if (writingDays == 0)
            {
                cout << "No writing session has been entered yet.\n";
            }
            else
            {
                cout << left << setw(25) << "Favorite Book:"
                    << favoriteBook << endl;

                cout << left << setw(25) << "Favorite Author:"
                    << favoriteAuthor << endl;

                cout << left << setw(25) << "Writing Days:"
                    << writingDays << endl;

                cout << left << setw(25) << "Total Hours:" << fixed << setprecision(2)
                    << totalHours << endl;

                cout << left << setw(25) << "Average Hours/Day:"
                    << averageHours << endl;
            }

            break;
        }

        case 3:
        {
            cout << "\nWriting Levels\n";
            cout << "Beginner: 1-2 days/week\n";
            cout << "Intermediate: 3-4 days/week\n";
            cout << "Advanced: 5-7 days/week\n";

            break;
        }

        case 4:
        {
            cout << "\nExiting program...\n";
            break;
        }
        }

    } while (menuChoice != 4);

    return 0;
}

// This function changes the console text color.
void changeColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// This function displays the welcome banner.
void displayBanner()
{
    changeColor(11); // Light blue

    cout << "=======================================================" << endl;
    cout << "   Welcome to this Creative Writing Tracking Program   " << endl;
    cout << "=======================================================" << endl;

    changeColor(7); // Default gray
}

// This function displays the user input options menu.
void displayMenu()
{
    changeColor(14); // Yellow

    cout << "\n1. Add Writing Session" << endl;
    cout << "2. View Writing Report" << endl;
    cout << "3. Recommend Writing Level" << endl;
    cout << "4. Quit" << endl;

    changeColor(7); // Default Gray
}

// This function collects and validates string input.
string getValidString(string prompt)
{
    string input;

    do
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty. Please try again.\n";
        }

    } while (input.empty());

    return input;
}

// This function collects and validates integer input.
int getValidInt(string prompt, int min, int max)
{
    int value;

    while (true)
    {
        cout << prompt;

        if (cin >> value && value >= min && value <= max)
        {
            cin.ignore(200, '\n');
            return value;
        }

        cout << "Invalid input. Please enter a value from "
            << min << " to " << max << ".\n";

        cin.clear();
        cin.ignore(200, '\n');
    }
}

// This function collects and validates double input.
double getValidDouble(string prompt, double min, double max)
{
    double value;

    while (true)
    {
        cout << prompt;

        if (cin >> value && value >= min && value <= max)
        {
            return value;
        }

        cout << "Invalid input. Please try again.\n";

        cin.clear();
        cin.ignore(200, '\n');
    }
}

// This function calculates the average hours spent writing.
double calculateAverage(double totalHours, int writingDays)
{
    return totalHours / writingDays;
}

// This function saves the report as a text file named report.txt.
void saveReport(string favoriteBook,
    string favoriteAuthor,
    int writingDays,
    double totalHours,
    double averageHours)
{
    ofstream outFile("report.txt");

    if (!outFile)
    {
        cout << "Error creating report file.\n";
        return;
    }

    outFile << "---------------- CREATIVE WRITING REPORT ----------------\n";

    outFile << left << setw(25) << "Favorite Book:"
        << favoriteBook << endl;

    outFile << left << setw(25) << "Favorite Author:"
        << favoriteAuthor << endl;

    outFile << left << setw(25) << "Writing Days:"
        << writingDays << endl;

    outFile << left << setw(25) << "Total Hours:" << fixed << setprecision(2)
        << totalHours << endl;

    outFile << left << setw(25) << "Average Hours/Day:"
        << averageHours << endl;

    outFile << "----------------------------------------------------------\n";

    outFile.close();

    cout << "\nReport saved as report.txt\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu