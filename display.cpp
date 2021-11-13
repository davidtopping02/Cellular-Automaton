
using namespace std;
#include <iostream>
#include <cellularAutomaton.h>

int testArray[10] = {0,0,0,0,1,0,1,0,1,0};

void display(){
    for(int i = 0; i < 10; i++){
        if(testArray[i] == 1){
            cout << "#";
        }else{
            cout << "-";
        }
    }
    cout << '\n';
}
int main(){
 display();
}
