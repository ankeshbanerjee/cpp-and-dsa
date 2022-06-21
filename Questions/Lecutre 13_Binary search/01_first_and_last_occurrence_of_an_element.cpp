#include <iostream>
using namespace std;

int firstOccurrence (int arr[], int size, int key){
    int start =0, end = size-1;
    int ans = -1;

    while (start <= end){
        int mid = start + (end-start)/2;
        if (arr[mid] == key){
            ans = mid;
            end = mid -1;
        }
        else if (arr[mid] < key){
            start = mid+1;
        }
        else if (arr [mid] > key){
            end = mid -1 ;
        }
    }
    return ans;
}
int lastOccurrence (int arr[], int size, int key){
    int start =0, end = size-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while (start <= end){
        if (arr[mid] == key){
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key){
            start = mid+1;
        }
        else if (arr [mid] > key){
            end = mid -1 ;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main (){
    int arr [11] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 7};

    cout << "First occurence of 3 is at index: " << firstOccurrence(arr, 11, 3) << endl;
    cout << "Last occurence of 3 is at index: " << lastOccurrence(arr, 11, 3) << endl;

return 0;
}