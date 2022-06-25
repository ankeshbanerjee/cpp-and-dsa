#include <iostream>
using namespace std;

int main (){
    int i=3;
    // creating a reference variable (reference variable: same memory location but different names)
    int & j = i;

    cout << i << endl;
    cout << j << endl;
    
    i++;
    cout << i << endl;
    cout << j << endl;

    j++;
    cout << i << endl;
    cout << j << endl;
return 0;
}