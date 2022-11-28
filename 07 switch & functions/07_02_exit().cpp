// If we use a switch case in an infinite loop, then how to get out of that loop, without using 'break'?
// We here use exit(), which immediately terminates the process.
//The exit() function is used to terminate a process or function calling immediately in the program.
// It means any open file or function belonging to the process is closed immediately as the exit() function occurred in the program

#include <iostream>
using namespace std;

int main (){
    int num = 1;
    while (1){
        switch (num){
            case 1: cout << num << endl;
            exit(0); // 0 means successfully exits.
        }
    }
}