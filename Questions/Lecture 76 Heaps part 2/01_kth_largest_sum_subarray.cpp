#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*

int getKthLargest (vector <int> &arr, int k){

    vector<int>storeSum;
    int n = arr.size();

    for (int i=0; i<n; i++){
        int sum = 0;

        for (int j=i; j<n; j++){
            sum += arr[j];
            storeSum.push_back(sum);
        }
    }

    sort (storeSum.begin(), storeSum.end());
    // kth largest will be on [storeSum.size()-k] th index
    return storeSum[storeSum.size()-k];
}
// TC = O(n^2logn) , bcz TC of sorting is LlogL
// SC = O(n^2)

*/

int getKthLargest (vector <int> &arr, int k){

    priority_queue <int, vector<int>, greater<int> > mini;
    int n = arr.size();

    for (int i=0; i<n; i++){
        int sum = 0;

        for (int j=i; j<n; j++){
            sum += arr[j];
            if (mini.size() <= k){
                mini.push(sum);
            }
            else{
                if (sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }    
            }
        }
    } 

    return mini.top();
}

// TC = O(N^2logK), bcz of n^2 insertion in k sized heap
// SC = O(K), bcz of using priority queue (heap)

int main (){
    
return 0;
}