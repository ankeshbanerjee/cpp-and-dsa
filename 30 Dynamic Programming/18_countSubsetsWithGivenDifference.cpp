#include <bits/stdc++.h> 
using namespace std;

// the array is to be divided in two subsets, let, their sums are s1 and s2
// according to the ques, s1 >= s2 and s1 - s2 = d
// now, if the sum of all the elements of the array is totSum, then
// s1 = totSum - s2
// s1 - s2 = d => totSum - 2s2 = d => s2 = (totSum - d) / 2
// so, our task is to just count the number of subsets with sum ((totSum - d) / 2), which is the problem - dp-17 (count subsets with sum k)
// just two edge cases are needed to be watched out -
// 1. totSum >= d, coz, the totSum can't be less than the difference of the s1 and s2
// 2. (totSum-d) has to be even, coz it is the sum of a subset of integers (s2), so that (totSum-2)/2 can be an integer
// so, if these two cases don't get fulfilled, return 0 (i.e., count of such subsets is 0)


int mod = (int)(1e9+7);

int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
	// base case
	if (ind == 0){
		if (target == 0){
			if (arr[0] == 0) return 2;
			else return 1;
		}
		else{
			return (arr[0] == target);
		}
	}

	if (dp[ind][target] != -1)return dp[ind][target];
	// take or not take
	int notTake = f(ind-1, target, arr, dp);
	int take = 0;
	if (arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);

	return dp[ind][target] = (take + notTake)%mod;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return f(n-1, k, arr, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum = 0;
    for (int i=0; i<n; i++)totSum += arr[i];

    // edge case
    if (totSum < d || (totSum - d)%2) return 0;

    return findWays (arr, (totSum-d)/2);
}


// tabulation
int mod = (int)(1e9+7);

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, 0));
	if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k)dp[0][arr[0]] = 1;

    for (int ind=1; ind<n; ind++){
        for (int target=0; target<=k; target++){
            int notTake = dp[ind-1][target];
	        int take = 0;
	        if (arr[ind] <= target) take = dp[ind-1][target-arr[ind]];

            dp[ind][target] = (take + notTake) % mod;
        }
    }

    return dp[n-1][k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum = 0;
    for (int i=0; i<n; i++)totSum += arr[i];

    // edge case
    if (totSum < d || (totSum - d)%2) return 0;

    return findWays(arr, (totSum-d)/2);
}


// space optimization
#include <bits/stdc++.h> 
int mod = (int)(1e9+7);

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

            curr[target] = (take + notTake) % mod;
        }
        prev = curr;
    }

    return prev[k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum = 0;
    for (int i=0; i<n; i++)totSum += arr[i];

    // edge case
    if (totSum < d || (totSum - d)%2) return 0;

    return findWays(arr, (totSum-d)/2);
}





