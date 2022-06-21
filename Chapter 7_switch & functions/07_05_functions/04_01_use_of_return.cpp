#include <iostream>
using namespace std;

void function ( int a, int b ){
    cout << a << endl;
    return;
     // by using 'return' we tell the compiler that, just go back from here immediately, no need to execute further codes.
    cout << b << endl;
}

int main (){
    
    int a = 1;
    int b = 2;
    
    function (a,b);

    return 0;
}