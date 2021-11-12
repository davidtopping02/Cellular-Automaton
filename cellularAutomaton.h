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
#include <vector>
#include <iostream>
#include <bitset>
#include <string>
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
 * CLASSES REQUIRED FOR THE CELLULAR AUTOMATON PROGRAM
 * 
 */

/**
 * individual rule for each binary position
 * 
 */
class Rule
{
private:
    vector<int> pattern;
    bool on;

public:
    /**
     * @brief Construct a new Rule object
     * 
     */
    Rule()
    {
        //initialising the private members
        this->on = false;
    }

    void setPattern(vector<int> newPattern)
    {
        pattern = newPattern;
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

    /**
     * @brief Get the Pattern object
     * 
     * @return vector<int> 
     */
    vector<int> getPattern()
    {
        return pattern;
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
        vector<int> tempVector = {0, 0, 0};
        ruleArray[0].setPattern(tempVector);
        ruleArray[0].setOn(false);

        tempVector = {0, 0, 1};
        ruleArray[1].setPattern(tempVector);
        ruleArray[1].setOn(false);

        tempVector = {0, 1, 0};
        ruleArray[2].setPattern(tempVector);
        ruleArray[2].setOn(false);

        tempVector = {0, 1, 1};
        ruleArray[3].setPattern(tempVector);
        ruleArray[3].setOn(false);

        tempVector = {1, 0, 0};
        ruleArray[4].setPattern(tempVector);
        ruleArray[4].setOn(false);

        tempVector = {1, 0, 1};
        ruleArray[5].setPattern(tempVector);
        ruleArray[5].setOn(false);

        tempVector = {1, 1, 0};
        ruleArray[6].setPattern(tempVector);
        ruleArray[6].setOn(false);

        tempVector = {1, 1, 1};
        ruleArray[7].setPattern(tempVector);
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

#endif //CELLULAR_AUTOMATON_H