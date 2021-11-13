#include "cellularAutomaton.h"
#include <iostream>
#include <bitset>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    //creating new rule set and setting it to rule 30
    RulesSet theRules;
    theRules.setRulesFromBinary(toBinary(30));

    //emptying the file
    std::ofstream ofs;
    ofs.open("cellularAutomaton.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    //creating a sample current line and initialising all values to 0
    int lineArray[81];

    for (int i = 0; i < 81; i++)
    {
        lineArray[i] = 0;
    }

    //setting middle array elemenet to 1
    lineArray[41] = 1;

    newLine(theRules, lineArray, 40);

    return 0;
}