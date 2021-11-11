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
    int pattern[3];
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

        for (int i = 0; i < 3; i++)
        {
            this->pattern[i] = 0;
        }
    }

    /**
     * @brief Set the Pattern object
     * 
     * @param patternArray 
     */
    void setPattern(int patternArray[3])
    {
        for (int i = 0; i < 3; i++)
        {
            pattern[i] = patternArray[i];
        }
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
    Rule pos128;

public:
    RulesSet()
    {
        //initialising all patterns
        int patternArray[3] = {0, 0, 0};
        pos1.setPattern(patternArray);
        pos1.setOn(false);

        int patternArray[3] = {0, 0, 1};
        pos2.setPattern(patternArray);
        pos2.setOn(false);
    }
};

#endif //CELLULAR_AUTOMATON_H