// There are n stalls.
// In array of size n is given where the elements are the position (co-ord) of the stalls.
// k aggresive cows are to be placed in those stalls, such that, the minimum distance between two cows is largest.
// Find that largest distance betweeen two cows.

// Why binary search to solve this problem?
// When we can neglect left or right part after finding a possible/ not possible solution in a sorted answer space, we use binary search;

#include <iostream>
using namespace std;

int isPossible (int arr[], int n, int k, int mid){
    int cowCount = 1;
    int lastPos = arr[0];
    for (int i=0; i<n; i++){
        if (arr[i] - lastPos >= mid){
            cowCount ++;
            if (cowCount == k){
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int aggresiveCows (int arr[], int n, int k){
    int s = 0;
    int e = arr[n-1];
    int mid = s + (e-s)/2;
    int ans = -1;
    while (s<=e){
        if (isPossible(arr, n, k, mid)){         // isPossible : is it possible to place all the cows in the stalls for this value of mid?
            s = mid+1;
            ans = mid;
        }
        else{
            e = mid -1 ;       // if it is not possible to place all the cows for a value a of mid, then it will also not be possible for the greater values of mid
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main (){
    int arr[5] = {1, 2, 3, 4, 6};
    cout << "largest minimum distance is: " << aggresiveCows (arr, 5, 2) << endl;
return 0; 
}