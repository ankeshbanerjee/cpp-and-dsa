// A B C 
// A B C 
// A B C

#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the number of rows: " << endl;
    cin >> n;

    int i = 1;

    while (i <= n){
        int j = 1;
        char ch = 'A';
        while (j <= n){
            cout << ch << " ";
            j = j + 1;
            ch = ch + 1;
        }
        i = i+1;
        cout << endl;
    }
}