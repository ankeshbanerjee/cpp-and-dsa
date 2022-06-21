// 1
// 2 3
// 3 4 5
// 4 5 6 7
// 5 6 7 8 9

#include <iostream>
using namespace std;

int main (){
    cout << "Enter the number of rows: " << endl;
    int n;
    cin >> n;

    int i = 1;
    while (i <= n){
        int j=1;
        int k = i;
        while (j<=i){
            cout << k << " ";
            k = k+1;
            j = j + 1;
        }
        cout << endl;
        i = i +1;
    }
    
}