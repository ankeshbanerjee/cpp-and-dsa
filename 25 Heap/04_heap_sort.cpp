#include <iostream>
#include <vector>
using namespace std;

void heapify (vector <int> &arr, int n, int i){
    // 0 base indexing
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// heap sort
void heapSort (vector<int> &arr){
    // heap creation
    int size = arr.size();
    for (int i= size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }

    // sorting
    int n = size-1;
    while (n > 0){
        // step 1: swap first and last element of array
        swap (arr[0], arr[n]);

        // step 2: decrease n, as last element is placed in correct position
        n--;

        // step 3: heapify the rest array
        heapify(arr, n+1, 0); // here, n+1 because we have to pass the size of the array here (not the last index)
    }
}

// TC = nlogn

int main (){

    vector<int> input = {54, 53, 55, 52, 50};

    cout << "Array before sorting:" << endl;
    for (auto i : input){
        cout << i << " ";
    }
    cout << endl;

    heapSort(input);

    cout << "Array after sorting:" << endl;
    for (auto i : input){
        cout << i << " ";
    }
    cout << endl;

return 0;
}