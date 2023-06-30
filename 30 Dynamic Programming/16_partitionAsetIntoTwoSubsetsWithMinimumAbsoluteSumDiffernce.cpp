#include <bits/stdc++.h>
using namespace std;

// let the two subset sums be s1 and s2
// so, s2 = totalSum-s1;
// so, we need to explore the possible values of s1
// now, s1 can be anything between 0 to totalSum
// so, initiating dp array - dp[n][totalSum+1], here, prev[totalSum]
// the idea is, dp[n-1][target] returns true if it is possible to have subset sum = target, till index (n-1)
// here prev[target] tells the same thing.
// now, just iterate through all the possible values of s1 (0 to totalSum) and find the out the minimum sum difference
// here s1 is iterated in the range [0 to totalSum/2], coz, we are checking for abs(s1-s2) here and s2 = totalSum-s1
// so, value of abs(s1-s2) will repeat in the range [totalSum/2 to totalSum]
// so, it is enough to iterate in the range [0 to totalSum/2]

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalSum = 0;
	for (int i=0; i<n; i++)totalSum += arr[i];

	int k=totalSum;
	// space optimized code of 'subset sum equal to k'
	vector <bool> prev (k+1, 0), curr(k+1, 0);
	prev[0] = true;
	if(arr[0] <= k) prev[arr[0]] = true;

	for (int ind = 1; ind < n; ind++) {
		curr[0] = true;
		for (int target = 1; target <= k; target++) {
		bool notTake = prev[target];
		bool take = false;
		if (arr[ind] <= target)
			take = prev[target - arr[ind]];
			curr[target] = take || notTake;
		}
		prev = curr;
	}

	int mini = 1e9;
	for (int s1=0; s1<=totalSum/2; s1++){
		if (prev[s1]){
			mini = min(mini, abs(s1-(totalSum-s1)));
		}
	}
	
	return mini;
}
