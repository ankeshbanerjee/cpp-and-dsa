#include <iostream>
using namespace std;

void printArray (int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

void bubbleSort (int arr[], int n){
    for (int i=1; i<n; i++){
        // for round 1 to n-1
        bool swapped = false;
        for (int j=0; j < n-i; j++){    // loop will run upto the 2nd last element
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false){     // if no swaps in one of the rounds, then it is sorted.
            break; // or, return;
        }
    }
}

int main (){
    int arr[5] = {6, 2, 8, 4, 10};
    bubbleSort(arr, 5);
    printArray(arr,5);
return 0;
}