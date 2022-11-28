#include <iostream>
using namespace std;

int getMax (int arr[], int n){
    int maximum = INT_MIN;
    for ( int i = 0; i< n; i++){
        // if ( maximum < arr [i] ){
        //     maximumimum = arr [i];
        // }
        int maximum = max ( maximum, arr[i] );
    }
    return maximum;
}

int getMin (int arr [], int n){
    int minimum = INT_MAX;
    for (int i=0; i<n; i++){
        // if ( minimum > arr[i]){
        //     minimum = arr[i];
        // }
        minimum = min ( minimum, arr[i] );
    }
    return minimum;
}

int main (){
    int size;
    cin>> size;

    // int arr [size] is a bad practice
    int arr [100]; 
    // it is a better practice

    for (int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "Maximum value is: " << getMax(arr, size) << endl;
    cout << "Minimum value is: " << getMin(arr, size) << endl;

return 0;
}