#include <iostream>
using namespace std;

int binarySearch (int arr[], int size, int key, int s, int e){
    int mid = s + (e-s)/2;
    while (s<=e){
        if (arr[mid] == key){
            return mid;
        }
        if (arr[mid]<key){
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int pivot (int arr[], int size){
    int s = 0, e= size - 1;
    int mid = s + (e-s)/2;
    while (s<e){
        if (arr[mid] >= arr[0]){
        s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s; // return e;
}

int search (int arr[], int size, int key){
    int p = pivot (arr, size);
    if (key >= arr[p] && key <= arr[size-1]){
        return binarySearch(arr, size, key, p, size-1);
    }
    else {
        return binarySearch (arr, size, key , 0, p-1);
    }
}

int main (){
    int arr[5] = {7, 9, 1, 2, 3};
    if (search (arr, 5, 2) == -1){
        cout << "Key is absent" << endl;
    }
    else {
        cout << "Key is present at index: " <<search (arr, 5, 2)<<  endl;
    }
return 0;
}