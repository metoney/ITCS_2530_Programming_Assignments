// Andrew Kuyda
// ITCS 2530
// Prof. Koss
// 6/28/2026

// This program prompts the user for information related to creative writing.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

//Added Enum to represent the mood of each writing day
enum dailyMood { WRITERS_BLOCK, NORMAL_PROGRESS, CREATIVE_FLOWSTATE };

//***WEEK 07 - ADDED struct to store writing session data
struct WritingSession
{
    string date;
    double hoursWritten;
    dailyMood mood;
};

// This defines the various function prototypes.
void changeColor(int color);
void displayBanner();
void displayMenu();

string getValidString(string prompt);
int getValidInt(string prompt, int min, int max);
double getValidDouble(string prompt, double min, double max);

double calculateAverage(double totalHours, int writingDays);
void saveReport(string favoriteBook, string favoriteAuthor, int writingDays, double totalHours, double averageHours);

//Added Prototypes for mood input and mood report functions
void getMoodCounts(int moodCounts[], int size);
void displayMoodReport(const int moodCounts[], int size);

//**WEEK 07 - ADDED: Prototypes in the same style as original author
void addSession(WritingSession& session, string sessionDate, double hours);
void summarizeSessions(const WritingSession sessions[], int numDays);

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

    //Added Array to store how many days the user felt each mood
    const int MOOD_COUNT = 3;
    int moodCounts[MOOD_COUNT] = { 0, 0, 0 };

    //*** WEEK 07 - ADDED: Array to store weekly sessions
    const int MAX_DAYS = 7;
    WritingSession weekSessions[MAX_DAYS];

    // This is a do...while loop that allows the user to run the menu repeatedly until they wish to quit.
    do
    {
        // This calls the displayBanner and displayMenu functions.
        displayBanner();
        displayMenu();

        //Added Updated max menu choice from 4 to 5 to account for new mood report option
        menuChoice = getValidInt("Enter choice: ", 1, 5);

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

                //***WEEK 07 - Added: 
                addSession(weekSessions[day - 1], "Day " + to_string(day), sessionHours);
            }

            //Added Ask user to fill input their mood counts for the week
            getMoodCounts(moodCounts, MOOD_COUNT);

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

            //***WEEK 07 - ADDED: 
            summarizeSessions(weekSessions, writingDays);

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

        //Added Display for mood report
        case 4:
        {
            displayMoodReport(moodCounts, MOOD_COUNT);
            break;
        }

        //Added Quit moved from case 4 to case 5
        case 5:
        {
            cout << "\nExiting program...\n";
            break;
        }
        }

        //Added Changed exit condition from 4 to 5
    } while (menuChoice != 5);

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

    //Added New menu option to view mood report
    cout << "4. View Mood Report" << endl;
    cout << "5. Quit" << endl;

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

//Added Function to prompt user for how many days they felt each mood
void getMoodCounts(int moodCounts[], int size)
{
    cout << endl << "Let's track how you felt during your writing sessions this week!" << endl;
    cout << "For each type of mood below, enter how many days you felt that way (0-7):" << endl << endl;

    for (int i = 0; i < size; i++)
    {
        dailyMood mood = static_cast<dailyMood>(i);

        if (mood == WRITERS_BLOCK)
            moodCounts[i] = getValidInt("Days you experienced Writer's Block: ", 0, 7);
        else if (mood == NORMAL_PROGRESS)
            moodCounts[i] = getValidInt("Days of Normal Progress: ", 0, 7);
        else if (mood == CREATIVE_FLOWSTATE)
            moodCounts[i] = getValidInt("Days you were in a Creative Flowstate: ", 0, 7);

        cout << endl;
    }
}

//Added Function to display the mood report and determine the most common mood
void displayMoodReport(const int moodCounts[], int size)
{
    changeColor(11); // Cyan

    cout << endl << "------------- MOOD REPORT -------------" << endl;

    changeColor(7); // Default Gray

    cout << left << setw(25) << "Writer's Block:" << moodCounts[WRITERS_BLOCK] << " days" << endl;
    cout << left << setw(25) << "Normal Progress:" << moodCounts[NORMAL_PROGRESS] << " days" << endl;
    cout << left << setw(25) << "Creative Flowstate:" << moodCounts[CREATIVE_FLOWSTATE] << " days" << endl;

    //Added Loop through array to find the most common mood
    int highest = 0;
    dailyMood commonMood = WRITERS_BLOCK;

    for (int i = 0; i < size; i++)
    {
        if (moodCounts[i] > highest)
        {
            highest = moodCounts[i];
            commonMood = static_cast<dailyMood>(i);
        }
    }

    changeColor(10); // Green

    cout << endl << "Your most common mood this week was: ";

    switch (commonMood)
    {
    case WRITERS_BLOCK:
        cout << "Writer's Block!" << endl;
        cout << "Don't worry, writer's block happens to everyone!" << endl;
        break;
    case NORMAL_PROGRESS:
        cout << "Normal Progress!" << endl;
        cout << "Great job getting some writing done!" << endl;
        break;
    case CREATIVE_FLOWSTATE:
        cout << "Creative Flowstate!" << endl;
        cout << "AWESOME! You got a lot written this week!" << endl;
        break;
    }

    changeColor(7); // Default Gray

    cout << "---------------------------------------" << endl;
}

//***WEEK 07 - ADDED: Function to add values to Writing Session Struct
void addSession(WritingSession& session, string sessionDate, double hours)
{
    session.date = sessionDate;
    session.hoursWritten = hours;

    if (hours < 1.0)
        session.mood = WRITERS_BLOCK;
    else if (hours < 3.0)
        session.mood = NORMAL_PROGRESS;
    else
        session.mood = CREATIVE_FLOWSTATE;
}

//***WEEK 07 - ADDED: Function to output session info and averages
void summarizeSessions(const WritingSession sessions[], int numDays)
{
    double total = 0.0;

    cout << "\n----------- DAILY SESSION BREAKDOWN -----------\n";
    cout << left << setw(10) << "Day" << setw(12) << "Hours" << "Mood" << endl;

    for (int i = 0; i < numDays; i++)
    {
        total += sessions[i].hoursWritten;

        cout << left << setw(10) << sessions[i].date
            << setw(12) << fixed << setprecision(2) << sessions[i].hoursWritten;

        switch (sessions[i].mood)
        {
        case WRITERS_BLOCK:      cout << "Writer's Block"; break;
        case NORMAL_PROGRESS:    cout << "Normal Progress"; break;
        case CREATIVE_FLOWSTATE: cout << "Creative Flowstate"; break;
        }
        cout << endl;
    }

    cout << "Average hours per day: " << fixed << setprecision(2)
        << (total / numDays) << " hrs/day\n";
    cout << "------------------------------------------------\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu