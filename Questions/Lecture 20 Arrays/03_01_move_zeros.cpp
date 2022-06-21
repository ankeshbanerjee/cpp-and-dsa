#include <iostream>
#include<algorithm>
using namespace std;

void moveZeros (int arr[], int size){
    int nonZero = 0;
    for (int i=0; i<size; i++){
        if (arr[i] != 0){
            swap(arr[i], arr[nonZero]);
            nonZero++;
        }
    }
}

void printArray (int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " " ;
    }cout << endl;
}


int main (){
    int arr[6] = {0, 1, 0, 3, 12, 0};

    moveZeros (arr, 6);
    printArray(arr,6);
return 0;
}