#include <iostream>
using namespace std;

int main (){
    int a;
    cout << "Enter the value of a" << endl;
    cin >> a; // cin takes the input from the user

    if (a>0){
        cout << "a is positive" << endl;
    }
    else {
        cout << "a is not positive" << endl;
    }
}