#include <bits/stdc++.h>
using namespace std;

// f(ind, target) expresses the number of subsets with sum=target, till array index 'ind'
// this code is almost similar to the code of dp-14 (subset sum equal to k)
// in dp-14, we just have to state if the subset with sum=k exists or not
// but here we have to count the number of subsets with sum = k;
// so, to count all ways, we have just changed the return statement of fucntion f
// in dp-14, that was 'return take | notTake;'
// which is here, changed to, 'return take+notTake;'
// to count all the ways, '+' is used

// memoization
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
	// base case
	// if target is achieved
	if (target == 0) return 1;
	if (ind == 0) return (arr[ind] == target);

	if (dp[ind][target] != -1)return dp[ind][target];
	// take or not take
	int notTake = f(ind-1, target, arr, dp);
	int take = 0;
	if (arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);

	return dp[ind][target] = take + notTake;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return f(n-1, k, arr, dp);
}
// recursion without memoization would cause a TC of O(2^n), coz, every pair (ind, target) has to options - take or notTake
// TC of memoization is O(n*k) and SC is O(n*k) + O(n) (recursion stack space)
// recursion stack space is O(n), coz, at a strech, the call can maxium go n to 0 i.e., f(n, taget) to f(0, target)


// tabulation
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, 0));
	for (int ind=0; ind<n; ind++) dp[ind][0] = 1;
	if(arr[0]<=k)dp[0][arr[0]] = 1;

	for (int ind=1; ind<n; ind++){
		for (int target=1; target<=k; target++){
			int notTake = dp[ind-1][target];
			int take = 0;
			if (arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
			dp[ind][target] = take + notTake;
		}
	}

	return dp[n-1][k];
}
// TC = O(n*k), SC = O(n*k)


// space optimization
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);
	prev[0] = 1;
	if(arr[0]<=k)prev[arr[0]] = 1;

	for (int ind=1; ind<n; ind++){
		curr[0] = 1;
		for (int target=1; target<=k; target++){
			int notTake = prev[target];
			int take = 0;
			if (arr[ind] <= target) take = prev[target-arr[ind]];
			curr[target] = take + notTake;
		}
		prev = curr;
	}

	return prev[k];
}
// TC = O(n*k)
// SC = O(k)