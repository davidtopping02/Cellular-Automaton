#include <iostream>
#include "cellularAutomaton.h"
using namespace std;
#include <string>

int main()
{
    int choice = 0;

    while (choice != 4) {
        cout << "\nSelect an option: [1] Run sample Automaton [2] Automaton using user inputs [3] 2D Cellular Automata [4] Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                sampleAutomaton();
                break;
            case 2:
                automatonOptions();
                break;
            case 3:
                cout << "Run 2D simulation" << endl;
                break;
            case 4:
                cout << "Exiting Program" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
        cin.clear();
        cin.ignore();
    }
    return 0;
}

void sampleAutomaton() {
    emptyFile();
    //creating new rule set and setting it to rule 30
    RulesSet theRules;
    theRules.setRulesFromBinary(toBinary(30));

    //creating a sample current line and initialising all values to 0
    int lineArray[81];

    for (int i = 0; i < 81; i++)
    {
        lineArray[i] = 0;
    }

    //setting middle array elemenet to 1
    lineArray[41] = 1;

    newLine(theRules, lineArray, 40);
}

void automatonOptions() {
    //creating new rule set and setting it to users choice of rule
    RulesSet theRules;
    int rule;
    int width;
    int iterations;
    emptyFile();

    cout << "\nEnter number for which rule you would like to use" << endl;
    cin >> rule;
    theRules.setRulesFromBinary(toBinary(rule));

    //creating a current line and initialising all values to 0
    /*
    cout << "\nHow wide would you like to make it?" << endl;
    cin >> width;
    int lineArray[width];

    for (int i = 0; i < width; i++)
    {
        lineArray[i] = 0;
    }

    //setting middle array element to 1
    lineArray[width/2] = 1;
    */

    int lineArray[81];

    for (int i = 0; i < 81; i++)
    {
        lineArray[i] = 0;
    }

    //setting middle array elemenet to 1
    lineArray[41] = 1;

    cout << "\nHow many lines should it run for?" << endl;
    cin >> iterations;

    newLine(theRules, lineArray, iterations);
}

void emptyFile() {
    //emptying the file
    std::ofstream ofs;
    ofs.open("cellularAutomaton.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}