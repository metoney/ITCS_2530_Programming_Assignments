// Week01_Programming_Assignment.cpp

//This program prompts the user for three pieces of information related to creative writing.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // These are variables that store user input.
    string favoriteBook;
    string favoriteAuthorFirstName;
    string favoriteAuthorLastName;
    int writingDays;

    // This is a variable used for a simple calculation.
    int yearlyWritingDays;

     //This is a welcome banner that displays when the user first runs the program.
    cout << "====================================================" << endl;
    cout << "   Welcome to this Program About Creative Writing   " << endl;
    cout << "====================================================" << endl << endl;
    
    // This prompts the user about what their favorite book is.
    cout << "What is your favorite book?" << endl;
    getline(cin, favoriteBook);

    // This prompts the user about who their favorite author is.
    cout << "Who is your favorite author? Please enter their first and last name." << endl;
    cin >> favoriteAuthorFirstName >> favoriteAuthorLastName;

    if (!(cin >> favoriteAuthorFirstName >> favoriteAuthorLastName))
    {
        cout << "Invalid input for favorite author. Please enter both their first and last name." << endl;
        cin.clear();
        cin.ignore(200, '\n')

        cin >> favoriteAuthorFirstName >> favoriteAuthorLastName;
    }

    // This prompts the user about how many days a week, on average, they write.
    cout << "How many days do you write, on average, every week? Please enter a number between 0 and 7." << endl;
    cin >> writingDays;

    // This occurs if the user inputs a value less than 0 or greater than 7.
    if (writingDays < 0 || writingDays > 7)
    {
        cout << "Invalid input for writing days. It will be set to 0." << endl;
        cin.clear();
        cin.ignore(200, '\n');
        writingDays = 0;
    }

    // This calculates how many days the user writes per year.
    yearlyWritingDays = writingDays * 52;

    // This displays all the information the user input in a well-formatted summary table.
    cout << "------------------ CREATIVE WRITING REPORT ------------------" << endl;

    cout << left << setw(30) << "Favorite Book:"
         << favoriteBook << endl;

    cout << left << setw(30) << "Favorite Author:"
         << favoriteAuthorFirstName << " " << favoriteAuthorLastName << endl;

    cout << left << setw(30) << "Weekly Writing Days:" << fixed << setprecision(2)
         << writingDays << endl;

    cout << left << setw(30) << "Yearly Writing Days:" << fixed << setprecision(2)
         << yearlyWritingDays << endl;

    cout << "-------------------------------------------------------------" << endl;

    // This saves the summary table as a file named report.txt.
    ofstream outFile("report.txt");

    outFile << "------------------ CREATIVE WRITING REPORT ------------------" << endl;

    outFile << left << setw(30) << "Favorite Book:"
            << favoriteBook << endl;

    outFile << left << setw(30) << "Favorite Author:"
            << favoriteAuthorFirstName << " " << favoriteAuthorLastName << endl;

    outFile << left << setw(30) << "Weekly Writing Days:" << fixed << setprecision(2)
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
