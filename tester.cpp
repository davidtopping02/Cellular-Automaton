#include "cellularAutomaton.h"
#include <iostream>
#include <bitset>
#include <cstring>
#include <bits/stdc++.h>
// #include "display.cpp"

using namespace std;

int main()
{

    //creating new rule set and setting it to rule 30
    RulesSet theRules;
    theRules.setRulesFromBinary("00011110");

    //creating a sample current line and initialising all values to 0
    int lineArray[41];

    for (int i = 0; i < 41; i++)
    {
        lineArray[i] = 0;
    }

    //setting middle array elemenet to 1
    lineArray[21] = 1;

    newLine(theRules, lineArray, 40);
    //getting a pointer to the next line after processing
    // for (int i = 0; i <20; i++){
    //     int *newLine = nextLine(theRules, lineArray);
    //     display(newLine);
    // }
    

    


    //printing the next line
    // for (int i = 0; i < 41; i++)
    // {
    //     cout << newLine[i];
    // }

    // cout << endl
    //      << "DONE" << endl;

    return 0;
}