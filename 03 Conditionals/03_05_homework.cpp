#include <iostream>
using namespace std;

int main () {
    char ch;
    cout << "Enter your input" << endl;
    cin >> ch;
    
    if (ch <= 122 && ch >= 97){
        cout << "Lower case" << endl;
    } 
    else if ( ch >= 65 && ch <= 90){
        cout << "Upper case" << endl;
    }
    else if (ch >= 48 && ch <= 57){
        cout << "This is numeric" << endl;
    }
}