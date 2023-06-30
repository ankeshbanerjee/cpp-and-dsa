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


// An important note : 
// in this problem, given constraint is 1 <= arr[i]
// but if the constraint were, 0 <= arr[i], then this base case would not return correct answer
// e.g. consider, arr= {0, 0, 1}, target = 1;
// the actual answer of this problem should be 4 ({0, 1}, {0, 1}, {0, 0, 1}, {1})
// but this method would give its answer as 1, coz, after the first call, 
// it will get target = 0 and according to the base it would return 1;
// so, if the constraint is 0 <= arr[i], we have to change the base case and take the call upto ind==0
// the modified base case will be -
// when (ind == 0)
//	- then two cases will be there, sum == 0 and sum != 0
// 		now if (sum == 0), then if arr[0] == 0, then there will be two options - take or not take
// 			i.e., if we take arr[0], then the sum will be 0, as arr[0] == 0, and even if we don't take it, then also the sum will be 0
// 			i.e., two we will have two subsets here - [{0}, {}]. so, return 2;
// 			and if it arr[0] != 0, then, only option is to not take it. (subset - {}), so return 1;
// now, if sum != 0
// 			then, return (arr[0] == sum);
//	
// code :-
// if (ind == 0){
// 	if (sum == 0){
// 		if (arr[0] == 0) return 2;
// 		else return 1;
// 	}
// 	else{
// 		return (arr[0] == sum);
// 	}
// }

// or, another form of it is ->
// if (ind==0){
// 	if (sum == 0 && arr[0] == 0) return 2;
// 	if (sum == 0 || arr[0] == sum) return 1;
// 	return 0;
// }

// this base case will be required in the next problem (dp-18)
int f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
	// base case
	if (ind == 0){
		if (sum == 0){
			if (arr[0] == 0) return 2;
			else return 1;
		}
		else{
			return (arr[0] == sum);
		}
	}

	if (dp[ind][sum] != -1)return dp[ind][sum];
	// take or not take
	int notTake = f(ind-1, sum, arr, dp);
	int take = 0;
	if (arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr, dp);

	return dp[ind][sum] = take + notTake;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return f(n-1, k, arr, dp);
}

// tabulation and space optimization in next problem (dp-18)