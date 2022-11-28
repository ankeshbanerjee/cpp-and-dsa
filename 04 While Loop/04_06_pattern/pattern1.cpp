// No. of rows = No. of columns

#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the number of rows: " << endl;
    cin >> n;

    int i = 1;
cout << "Pattern:-" << endl << endl;
    while (i<=n){
        int j = 1;
        while (j<=n){
            cout << "* " ;
            j=j+1;
        }
        cout << endl;
        i = i+1;
    }
}