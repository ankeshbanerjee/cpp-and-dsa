#include <iostream>
using namespace std;

int main (){
    int arr [ 100 ];
    cout << "Enter the size (length) of the array: " << endl;
    int n;
    cin >> n;

    for (int i= 0; i<n; i++){
        cout << "Enter the " << i+1 << "th element of the array: " << endl;
        cin>> arr[i];
    }


    int sum = 0;
    for (int i= 0; i<n; i++){
        sum = sum + arr[i];
    }

    cout << "The result is : " << sum << endl;
return 0;
}