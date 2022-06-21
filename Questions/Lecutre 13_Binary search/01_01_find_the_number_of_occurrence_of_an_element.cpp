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
    int firstOcc = firstOccurrence (arr, 11, 3);
    int lastOcc = lastOccurrence (arr, 11, 3);

    cout <<"Total no. of occurrence of 3 is " << (lastOcc - firstOcc + 1) << endl;
    // This is the formula to find the no. of occurrence
    
return 0;
}