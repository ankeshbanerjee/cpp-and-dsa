#include <iostream>
using namespace std;

int main (){
    int num = 3;
    int * ptr = &num;

    cout << ptr << endl;
    cout << &num << endl;

    // int * ptr => ptr is a pointer to an integer
    // char * ptr => ptr is a pointer to a character
    // double num = 1.4;
    // double * ptr = &num;
    // ptr is a pointer to a double



    // Dereference Operator => *
    cout << *ptr << endl; // *ptr => value at address pointed by ptr
    cout << num << endl;
    
return 0;
}