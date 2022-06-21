#include <iostream>
using namespace std;

int main (){
    int num = 3; 
    cout << num << endl;
    // every variable name is mapped with its address in the symbol table.
    // so, when the variable 'num' is needed to be accessed, it will go to the corresponding mapped address of 'num'
    // then, we will get the value stored at that address.

    
    // address Of Operator => &
    cout << "Address of num is: " << &num << endl;
return 0;
}