// Week01_Programming_Assignment.cpp

// This program prompts the user for three pieces of information related to creative writing.

#include <iostream>
#include <string>

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

    // This prompts the user about what their favorite book is.
    cout << "What is your favorite book?" << endl;
    getline(cin, favoriteBook);

    // This prompts the user about who their favorite author is.
    cout << "Who is your favorite author? Please enter their first and last name." << endl;
    cin >> favoriteAuthorFirstName >> favoriteAuthorLastName;

    // This prompts the user about how many days a week, on average, they write.
    cout << "How many days do you write, on average, every week? Please only enter an integer between 0 and 7." << endl;
    cin >> writingDays;

    // This calculates how many days the user writes per year.
    yearlyWritingDays = writingDays * 52;

    // This displays all the information the user input.
    cout << "----- Creative Writing Profile -----" << endl;
    cout << "Your favorite book is " 
         << favoriteBook << endl;
    cout << "Your favorite author is " 
         << favoriteAuthorFirstName << " " << favoriteAuthorLastName << endl;
    cout << "You write about " 
         << writingDays << " days every week, which adds up to " << yearlyWritingDays << " days every year" << endl;

    // This combines all of the information the user input into one fun sentence related to creative writing.
    cout << "You're inspired by " << favoriteBook << " to write like " 
         << favoriteAuthorFirstName << " " << favoriteAuthorLastName << " one story at a time!" << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
