#include "cellularAutomaton.h"
#include <iostream>
#include <bitset>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief function to convert a number to 8-bit binary
 * 
 * @param n 
 * @return string 
 */
string toBinary(int n)
{
    //converting the int to a binary bitset
    bitset<8> binaryNum(n);

    //converting bitset to string
    string binaryNum_string = binaryNum.to_string();

    return binaryNum_string;
}

/**
 * @brief Set the Rules From Binary Number
 * 
 * @param rules 
 * @param binaryNumber 
 * @return int 
 */
int setRulesFromBinary(RulesSet theRules, string binaryNumber)
{
    //converting the binary number to an array of characters in correct order
    char binArray[8];
    reverse(binaryNumber.begin(), binaryNumber.end());
    strcpy(binArray, binaryNumber.c_str());

    //looping through each array character and setting the rule to on if it is required
    for (int i = 0; i < 8; i++)
    {
        if (binArray[i] == '1')
        {
            theRules.ruleArray[i].setOn(true);
        }
    }

    return SUCCESS;
}

/**
 * @brief determines the next line based on the rules and the previous line
 * 
 * @param theRules 
 * @param currentLine 
 * @return int* 
 */
int *nextLine(RulesSet theRules, int currentLine[])
{
    int previous = currentLine[41];
    int nextLine[41];

    for (int i = 0; i < 41; i++)
    {
        nextLine[i] = 0;
    }

    for (int i = 0; i < 41; i++)
    {
        Rule ruleToUse;
        int currentPattern[3];

        //getting the pattern (previous, currnet, next) for the current position and storing
        currentPattern[0] = previous;
        currentPattern[1] = currentLine[i];
        currentPattern[2] = currentLine[i++];

        //finding which rule applies to the pattern found
        for (int j = 0; j < 8; j++)
        {
            if ((currentPattern[0] == theRules.ruleArray[j].pattern[0]) && (currentPattern[1] == theRules.ruleArray[j].pattern[1]) && (currentPattern[2] == theRules.ruleArray[j].pattern[2]))
            {
                ruleToUse = theRules.ruleArray[j];
                break;
            }
        }

        previous = currentLine[i];

        if (ruleToUse.getOn() == true)
        {
            nextLine[i] = 1;
        }
    }

    for (int i = 0; i < 41; i++)
    {
        cout << nextLine[i] << endl;
    }

    return nextLine;
}