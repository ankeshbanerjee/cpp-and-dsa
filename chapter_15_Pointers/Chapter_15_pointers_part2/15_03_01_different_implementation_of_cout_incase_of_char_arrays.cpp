#include <iostream>
using namespace std;

int main (){
        char temp = 'z';
    char * p = &temp;
    cout << p << endl; // it is a char pointer, i.e., it will print the entire content, till it finds the null character
    // here, first it prints 'z', then it's subsequent characters and stops when it finds the null character
return 0;
}