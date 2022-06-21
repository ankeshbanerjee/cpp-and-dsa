// There are N number of boards and K number of painters
// There is array of size N. The elements of the array are the length of the boards.
// 1 unit time is required to paint 1 unit length of the board
// Find the minimum time required to get the job done
// condition is that painters can paint only contiguous boards.

#include <iostream>
using namespace std;
bool isPossible (int arr[], int n, int k, int mid){
    int painterCount = 1;
    int boardLengthSum = 0;

    for (int i=0; i<n; i++){
        if (boardLengthSum + arr[i] <= mid){
            boardLengthSum += arr[i];
        }
        else {
            painterCount ++;
            if (painterCount > k || arr[i] > mid){
                return false;
            }
            boardLengthSum = arr[i];
        }
    }
    return true;
}

int partition(int arr[], int n, int k){
    int s = 0;
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if (isPossible(arr, n, k, mid)){
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main (){
    int arr [4] = {10, 20, 30, 40};
    cout <<"Minimum time to required to complete the job: "<< partition(arr, 4, 2) << endl;
return 0;
}