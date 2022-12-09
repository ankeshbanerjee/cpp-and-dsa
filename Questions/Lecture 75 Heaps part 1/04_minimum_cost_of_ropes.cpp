#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long minCost (long long arr[], long long n){
    // push into min heap
    priority_queue<long long, vector<long long>, greater <long long> > pq;
    for (long long i=0; i<n; i++){
        pq.push(arr[i]);
    }

    long long cost = 0;

    while (pq.size() > 1){
        long long m = pq.top();
        pq.pop();

        long long n = pq.top();
        pq.pop();

        long long sum = m+n;
        cost =+ sum;

        pq.push(cost);
    }
    return cost;
}
// TC = NlogN, for insertion
// SC = O(N), for using priority queue
int main (){
    
return 0;
}