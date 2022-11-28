// A B C 
// D E F 
// G H I 

#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the number of rows: " << endl;
    cin >> n;

    int i = 1;
    char ch = 'A';

    while (i <= n){
        int j = 1;
        while (j <= n){
            cout << ch << " ";
            j = j+1;
            ch = ch +1;
        }
        cout << endl;
        i = i+1;
    }
}