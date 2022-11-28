#include <iostream>
using namespace std;

void print (int * arr, int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void bubbleSort (int * arr, int size){
    // base case - already sorted
    if ( size == 0 || size == 1){
        return;
    }

    // ek case solve karlo-largest element ko last mei rakh diya
    for (int i=0; i<size-1; i++){
        if (arr[i]>arr[i+1]){
            swap (arr[i], arr[i+1]);
        }
    }

    // recursive call
    bubbleSort(arr, size-1);
}

int main (){
    int arr[5] = {6, 2, 4, 8, 5};
    bubbleSort (arr, 5);
    print(arr,5);
return 0;
}