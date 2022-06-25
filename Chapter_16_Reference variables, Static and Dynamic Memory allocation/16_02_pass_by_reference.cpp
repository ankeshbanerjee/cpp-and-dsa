#include <iostream>
using namespace std;

void update1 (int n){   // here a memory block is created, named 'n'
    n++;
}

void update2 (int& n){  // here no new memory block is created, it is a reference variable and it is directly pointing towards the variable of the main function
    n++;
}

int main (){
    int n = 3;

    cout << "before: " << n << endl;
    update1(n);
    cout << "after: " << n << endl;

    
    cout << "before: " << n << endl;
    update2(n);
    cout << "after: " << n << endl;

return 0;
}