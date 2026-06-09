// Week02_Programming_Assignment.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // These are variables that store user input.
    string favoriteAuthorFirstName;
    string favoriteAuthorLastName;
    int favoriteAuthorBooks;
    double favoriteAuthorBookPrice;

    // This is a variable used for a calculation.
    double favoriteAuthorBooksTotalPrice;

    //This is a welcome banner that displays when the user first runs the program.
    cout << "====================================================" << endl;
    cout << "   Welcome to this Program About Creative Writing   " << endl;
    cout << "====================================================" << endl << endl;

    // This prompts the user about who their favorite author is.
    cout << "Who is your favorite author? Please enter their first and last name." << endl;
    cin >> favoriteAuthorFirstName >> favoriteAuthorLastName;

    // This prompts the user about how many books they own published by their favorite author.
    cout << "How many of " << favoriteAuthorFirstName << " " << favoriteAuthorLastName << "'s books do you own?" << endl;
    cin >> favoriteAuthorBooks;

    // This occurs if the user inputs a value less than 0.
    if (cin.fail() || favoriteAuthorBooks < 0)
    {
        cout << "Invalid input for book count. It will be set to 0." << endl;
        cin.clear();
        cin.ignore(200, '\n');
        favoriteAuthorBooks = 0;
    }

    // This prompts the user about how much they are willing to pay for a book published by their favorite author.
    cout << "How much are you willing to pay for one of " << favoriteAuthorFirstName << " " << favoriteAuthorLastName << "'s books?" << endl;
    cin >> favoriteAuthorBookPrice;

    // This occurs if the user inputs a value less than 0.0.
    if (cin.fail() || favoriteAuthorBookPrice < 0)
    {
        cout << "Invalid input for price. It will be set to 0.0." << endl;
        cin.clear();
        cin.ignore(200, '\n');
        favoriteAuthorBookPrice = 0.0;
    }

    // This calculates how much the user is willing to pay for books published by their favorite author.
    favoriteAuthorBooksTotalPrice = favoriteAuthorBooks * favoriteAuthorBookPrice;

    // This displays all the information the user input in a well-formatted summary table.
    cout << endl << "------------------ CREATIVE WRITING REPORT ------------------" << endl;

    cout << left << setw(30) << "Favorite Author:"
        << favoriteAuthorFirstName + " " + favoriteAuthorLastName << endl;

    cout << left << setw(30) << "Books Owned:" << favoriteAuthorBooks << endl;

    cout << left << setw(30) << "Book Price:" << fixed << setprecision(2)
        << favoriteAuthorBookPrice << endl;

    cout << left << setw(30) << "Total Book Collection Value:" << fixed << setprecision(2)
        << favoriteAuthorBooksTotalPrice << endl;

    cout << "-------------------------------------------------------------" << endl;

    // This saves the summary table as a file named report.txt.
    ofstream outFile("report.txt");

    outFile << "------------------ CREATIVE WRITING REPORT ------------------" << endl;

    outFile << left << setw(30) << "Favorite Author:"
        << favoriteAuthorFirstName + " " + favoriteAuthorLastName << endl;

    outFile << left << setw(30) << "Books Owned:" << favoriteAuthorBooks << endl;

    outFile << left << setw(30) << "Book Price:" << fixed << setprecision(2)
        << favoriteAuthorBookPrice << endl;

    outFile << left << setw(30) << "Total Book Collection Value:" << fixed << setprecision(2)
        << favoriteAuthorBooksTotalPrice << endl;

    outFile << "-------------------------------------------------------------" << endl;

    outFile.close();

    cout << endl << "Report saved as report.txt" << endl;

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
