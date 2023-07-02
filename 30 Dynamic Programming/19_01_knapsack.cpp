#include <bits/stdc++.h>
using namespace std;

// this problem is similar as dp-14
// two choices - take(if weight left for bag >= weight[currentIndex]) or notTake
// base case if ind == 0, then I will take that if, weight left for the bag <= weight[0]

#include <bits/stdc++.h>
int f(int ind, int W, vector<int> &val, vector<int> &wt,
      vector<vector<int>> &dp) {
  // base case
  if (ind == 0) {
    if (W >= wt[ind])
      return val[ind];
    else
      return 0;
  }

	if (dp[ind][W] != -1) return dp[ind][W];

  // take or notTake
  int notTake = f(ind - 1, W, val, wt, dp);
  int take = INT_MIN;
  if (W >= wt[ind])
    take = val[ind] + f(ind - 1, W - wt[ind], val, wt, dp);

  return dp[ind][W]=max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
  vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
  return f(n - 1, maxWeight, value, weight, dp);
}
// recursion without memoization would cause a TC of O(2^n), coz, every pair (ind, W) has to options - take or notTake
// TC of memoization is O(n*maxWeight) and SC is O(n*maxWeight) + O(n) (recursion stack space)
// recursion stack space is O(n), coz, at a strech, the call can maxium go n to 0 i.e., f(n, W) to f(0, W)



// tabulation - 2 changing parameters - 2 outer nested loops
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
  vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

	for (int W=weight[0]; W<= maxWeight; W++)dp[0][W] = value[0];

	for (int ind=1; ind<n; ind++){
		for (int W=0; W<=maxWeight; W++){
			int notTake = dp[ind-1][W];
  			int take = INT_MIN;
			if (W >= weight[ind])
				take = value[ind] + dp[ind-1][W-weight[ind]];

  			dp[ind][W]=max(take, notTake);
		}
	}

	return dp[n-1][maxWeight];
}
// TC = O(n*maxWeight)
// SC = O(n*maxWeight)


// space optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
  	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

	for (int W=weight[0]; W<= maxWeight; W++)prev[W] = value[0];

	for (int ind=1; ind<n; ind++){
		for (int W=0; W<=maxWeight; W++){
			int notTake = prev[W];
  			int take = INT_MIN;
			if (W >= weight[ind])
				take = value[ind] + prev[W-weight[ind]];

  			curr[W]=max(take, notTake);
		}
		prev = curr;
	}

	return prev[maxWeight];
}
// TC = O(n*maxWeight)
// SC = O(maxWeight) + O(maxWeight) 



// space optimization to a single array
// an observation from the above space optimization is that
// when we try to update the curr row, we need the values from prev row
// more specifically, when we try to udpate the value of W index of curr (curr[W]),
// we actually need the values of indeces from 0 to W of prev (prev[0] to prev[W]).
// the values of prev[W+1] to prev[maxWeight] are not required to update the curr.
// so, if we can use those indeces (W+1 to maxWeight) of prev, to avoid using curr array.
// so, to do that, we need to run the inner nested loop like this - for (int W=maxWeight; W>=0; W--){}
// it will not affect the current results, as to compute the value of a index of current row, we just need the information from prev row
// thus, space optimization can be done to a single array

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
  	vector<int> prev(maxWeight+1, 0);

	for (int W=weight[0]; W<= maxWeight; W++)prev[W] = value[0];

	for (int ind=1; ind<n; ind++){
		for (int W=maxWeight; W>=0; W--){
			int notTake = prev[W];
  			int take = INT_MIN;
			if (W >= weight[ind])
				take = value[ind] + prev[W-weight[ind]];

  			prev[W]=max(take, notTake);
		}
	}

	return prev[maxWeight];
}
// TC = O(n*maxWeight)
// SC = O(maxWeight)