#include <iostream>
#include "cellularAutomaton.h"
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