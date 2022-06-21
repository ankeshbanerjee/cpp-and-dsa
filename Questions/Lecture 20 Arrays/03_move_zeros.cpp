#include <iostream>
using namespace std;

void moveZeros (int arr[], int size, int ans[]){
    int i=0, k=0;
    while (i<size){
        if ( arr[i] != 0){
            ans[k++] = arr[i++];
        }
        else {
            i++;
        }
    }
    while (k<size){
        ans[k++] = 0;
    }
}

void printArray (int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " " ;
    }cout << endl;
}


int main (){
    int arr1[6] = {0, 1, 0, 3, 12, 0};
    
    int ans [6];

    moveZeros(arr1, 6, ans);
    printArray(ans, 6);
return 0;
}