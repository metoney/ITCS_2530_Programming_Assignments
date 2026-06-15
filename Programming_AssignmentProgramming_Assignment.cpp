// Week04_Programming_Assignment.cpp

// This program prompts the user for information related to creative writing.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cassert>

using namespace std;

int main()
{
    // These are variables that allow the user input menu to function properly.
    int menuChoice;

        // This is a do...while loop that allows the user to run the menu repeatedly until they wish to quit.
    do
    {
        cout << "====================================================" << endl;
        cout << "   Welcome to this Program About Creative Writing   " << endl;
        cout << "====================================================" << endl;

        cout << "1. Add Writing Session" << endl;
        cout << "2. View Writing Report" << endl;
        cout << "3. Recommend Writing Level" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter choice: ";

        while (!(cin >> menuChoice))
        {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(200, '\n');
        }

        cin.ignore(200, '\n');

        switch (menuChoice)
        {
        case 1:
        {
            // These are variables that store user input.
            string favoriteBook;
            string favoriteAuthor;
            int writingDays;
            double sessionHours;

            // These are variables used for a simple calculation.
            double totalHours = 0.0;
            double averageHours;

            // This prompts the user about what their favorite book is.
            cout << "What is your favorite book?" << endl;
            getline(cin, favoriteBook);

            // This prompts the user about who their favorite author is.
            cout << "Who is your favorite author? Please enter their first and last name." << endl;
            getline(cin, favoriteAuthor);

            // This prompts the user about how many days a week, on average, they write.
            cout << "How many days did you write this past week? Please enter a number between 1 and 7." << endl;

            while (!(cin >> writingDays) || writingDays < 1 || writingDays > 7)
            {
                cout << "Please enter a value from 1 to 7: ";
                cin.clear();
                cin.ignore(200, '\n');
            }

            // This is a while loop nested in a for loop that runs a fixed number of times depending on writingDays.
            for (int day = 1; day <= writingDays; day++)
            {
                cout << "Hours written on day "
                    << day << ": ";

                while (!(cin >> sessionHours) || sessionHours < 0 || sessionHours > 24)
                {
                    cout << "Please enter a valid number: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                }

                // This expression is equivalent to totalHours = totalHours + sessionHours.
                totalHours += sessionHours;
            }

            // This calculates the average number of hours the user writes based on totalHours and writingDays.
            averageHours = totalHours / writingDays;

            // This compound boolean comments on the user's writing habits based on writingDays and averageHours.
            if (writingDays >= 5 && averageHours >= 2.0)
            {
                cout << "\nYou have a strong writing routine." << endl;
            }
            else
            {
                cout << "\nKeep building your writing habit." << endl;
            }

            // This compound boolean also comments on the user's writing habits based on writingDays and averageHours.
            if (writingDays >= 3 && totalHours >= 10)
            {
                cout << "You are showing excellent commitment." << endl;
            }
            else
            {
                cout << "Try increasing your weekly writing time." << endl;
            }

            // This displays all the information the user input in a well-formatted summary table.
            cout << "\n------------------ CREATIVE WRITING REPORT ------------------" << endl;

            cout << left << setw(30) << "Favorite Book:"
                << favoriteBook << endl;

            cout << left << setw(30) << "Favorite Author:"
                << favoriteAuthor << endl;

            cout << left << setw(30) << "Writing Days:"
                << writingDays << endl;

            cout << left << setw(30) << "Total Hours:" << fixed << setprecision(2)
                << totalHours << endl;

            cout << left << setw(30) << "Average Hours/Day:"
                << averageHours << endl;

            cout << "-------------------------------------------------------------" << endl;

            // This saves the summary table as a file named report.txt.
            ofstream outFile("report.txt");

            if (outFile)
            {
                outFile << "------------------ CREATIVE WRITING REPORT ------------------" << endl;

                outFile << left << setw(30) << "Favorite Book:"
                    << favoriteBook << endl;

                outFile << left << setw(30) << "Favorite Author:"
                    << favoriteAuthor << endl;

                outFile << left << setw(30) << "Writing Days:"
                    << writingDays << endl;

                outFile << left << setw(30) << "Total Hours:" << fixed << setprecision(2)
                    << totalHours << endl;

                outFile << left << setw(30) << "Average Hours/Day:"
                    << averageHours << endl;

                outFile << "-------------------------------------------------------------" << endl;


                outFile.close();

                cout << endl << "Report saved as report.txt" << endl;
            }

            break;
        }

        case 2:
            cout << "\nView Writing Report selected." << endl;
            break;

        case 3:
            cout << "\nWriting Levels" << endl;
            cout << "Beginner: 1-2 days/week" << endl;
            cout << "Intermediate: 3-4 days/week" << endl;
            cout << "Advanced: 5-7 days/week" << endl;
            break;

        case 4:
            cout << "\nExiting program..." << endl;
            break;

        default:
            cout << "\nInvalid menu option." << endl;
        }

    } while (menuChoice != 4);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
