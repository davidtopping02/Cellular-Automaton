/**
 * @file main.cpp
 * @author David Topping, Caleb Harmon, Heather Currie
 * @brief Main file from which the menu of the cellular automaton is run
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 **/

//includes required for this file
#include <iostream>
#include "cellularAutomaton.h"
using namespace std;
#include <string>

int main()
{
    cout << "This is a cellular automaton programmed by David Topping, Caleb Harmon, Heather Currie" << endl;
    cout << "Everytime you run a cellular automaton the result will be saved to a file in the source folder\n"
         << endl;

    //initialise local variables/objects
    RulesSet theRules;
    int choice;

    //looping till exit
    while (choice != 4)
    {
        //menu option
        cout << "1. Run Cellular Automaton (chosing your own rule, number of generations and starting point)" << endl;
        cout << "2. Run random Cellular Automaton rule for 40 generations" << endl;
        cout << "3. Load from File" << endl;
        cout << "4. Exit " << endl;
        cout << "Option: ";

        //getting user input and selecting correct choice
        cin >> choice;

        switch (choice)
        {
        case 1:
            runAutomatonUserInput(theRules);
            cout << "" << endl;
            break;
        case 2:
            randomAutomaton(theRules);
            cout << "" << endl;
            break;
        case 3:
            cout << "Choice 3" << endl;
            cout << "" << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            abort();
            break;
        default:
            cout << "Invalid input\n"
                 << endl;
            cout << "" << endl;
        }
        //clearing cin
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return 0;
}

/**
 * @brief runs the cellular automaton with user options
 *
 * @param theRules
 */
void runAutomatonUserInput(RulesSet theRules)
{
    //initialise local variables/objects
    int userRule;
    int iterations;
    int startingPoint;

    //getting user's rule and number of iterations
    while ((userRule < 0 || userRule > 255) && iterations > 1 && startingPoint < 0 || startingPoint > 81)
    {
        //rule
        cout << "\nSelect Rule (0-255)" << endl;
        cout << "Rule: ";
        cin >> userRule;

        if (!cin)
        {
            cout << "Bad value! Press enter to continue\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        //generations
        cout << "\nSelect Number of generations (40 is recommended)" << endl;
        cout << "Generations: ";
        cin >> iterations;

        if (!cin)
        {
            cout << "Bad value! Press enter to continue\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        //starting point
        cout << "\nSelect the starting point of the cellular automation (between 0 and 81 - 41 is the middle)" << endl;
        cout << "Starting Point: ";
        cin >> startingPoint;

        if (!cin)
        {
            cout << "Bad value! Press enter to continue\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        theRules.setRulesFromBinary(toBinary(userRule));

        //running the automaton
        cellularAutomaton(theRules, iterations, startingPoint);
    }
}

/**
 * @brief runs the cellular automaton on a random rule for 40 generations
 * 
 * @param theRules 
 */
void randomAutomaton(RulesSet theRules)
{
    srand(time(0));
    int randomNum = ((rand() % 255) + 1);

    cout
        << "Running rule '" << randomNum << "'\n"
        << endl;

    //setting the rules to the user's option
    theRules.setRulesFromBinary(toBinary(randomNum));

    //running the automaton
    cellularAutomaton(theRules, 40, 41);
}