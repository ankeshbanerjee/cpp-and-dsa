#include <bits/stdc++.h> 
using namespace std;

// this problem is same as the dp-18 (count subsets with given difference), just written in another language
// coz, +1 +2 +4 -3 -1 = (1+2+4) - (3+1) = 3
// s1 - s2 = d 

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);
	if (arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= k)prev[arr[0]] = 1;

    for (int ind=1; ind<n; ind++){
        for (int target=0; target<=k; target++){
            int notTake = prev[target];
	        int take = 0;
	        if (arr[ind] <= target) take = prev[target-arr[ind]];

            curr[target] = (take + notTake);
        }
        prev = curr;
    }

    return prev[k];
}

int countPartitions (int n, int d, vector<int> &arr){
    int totSum = 0;
    for (auto it : arr)totSum += it;
    if (totSum<d || (totSum-d)%2!=0) return 0;
    return findWays(arr, (totSum-d)/2);
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    return countPartitions(n, target, arr);
}
