// Andrew Kuyda
// ITCS 2530
// Prof. Koss
// 7/10/2026

// This program prompts the user for information related to creative writing.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

//Added Enum to represent the mood of each writing day
enum dailyMood { WRITERS_BLOCK, NORMAL_PROGRESS, CREATIVE_FLOWSTATE };

//Added struct to store writing session data
struct WritingSession
{
    string date;
    double hoursWritten;
    dailyMood mood;
};

//***WEEK 08 - ADDED: class for WritingTracker code
class WritingTracker
{
private:
    WritingSession sessions[7];
    int writingDays;
    double totalHours;
    string favoriteBook;
    string favoriteAuthor;
    int sessionsRecorded;  

public:
    WritingTracker(); 

    void setFavorites(string book, string author);
    int askWritingDays();
    void addSession();
    void showReport() const;
    void saveReportToFile(const string& filename) const;
    double computeAverageDuration() const;
    int getWritingDays() const;
    double getTotalHours() const;
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

//Added Prototypes in the same style as original author
void addSession(WritingSession& session, string sessionDate, double hours);
void summarizeSessions(const WritingSession sessions[], int numDays);


//***WEEK 08 - REPLACED old variables that tracked all data now in WritingTracker class
int main()
{
    int menuChoice;
    WritingTracker tracker;

    //Added Array to store how many days the user felt each mood
    const int MOOD_COUNT = 3;
    int moodCounts[MOOD_COUNT] = { 0, 0, 0 };

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
        //*** WEEK 08 - REPLACED entirety of case1 with new code integrated into class instead of containing variables itself
        case 1:
        {
            string book = getValidString("What is your favorite book? ");
            string author = getValidString("Who is your favorite author? ");
            tracker.setFavorites(book, author);

            int days = tracker.askWritingDays();

            // This is a for loop that runs a fixed number of times depending on writing days
            for (int day = 1; day <= days; day++)
            {
                tracker.addSession();
            }

            //Added Ask user to fill input their mood counts for the week
            getMoodCounts(moodCounts, MOOD_COUNT);

            changeColor(10);

            //Comments for writing routine based on average days
            if (tracker.getWritingDays() >= 5 && tracker.computeAverageDuration() >= 2.0)
            {
                cout << "\nYou have a strong writing routine.\n";
            }
            else
            {
                cout << "\nKeep building your writing habit.\n";
            }

            //Comments on writing motivation based on amount written
            if (tracker.getWritingDays() >= 3 && tracker.getTotalHours() >= 10.0)
            {
                cout << "You are showing excellent commitment.\n";
            }
            else
            {
                cout << "Try increasing your weekly writing time.\n";
            }

            changeColor(7); 

            tracker.showReport();
            tracker.saveReportToFile("report.txt");

            break;
        }

        //***WEEK 08 - REPLACED entire case with a refference to one function inside WritingTracker class
        case 2:
        {
            tracker.showReport();
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

//***WEEK 08 - ADDED a constructor for writing tracker that initializes all functions to 0 or an empty string
WritingTracker::WritingTracker()
{
    writingDays = 0;
    totalHours = 0.0;
    favoriteBook = "";
    favoriteAuthor = "";
    sessionsRecorded = 0;
}


void WritingTracker::setFavorites(string book, string author)
{
    favoriteBook = book;
    favoriteAuthor = author;
}


int WritingTracker::askWritingDays()
{
    writingDays = getValidInt("How many days did you write this week? Please enter a number between 1 and 7. ", 1, 7);
    return writingDays;
}


void WritingTracker::addSession()
{
    double hours = getValidDouble("Hours written on day " + to_string(sessionsRecorded + 1) + ": ", 0.0, 24.0);

    sessions[sessionsRecorded].date = "Day " + to_string(sessionsRecorded + 1);
    sessions[sessionsRecorded].hoursWritten = hours;

    if (hours < 1.0)
        sessions[sessionsRecorded].mood = WRITERS_BLOCK;
    else if (hours < 3.0)
        sessions[sessionsRecorded].mood = NORMAL_PROGRESS;
    else
        sessions[sessionsRecorded].mood = CREATIVE_FLOWSTATE;

    totalHours += hours;
    sessionsRecorded++;
}


double WritingTracker::computeAverageDuration() const
{
    return totalHours / writingDays;
}


int WritingTracker::getWritingDays() const
{
    return writingDays;
}


double WritingTracker::getTotalHours() const
{
    return totalHours;
}


void WritingTracker::showReport() const
{
    if (writingDays == 0)
    {
        cout << "No writing session has been entered yet.\n";
        return;
    }

    cout << "\n------------- CREATIVE WRITING REPORT -------------\n";
    cout << left << setw(25) << "Favorite Book:" << favoriteBook << endl;
    cout << left << setw(25) << "Favorite Author:" << favoriteAuthor << endl;
    cout << left << setw(25) << "Writing Days:" << writingDays << endl;
    cout << left << setw(25) << "Total Hours:" << fixed << setprecision(2) << totalHours << endl;
    cout << left << setw(25) << "Average Hours/Day:" << computeAverageDuration() << endl;
    cout << "---------------------------------------------------\n";

    cout << "\n----------- DAILY SESSION BREAKDOWN -----------\n";
    cout << left << setw(10) << "Day" << setw(12) << "Hours" << "Mood" << endl;

    for (int i = 0; i < writingDays; i++)
    {
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
    cout << "------------------------------------------------\n";
}


void WritingTracker::saveReportToFile(const string& filename) const
{
    ofstream outFile(filename);

    if (!outFile)
    {
        cout << "Error creating report file.\n";
        return;
    }

    outFile << "---------------- CREATIVE WRITING REPORT ----------------\n";
    outFile << left << setw(25) << "Favorite Book:" << favoriteBook << endl;
    outFile << left << setw(25) << "Favorite Author:" << favoriteAuthor << endl;
    outFile << left << setw(25) << "Writing Days:" << writingDays << endl;
    outFile << left << setw(25) << "Total Hours:" << fixed << setprecision(2) << totalHours << endl;
    outFile << left << setw(25) << "Average Hours/Day:" << computeAverageDuration() << endl;
    outFile << "----------------------------------------------------------\n";

    outFile.close();
    cout << "\nReport saved as " << filename << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu