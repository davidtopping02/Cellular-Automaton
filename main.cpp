#include <iostream>
#include "cellularAutomaton.h"
using namespace std;
#include <string>

void automatonOptions();

int main()
{
    int choice = 0;

    while (choice != 4) {
        cout << "\nSelect an option: [1] Run Automaton [2] Load saved file [3] Game of life [4] Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                automatonOptions();
                break;
            case 2:
                cout << "Choice 2" << endl;
                break;
            case 3:
                cout << "Choice 3" << endl;
                break;
            case 4:
                cout << "Choice 4" << endl;
                break;
            case 5:
                cout << "Exiting Program" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
        cin.clear();
        cin.ignore();
    }
    return 0;
}

// MAY NEED TO DELETE THIS FUNCTION... IDK IF YOU GOT THESE VALUES IN THE ACTUAL FUNCTION
void automatonOptions() {
    int rule1;
    int iterations = 0;
    string binary = "00000000";

    cout <<"\nEnter 8 bit binary number";
    cin >> binary;

    cout << "\nSelect Rule" << endl;
    cin >> rule1;

    cout << "\nHow long should it run for (how many iterations)" << endl;
    cin >> iterations;

    //call automaton function with these parameters?
}