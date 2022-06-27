#include <iostream>
using namespace std;

int global = 3;         // creating global variable

void a (int n){
    cout << global << endl;
    global ++ ;
}

int main (){
    int n = 7;
    a(7);
    cout << global << endl;
return 0;
}


// using global variable is a bad practice, because, the value of the global variable can be changed by any function
// So, for sharing variables, always use reference variables.