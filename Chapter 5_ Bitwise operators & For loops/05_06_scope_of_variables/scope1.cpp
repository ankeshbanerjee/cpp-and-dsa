#include <iostream>
using namespace std;

int main (){
    int a = 3;
    cout << a << endl;

    if (true){
        int a = 7;
        cout << a << endl;
    }
// the 'a's inside and outside the block are different.
   
    cout << a << endl;
    // this 'a' will be the 'a' created outside.

}