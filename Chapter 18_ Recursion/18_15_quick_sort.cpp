#include <iostream>
using namespace std;

void printArray (int * arr, int size){
    for (int i=0; i< size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition (int * arr, int s, int e){

    int pivot = arr[s];
    
    //count elements which are less than pivot
    int cnt =0;
    for (int i=s; i<=e; i++){
        if (arr[i] < pivot){
            cnt ++;
        }
    }

    // placing pivot at the right position
    int pivotIndex = cnt +s ;
    swap (arr[pivotIndex],arr[s]);

    // pivot k left part mei < pivot && pivot k right part mei > pivot
    int i=s, j=e;
    
    while (i < pivotIndex && j > pivotIndex){
        while (arr[i] < pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }

        if (i < pivotIndex && j > pivotIndex){
            swap (arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort (int * arr, int s, int e){
    // base case
    if (s >= e){
        return ;
    }

    // ekcase solve karna h

    // partition
    int p = partition(arr, s, e);

    // left part sort karna h
    quickSort(arr, s, p-1);

    // right part sort karna h
    quickSort(arr, p+1, e);
}

int main (){
    int arr[5] = {6, 2, 4, 3, 1};

    quickSort (arr, 0, 4);

    printArray (arr, 5);
return 0;
}