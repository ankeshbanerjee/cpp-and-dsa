#include <iostream>
using namespace std;

int main () {

    int a, b;

    cout << "Enter the value of a: " << endl;
    cin >> a;
    cout << "Enter the value of b: " << endl;
    cin >> b;

    if (a < b){
        cout << "B is greater than A" << endl;
    }
    else if (a > b){
        cout << "A is greater than B" << endl;
    }
    else if (a == b){
        cout << "A and B are equal" << endl;
    }

}