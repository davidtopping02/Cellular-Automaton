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
    string file;

    //looping till exit
    while (choice != 4)
    {
        //menu option
        cout << "1. Run Cellular Automaton (chosing your own rule, number of generations, automaton width and starting point)" << endl;
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
            cout << "Enter file name to read in: (recommend cellularAutomaton.txt) ";
            cin >> file;
            readFile(file);
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
    int userRule = -1;
    int iterations = -1;
    int cellWidth = -1;
    int startingPoint = -2;
    emptyFile();

    //getting user's rule and number of iterations
    while ((userRule < 0 || userRule > 255) && (iterations < 1) && (startingPoint < 0 || startingPoint > 81) && (cellWidth < 1 || cellWidth > 200))
    {
        //rule
        cout << "\nSelect Rule (0-255)" << endl;
        cout << "Rule: ";
        cin >> userRule;

        if (!cin || userRule > 255 || userRule < 1)
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

        if (!cin || iterations < 1)
        {
            cout << "Bad value! Press enter to continue\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        //setting the width
        cout << "\nSet the width of the automaton (1-200)" << endl;
        cout << "Width: ";
        cin >> cellWidth;

        if (!cin || cellWidth < 1 || cellWidth > 200)
        {
            cout << "Bad value! Press enter to continue\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        //starting point(s)

        //creating a sample current line and initialising all values to 0
        int firstLine[cellWidth];

        for (int i = 0; i < cellWidth; i++)
        {
            firstLine[i] = 0;
        }

        while (startingPoint != -1)
        {

            cout << "\nEnter the positions you would like to turn on (between 0 and " << cellWidth << " - " << cellWidth / 2 << " is the middle)" << endl;
            cout << "Enter '-1' to run automaton\n"
                 << endl;
            cout << "Position: ";
            cin >> startingPoint;

            if (startingPoint < -1 || startingPoint > cellWidth)
            {
                cout << "\nEnter a valid number\n"
                     << endl;
            }
            else
            {
                if (startingPoint != -1)
                {
                    firstLine[startingPoint] = 1;
                }

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (!cin)
        {
            cout << "Bad value! Press enter to continue\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        //setting the rules
        theRules.setRulesFromBinary(toBinary(userRule));

        //running the automaton
        cellularAutomaton(theRules, iterations, firstLine, cellWidth);
    }
}

/**
 * @brief runs the cellular automaton on a random rule for 40 generations
 * 
 * @param theRules 
 */
void randomAutomaton(RulesSet theRules)
{

    emptyFile();
    srand(time(0));
    int randomNum = ((rand() % 255) + 1);

    //setting up the firstLine
    int firstLine[81];

    for (int i = 0; i < 81; i++)
    {
        firstLine[i] = 0;
    }

    firstLine[41] = 1;

    cout
        << "\nRunning rule '" << randomNum << "'\n"
        << endl;

    //setting the rules to the user's option
    theRules.setRulesFromBinary(toBinary(randomNum));

    //running the automaton
    cellularAutomaton(theRules, 40, firstLine, 81);
}

/**
 * @brief empties the file
 */
void emptyFile()
{
    std::ofstream ofs;
    ofs.open("cellularAutomaton.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}