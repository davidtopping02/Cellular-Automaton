#include "cellularAutomaton.h"
#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;

int main()
{

    RulesSet theRules;
    setRulesFromBinary(theRules, "00100000");

    int lineArray[41];

    for (int i = 0; i < 41; i++)
    {
        lineArray[i] = 0;
    }

    lineArray[21] = 1;
    // lineArray[41] = 1;
    // lineArray[0] = 1;
    // lineArray[1] = 1;
    nextLine(theRules, lineArray);

    return 0;
}