// Week03_Programming_Assignment.cpp

// This program prompts the user for information related to creative writing.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cassert>

using namespace std;

int main()
{
    // These are variables that store user input.
    string favoriteBook;
    string favoriteAuthor;
    int writingDays;

    // This is a variable used for a simple calculation.
    double yearlyWritingDays;

    //This is a welcome banner that displays when the user first runs the program.
    cout << "====================================================" << endl;
    cout << "   Welcome to this Program About Creative Writing   " << endl;
    cout << "====================================================" << endl << endl;

    // This prompts the user about what their favorite book is.
    cout << "What is your favorite book?" << endl;
    getline(cin, favoriteBook);

    // This prompts the user about who their favorite author is.
    cout << "Who is your favorite author? Please enter their first and last name." << endl;
    getline(cin, favoriteAuthor);

    // This prompts the user about how many days a week, on average, they write.
    cout << "How many days do you write, on average, every week? Please enter a number between 0 and 7." << endl;

    if (!(cin >> writingDays))
    {
        cout << "Invalid input for writing days. It will be set to 0." << endl;
        cin.clear();
        cin.ignore(200, '\n');
        writingDays = 0;
    }
    else if (writingDays < 0 || writingDays > 7)
    {
        cout << "Writing days must be between 0 and 7. It will be set to 0." << endl;
        writingDays = 0;
    }

    // This comments on the user's writing habits based on how many days they write every week.
    switch (writingDays)
    {
    case 1:
        cout << "You write occasionally. Developing a regular schedule may help strengthen your writing habits." << endl;
        break;

    case 2:
    case 3:
    case 4:
        cout << "You maintain a moderate writing routine and show a good level of commitment." << endl;
        break;

    case 5:
    case 6:
    case 7:
        cout << "You are highly dedicated to writing and maintain a strong writing schedule." << endl;
        break;

    default:
        cout << "You currently write very little, but every writer starts somewhere." << endl;
    }

    // This calculates how many days the user writes per year.
    yearlyWritingDays = writingDays * 52.1429;

    // This comments on the user's yearly writing habits based on how many days they write every week.
    if (yearlyWritingDays >= 0 && yearlyWritingDays <= 121.6667)
    {
        cout << "Based on your weekly writing habits, you spend less than one-third of the year writing." << endl;
    }
    else if (yearlyWritingDays >= 121.6667 && yearlyWritingDays <= 243.3333)
    {
        cout << "Based on your weekly writing habits, you spend between one-third and two-thirds of the year writing." << endl;
    }
    else
        cout << "Based on your weekly writing habits, you spend more than two-thirds of the year writing." << endl;

    // This displays all the information the user input in a well-formatted summary table.
    cout << "------------------ CREATIVE WRITING REPORT ------------------" << endl;

    cout << left << setw(30) << "Favorite Book:"
        << favoriteBook << endl;

    cout << left << setw(30) << "Favorite Author:"
        << favoriteAuthor << endl;

    cout << left << setw(30) << "Weekly Writing Days:"
        << writingDays << endl;

    cout << left << setw(30) << "Yearly Writing Days:" << fixed << setprecision(2)
        << yearlyWritingDays << endl;

    cout << "-------------------------------------------------------------" << endl;

    // This terminates the program if the output file does not open.
    ofstream outFile("report.txt");

    if (!outFile)
    {
        cout << "Cannot open the output file."
            << "The program terminates." << endl;
        return 1;
    }

    // This saves the summary table as a file named report.txt.
    outFile << "------------------ CREATIVE WRITING REPORT ------------------" << endl;

    outFile << left << setw(30) << "Favorite Book:"
        << favoriteBook << endl;

    outFile << left << setw(30) << "Favorite Author:"
        << favoriteAuthor << endl;

    outFile << left << setw(30) << "Weekly Writing Days:"
        << writingDays << endl;

    outFile << left << setw(30) << "Yearly Writing Days:" << fixed << setprecision(2)
        << yearlyWritingDays << endl;

    outFile << "-------------------------------------------------------------" << endl;

    outFile.close();

    cout << endl << "Report saved as report.txt" << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
