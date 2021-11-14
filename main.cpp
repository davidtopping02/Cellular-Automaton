#include <iostream>
#include "cellularAutomaton.h"
using namespace std;
#include <string>

int main()
{
    //initialise local variables/objects
    RulesSet theRules;
    int choice;

    //looping till exit
    while (choice != 4)
    {
        //menu option
        cout << "1. Run Automaton (chosing your own rule)" << endl;
        cout << "2. Load saved file" << endl;
        cout << "3. Game of life " << endl;
        cout << "4. Exit " << endl;
        cout << "Option: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            runAutomaton(theRules);
            break;
        case 2:
            cout << "Choice 2" << endl;
            break;
        case 3:
            cout << "Choice 3" << endl;
            break;
        case 4:
            cout << "Choice 4" << endl;
            break;
        case 5:
            cout << "Exiting Program" << endl;
            break;
        default:
            cout << "Invalid input\n"
                 << endl;
        }
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
void runAutomaton(RulesSet theRules)
{
    //initialise local variables/objects
    int userRule;
    int iterations = 0;

    //getting user's rule

    while (userRule < 0 || userRule > 255)
    {

        cout << "\nSelect Rule (0-255)" << endl;
        cout << "Rule: ";
        cin >> userRule;

        if (!userRule)
        {
            cout << "\nERROR- invalid input\n"
                 << endl;
        }
        else
        {
            // //setting the rules to the user's option
            theRules.setRulesFromBinary(toBinary(userRule));

            //running the automaton
            cellularAutomaton(theRules, 40);
        }
    }
}