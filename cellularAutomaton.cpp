#include "cellularAutomaton.h"
#include <iostream>
#include <bitset>
#include <cstring>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

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

    //returning a string with the converted number
    return binaryNum_string;
}

/**
 * @brief Set the Rules From Binary Number
 *  
 * @param binaryNumber 
 * @return int 
 */
int RulesSet::setRulesFromBinary(string binaryNumber)
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
            this->ruleArray[i].setOn(true);
        }
    }

    return SUCCESS;
}

/**
 * @brief recursive method that determines the next line based on the rules and the previous line
 * 
 * @param theRules 
 * @param currentLine 
 * @return int* 
 */
void newLine(RulesSet theRules, int currentLine[], int endCondition)
{

    //initialising temporary variables
    int previous = currentLine[81];
    int nextLine[81];
    if (endCondition > 0)
    {
        //initialising all array values to 0
        for (int i = 0; i < 81; i++)
        {
            nextLine[i] = 0;
        }

        //looping through the whole row
        for (int i = 0; i < 81; i++)
        {
            //initialise temporary variables
            Rule ruleToUse;
            int currentPattern[3];

            //getting the pattern (previous, currnet, next) for the current position and storing
            currentPattern[0] = previous;
            currentPattern[1] = currentLine[i];
            currentPattern[2] = currentLine[(i + 1)];

            //looping through each rule finding which rule applies to the pattern found
            for (int j = 8; j >= 0; j--)
            {
                if ((currentPattern[0] == theRules.ruleArray[j].pattern[0]) && (currentPattern[1] == theRules.ruleArray[j].pattern[1]) && (currentPattern[2] == theRules.ruleArray[j].pattern[2]))
                {
                    ruleToUse = theRules.ruleArray[j];
                    break;
                }
            }

            //setting new previous to the current
            previous = currentLine[i];

            //setting the nexlines value to be 1 if rule is on
            if (ruleToUse.getOn() == true)
            {
                nextLine[i] = 1;
            }
        }

        endCondition--;
        //  int *newLine = nextLine(theRules, lineArray);

        display(nextLine);
        writeToFile(nextLine);
        newLine(theRules, nextLine, endCondition);

        //returning a pointer to the next line
        // return nextLine;
    }
}

/**
 * @brief displays the array containing the next line
 * 
 * @param cellArray 
 */
void display(int cellArray[])
{
    for (int i = 0; i < 81; i++)
    {
        if (cellArray[i] == 1)
        {
            cout << "*";
        }
        else
        {
            cout << ".";
        }
    }
    cout << '\n';
}

/**
 * @brief writes the output of the program to a file
 *
 * @param cellArray 
*/

void writeToFile(int cellArray[]) {

    //open file
    string filename("cellularAutomaton.txt");
    fstream myFile;
    myFile.open(filename, std::ios_base::app | std::ios_base::in);

    //if file is open
    if (myFile.is_open())
        for (int i = 0; i < 81; i++) {
        if (cellArray[i] == 1) {
            myFile << "*";
        }
        else {
            myFile << ".";
        }
    }
    myFile << '\n';
}