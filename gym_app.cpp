#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <limits>

using namespace std;

// Input request variables
string athleteName;
int trainingPlan;
float weight;
int category;
int competitions;
int privateLessons;
char correct;

// Calculation variables
float costOfSessions;
float costCompetitions;
float privateLessonCost;
float totalCost;

// Function to get and validate 'y' or 'n' input
char getValidatedChar() {
    char input;
    while (true) {
        cin >> input;
        input = tolower(input);
        if (input == 'y' || input == 'n') {
            break;
        }
        else {
            cout << "Invalid input. Please type 'y' to proceed or 'n' to start again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

// Improved data input function
void dataInput() {
    cout << "Hi, athlete!  \nTo calculate your training fees per month, please input the following: \n\nYour name: \n";

    while (true) {
        getline(cin, athleteName);

        // Check if the name contains only letters, dashes, or spaces
        if (athleteName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-^ ") == string::npos) {
            break;
        }
        else {
            cout << "Invalid input. Your name should contain only letters, dash '-', and caret '^'. Please re-enter your name: ";
        }
    }

    // Input a training plan:
    cout << "\nType the number of your training plan: \n1 - Beginner \n2 - Intermediate\n3 - Elite:\n";
    while (!(cin >> trainingPlan) || (trainingPlan < 1 || trainingPlan > 3)) {
        cout << "Invalid input. Please input a number from 1 to 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Input weight
    cout << "Your current weight in kg: ";
    while (!(cin >> weight) || weight <= 15 || weight > 362) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid weight between 15 and 362 kg: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Input competition weight category
void inputCompetitionCategory() {
    cout << "\n";
    while (true) {
        cout << "Type the number (1 - 6) of your competition weight category: \n"
            << "--------------------------------------\n"
            << "Number \t Category name \t Upper Weight Limit\n"
            << "--------------------------------------\n"
            << "1 -  \t Heavyweight    \t Unlimited (Over 100)\n"
            << "2 -  \t Light-Heavyweight   \t 100\n"
            << "3 - \t Middleweight       \t 90\n"
            << "4 - \t Light-Middleweight \t 81\n"
            << "5 -  \t Lightweight        \t 73\n"
            << "6 -  \t Flyweight            \t 66\n";

        if (cin >> category && category >= 1 && category <= 6) {
            break;
        }
        else {
            cout << "Invalid weight category. Please enter a number between 1 and 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Input competition numbers
void getCompetitionInput() {
    cout << "\n";
    if (trainingPlan > 1 && trainingPlan <= 3) {
        cout << "Please type 1 if you entered a competition this month:  ";
    }
    while (true) {
        if (cin >> competitions && competitions >= 0 && competitions <= 1) {
            break;
        }
        else {
            cout << "Invalid input. Please enter 0 or 1.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Input the number of private lessons
void privateLessonsInput() {
    cout << "\n";
    cout << "If you had private lessons, type how many (1 to 20): ";

    while (true) {
        if (cin >> privateLessons && privateLessons >= 1 && privateLessons <= 20) {
            break;
        }
        else {
            cout << "Invalid input. Please input a number from 1 to 20: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Check data function
void yourInfo() {
    cout << "\n Check your data: \n";
    cout << "1. Name: " << athleteName << endl;
    cout << "2. Training plan: " << trainingPlan << endl;
    cout << "3. Weight: " << weight << endl;
    cout << "4. Category: " << category << endl;
    cout << "5. Competitions entered: " << competitions << endl;
    cout << "6. Number of private lessons: " << privateLessons << endl;
    cout << "\n If everything is correct, type 'y' to see the cost of the training. Type 'n' to start again: ";
    correct = getValidatedChar();

    // Starting the input again if the athlete chose "n"
    while (correct == 'n') {
        dataInput();
        inputCompetitionCategory();
        getCompetitionInput();
        privateLessonsInput();
        cout << "\n Check your data: \n";
        cout << "1. Name: " << athleteName << endl;
        cout << "2. Training plan: " << trainingPlan << endl;
        cout << "3. Weight: " << weight << endl;
        cout << "4. Category: " << category << endl;
        cout << "5. Competitions entered: " << competitions << endl;
        cout << "6. Number of private lessons: " << privateLessons << endl;
        cout << "\n If everything is correct, type 'y' to see the cost of the training. Type 'n' to start again: ";
        correct = getValidatedChar();
    }
}

// Outputting the cost of training sessions function
void costSessions() {
    if (trainingPlan == 1) {
        costOfSessions = 100;
    }
    else if (trainingPlan == 2) {
        costOfSessions = 200;
    }
    else if (trainingPlan == 3) {
        costOfSessions = 300;
    }
    cout << "\nYour training plan will cost you $" << costOfSessions << " per month.\n";
}

// Calculating competition costs
void costCompetitionsFunc() {
    if (competitions == 1) {
        costCompetitions = 50; // Example cost for entering competitions
        cout << "Cost for competitions: $" << costCompetitions << "\n";
    }
    else {
        costCompetitions = 0;
        cout << "No competitions entered.\n";
    }
}

// Calculating private lesson costs
void costPrivateLessons() {
    privateLessonCost = privateLessons * 25; // Assuming $25 per private lesson
    cout << "Cost for private lessons: $" << privateLessonCost << "\n";
}

// Weight comparison function
void weightComparison(double weight, int category) {
    if (weight <= 66 && category == 6) {
        cout << "You are competing within your weight category";
    }
    else if (weight <= 66 && category < 6) {
        cout << "Your current weight is less than required for this category. Please consider competing in the lighter category.";
    }
    else if (weight > 66 && weight <= 73 && category == 5) {
        cout << "You are competing within your weight category";
    }
    else if (weight > 66 && weight <= 73 && category > 5) {
        cout << "Your current weight exceeds the maximum weight for this category. Please consider competing in the heavier category.";
    }
    else if (weight > 66 && weight <= 73 && category < 5) {
        cout << "Your current weight is less than required for this category. Please consider competing in the lighter category.";
    }
    else if (weight > 73 && weight <= 81 && category == 4) {
        cout << "You are competing within your weight category";
    }
    else if (weight > 73 && weight <= 81 && category > 4) {
        cout << "Your current weight exceeds the maximum weight for this category. Please consider competing in the heavier category.";
    }
    else if (weight > 73 && weight <= 81 && category < 4) {
        cout << "Your current weight is less than required for this category. Please consider competing in the lighter category.";
    }
    else if (weight > 81 && weight <= 90 && category == 3) {
        cout << "You are competing within your weight category";
    }
    else if (weight > 81 && weight <= 90 && category > 3) {
        cout << "Your current weight exceeds the maximum weight for this category. Please consider competing in the heavier category.";
    }
    else if (weight > 81 && weight <= 90 && category < 3) {
        cout << "Your current weight is less than required for this category. Please consider competing in the lighter category.";
    }
    else if (weight > 90 && weight <= 100 && category == 2) {
        cout << "You are competing within your weight category";
    }
    else if (weight > 90 && weight <= 100 && category > 2) {
        cout << "Your current weight exceeds the maximum weight for this category. Please consider competing in the heavier category.";
    }
    else if (weight > 90 && weight <= 100 && category < 2) {
        cout << "Your current weight is less than required for this category. Please consider competing in the lighter category.";
    }
    else if (weight > 100 && category == 1) {
        cout << "You are competing within your weight category";
    }
    else if (weight > 100 && category < 1) {
        cout << "Your current weight is less than required for this category. Please consider competing in the lighter category.";
    }
}


// Total cost calculation
void totalCostCalculation() {
    totalCost = costOfSessions + costCompetitions + privateLessonCost;
    cout << "\nTotal cost this month: $" << totalCost << "\n\n======================================= \n";
}

// Main function
int main() {
    dataInput();
    inputCompetitionCategory();
    getCompetitionInput();
    privateLessonsInput();
    yourInfo();
    costSessions();
    costCompetitionsFunc();
    costPrivateLessons();
    totalCostCalculation();
    weightComparison(weight, category);
    return 0;
}