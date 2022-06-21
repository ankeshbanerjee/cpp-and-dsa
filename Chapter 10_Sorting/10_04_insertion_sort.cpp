#include <iostream>
using namespace std;

void printArray (int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

void insertionSort (int arr[], int n){
    for (int i=1; i<n; i++){
        // round 1 to n-1
        int temp = arr[i];
        int j = i-1;
        while (j>=0){
            if (temp < arr[j]){
                arr[j+1] = arr[j];
            }
            else {
                break; 
            }
            j--;
        }
        arr[j+1] = temp;
    }
}

int main (){
    int arr[7] = {10, 1, 7, 4, 8, 2, 11};
    insertionSort (arr, 7);
    printArray(arr, 7);
return 0;
}