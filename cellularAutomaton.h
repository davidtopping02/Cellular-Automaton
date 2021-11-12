/**
 * @file cellularAutomaton.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CELLULAR_AUTOMATON_H
#define CELLULAR_AUTOMATON_H

/** 
 * ### INCLUDES ###
 */
#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

/**
 * ### ERROR codes / SUCCESS codes ###
 */
#define SUCCESS 100
#define INVALID_INPUT_PARAMETER 101
#define PARTIAL_SUCCESS 102
#define MEMORY_ALLOCATION_ERROR 103
#define NOT_IMPLEMENTED 104
#define FILE_IO_ERROR 105

/**
 *
 * ### CLASSES REQUIRED FOR THE CELLULAR AUTOMATON PROGRAM ###
 */

/**
 * individual rule for each binary position
 * 
 */
class Rule
{
private:
    bool on;

public:
    //pattern aray to hold the pattern of each rule
    int pattern[3];

    /**
     * @brief Construct a new Rule object
     * 
     */
    Rule()
    {
        //initialising the private members
        this->on = false;
    }

    /**
     * @brief Set the On object
     * 
     * @param onOrOff 
     */
    void setOn(bool onOrOff)
    {
        this->on = onOrOff;
    }

    /**
     * @brief Get the On object
     * 
     * @return true 
     * @return false 
     */
    bool getOn()
    {
        return on;
    }
};

/**
 * collection of the rules 
 * 
 */
class RulesSet
{

public:
    //an array of rules for each binary position
    Rule ruleArray[8];

    RulesSet()
    {
        //initialising all patterns
        ruleArray[0].pattern[0] = 0;
        ruleArray[0].pattern[1] = 0;
        ruleArray[0].pattern[2] = 0;
        ruleArray[0].setOn(false);

        ruleArray[1].pattern[0] = 0;
        ruleArray[1].pattern[1] = 0;
        ruleArray[1].pattern[2] = 1;
        ruleArray[1].setOn(false);

        ruleArray[2].pattern[0] = 0;
        ruleArray[2].pattern[1] = 1;
        ruleArray[2].pattern[2] = 0;
        ruleArray[2].setOn(false);

        ruleArray[3].pattern[0] = 0;
        ruleArray[3].pattern[1] = 1;
        ruleArray[3].pattern[2] = 1;
        ruleArray[3].setOn(false);

        ruleArray[4].pattern[0] = 1;
        ruleArray[4].pattern[1] = 0;
        ruleArray[4].pattern[2] = 0;
        ruleArray[4].setOn(false);

        ruleArray[5].pattern[0] = 1;
        ruleArray[5].pattern[1] = 0;
        ruleArray[5].pattern[2] = 1;
        ruleArray[5].setOn(false);

        ruleArray[6].pattern[0] = 1;
        ruleArray[6].pattern[1] = 1;
        ruleArray[6].pattern[2] = 0;
        ruleArray[6].setOn(false);

        ruleArray[7].pattern[0] = 1;
        ruleArray[7].pattern[1] = 1;
        ruleArray[7].pattern[2] = 1;
        ruleArray[7].setOn(false);
    }
};

/**
 * ### FUNCTON DEFINITIONS ###
 */

/**
 * @brief function to convert a number to 8-bit binary
 * 
 * @param n 
 * @return string 
 */
string toBinary(int n);

/**
 * @brief Set the Rules From Binary Number
 * 
 * @param rules 
 * @param binaryNumber 
 * @return int 
 */
int setRulesFromBinary(RulesSet rules, string binaryNumber);

/**
 * @brief determines the next line based on the rules and the previous line
 * 
 * @param theRules 
 * @param currentLine 
 * @return int* 
 */
int *nextLine(RulesSet theRules, int currentLine[41]);

#endif //CELLULAR_AUTOMATON_H