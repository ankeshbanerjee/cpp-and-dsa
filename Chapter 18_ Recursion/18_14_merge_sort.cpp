#include <iostream>
using namespace std;

void printArray (int * arr, int size){
    for (int i=0; i< size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge (int * arr, int s, int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int * left = new int [len1];
    int * right = new int [len2];

    // copying values in the two arrays
    int mainArrayIndex = s;
    for (int i=0; i<len1; i++){
        left[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for (int i=0; i< len2; i++){
        right [i] = arr[mainArrayIndex++]; 
    }

    mainArrayIndex = s;
    int index1 = 0, index2 = 0;

    while ( index1< len1 && index2 < len2 ){
        if (left[index1] < right[index2]){
        arr[mainArrayIndex++] = left[index1++];
        }
        else{
            arr[mainArrayIndex++] = right[index2++];
        }
    }

    while (index1 < len1){
        arr[mainArrayIndex++] = left[index1++];
    }

    while (index2 < len2){
            arr[mainArrayIndex++] = right[index2++];
    }




    delete []left;
    delete []right;
}

void mergeSort (int * arr, int s, int e){
    // base case
    if (s>=e){
        return;
    }


    // ek case solve karna h
    int mid = s + (e-s)/2;

    // left part sort karna h
    mergeSort(arr, s, mid);

    // right part sort karna h
    mergeSort (arr, mid+1, e);

    // merge two sorted arrays
    merge (arr, s, e);
}

int main (){
    int arr [5] = {2, 6, 4, 1, 5};

    mergeSort (arr, 0, 4);

    printArray (arr, 5);
return 0;
}