// ****
//  ***
//   **
//    *

#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the number of rows: "<< endl;
    cin >> n;

    int i = 1;
    while ( i <= n){
           int k = 1;
        while (k <= i-1){
            cout << " " ;
            k = k+1;
        }
        int j = 1;
        while (j <= n - i +1 ){
            cout << "*" ;
            j = j + 1;
        }
        cout << endl;
        i = i+1;
    }
}

