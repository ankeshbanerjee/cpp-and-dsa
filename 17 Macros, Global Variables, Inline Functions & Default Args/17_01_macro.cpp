// MACRO: mactro is a piece of code in a program that is replaced by the value of the macro


#include <iostream>
using namespace std;

#define PI 3.14         //creating macro

int main (){
    // double pi = 3.14     // creating a variable will not do the same thing, because of 2 reasons:
                            // 1. a certain amount of memory will be allocated for the variable (e.g. for a double 8 byte will be allocated),
                            //  whereas, for macro, no memory is allocated.
                            // 2. One can change the value of the variable by mistake

                            // ** here, pi = pi + 1, this can be done, but, PI = PI + 1, this can't be done, because this is not a variable,
                            //    and no memory storage is allocated for it.
    
    int r = 3;
    double area = PI * r * r;   // here 'PI' will be replaced by it's value

    cout << "Area is: " << area << endl;
return 0;
}