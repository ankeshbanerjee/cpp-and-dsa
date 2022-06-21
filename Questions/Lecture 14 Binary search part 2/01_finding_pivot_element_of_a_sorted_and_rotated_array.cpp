// Minimum of the sorted and rotated array will be the pivot element
#include <iostream>
using namespace std;

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

int main (){
    int arr[8] = {3, 4, 5, 6, 7, 8, 1, 2};
    int ans = pivot (arr, 8);
    cout << "The pivot element is: " << arr[ans] << endl;
return 0;
}