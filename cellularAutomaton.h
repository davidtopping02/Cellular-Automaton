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

#include <vector>
#include <iostream>
using namespace std;

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
        on = onOrOff;
    }
};

/**
 * collection of the rules 
 * 
 */
class RulesSet
{

private:
    //each rule position
    Rule pos1;
    Rule pos2;
    Rule pos4;
    Rule pos8;
    Rule pos16;
    Rule pos32;
    Rule pos64;

public:
    RulesSet()
    {
        //initialising all patterns
        vector<int> tempVector = {0, 0, 0};
        pos1.setPattern(tempVector);
        pos1.setOn(false);

        tempVector = {0, 0, 1};
        pos2.setPattern(tempVector);
        pos2.setOn(false);

        tempVector = {0, 1, 0};
        pos2.setPattern(tempVector);
        pos2.setOn(false);

        tempVector = {0, 1, 1};
        pos4.setPattern(tempVector);
        pos4.setOn(false);

        tempVector = {1, 0, 0};
        pos8.setPattern(tempVector);
        pos8.setOn(false);

        tempVector = {1, 0, 1};
        pos16.setPattern(tempVector);
        pos16.setOn(false);

        tempVector = {1, 1, 0};
        pos32.setPattern(tempVector);
        pos32.setOn(false);

        tempVector = {1, 1, 1};
        pos64.setPattern(tempVector);
        pos64.setOn(false);
    }
};

#endif //CELLULAR_AUTOMATON_H