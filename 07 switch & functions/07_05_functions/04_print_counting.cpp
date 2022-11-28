#include <iostream>
using namespace std;

// Function signature
void printCounting (int n){          // when we do not need to return output from a function, we use 'void' return-type
    
    //Function body
    for (int i=1; i<= n; i++){
        cout << i << endl;
    }

    // cout << a << endl; // it will give error, as 'a' is not a variable of this function (it is of main function)

    return; // as void function does not return anything, so there is no need to use 'return' in this case.
    // using 'return' means to return the flow
    // by using 'return' we tell the compiler that, just go back from here immediately, no need to execute further codes.
}

int main (){
    int a;
    cin >> a;

    printCounting (a); // Function call

}