#include <iostream>
#include <queue>
using namespace std;

int kthSmallest (int arr[], int l, int r, int k){
    // step 1: make max heap
    priority_queue<int> pq;

    // step 2: push first k elements of the array into the heap
    for (int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    // step 3: compare rest elements with heap top; if element < heap top, then push it
    for (int i=k; i<=r; i++){
        if (arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step 4: return heap top
    int ans = pq.top();
    return ans;
}
// TC = O(KlogK + (N-K)logK)
// SC = O(K), bcz using priority queue


int main (){
    int arr[6] = {7, 12, 10, 20, 17, 15};
    cout << "4th smallest element: " << kthSmallest(arr,0,5,4) << endl;
return 0;
}