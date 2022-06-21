// sort 0 and 1

#include <iostream>
using namespace std;

void printArray (int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void sortOne (int arr[], int size){
    int left =0;
    int right = size-1;

    while (left < right){
        if ( arr [left] == 0 ){
            left ++;
        }
        else if (arr[right] == 1){
            right --;
        }
        else if (arr[left] == 1 && arr[right] == 0){
            swap (arr[left] , arr[right]);
            left ++;
            right --;
        }
    }
}

int main (){
    int arr[10] = {1, 1, 0, 0, 0, 0, 1, 0};
    sortOne (arr, 8);
    printArray (arr, 8);
return 0;
}