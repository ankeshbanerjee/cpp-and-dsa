// There are n books and m students. The books are to be distributed among  the students such that the maximum number of pages of a student is minimum.
// Distribution should be in a contiguous manner.
// The elements of the array are the no. of pages of the n books. 
// Now, return that maximum number of pages of a student, which is minimum of all the cases.
// For more about the qs, go to codestudio_book allocation problem

// Why binary search to solve this problem?
// When we can neglect left or right part after finding a possible/ not possible solution in a sorted answer space, we use binary search;

#include <iostream>
using namespace std;

bool isPossible (int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for (int i=0; i < n; i++){
        if (pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if (arr[i]>mid || studentCount > m){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocate (int arr[], int n, int m){
    int s = 0;
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;

    while (s<=e){
        if (isPossible(arr, n, m, mid)){
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
    int arr[4] = {10, 20, 30, 40};
    cout << "Maximum no. of pages to a student, which is minimum of all the cases is: " << allocate(arr, 4, 2) << endl;
return 0;
}