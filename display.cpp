
using namespace std;
#include <iostream>
#include "cellularAutomaton.h"

// int testArray[10] = {0,0,0,0,1,0,1,0,1,0};

void display(int cellArray[]){
    for(int i = 0; i < 10; i++){
        if(cellArray[i] == 1){
            cout << "#";
        }else{
            cout << "-";
        }
    }
    cout << '\n';
}
