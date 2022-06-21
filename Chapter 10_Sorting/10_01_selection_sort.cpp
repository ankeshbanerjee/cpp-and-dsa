#include <iostream>
using namespace std;
void printArray (int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
    return;
}

void selectionSort (int arr[], int size){
    for (int i=0; i < size-1; i++){
        int minIndex = i;
        for (int j=i+1; j < size; j++){
            if(arr [j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    return;
}

int main (){
    int arr[5] = {64, 25, 12, 22, 11};
    selectionSort (arr, 5);
    printArray (arr,5);
return 0;
}