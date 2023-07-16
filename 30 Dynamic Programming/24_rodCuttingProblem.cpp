#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
	// base case
	if (ind == 0){
		// ind==0 means rodLength = 1,
		// so, no. of pieces of (rodlength=1) is N/1, so profit is N * price[0]
		return N*price[0];
	}

	if (dp[ind][N] != -1)return dp[ind][N];
	// take or notTake
	int notTake = 0 + f(ind-1, N, price, dp);
	int take = INT_MIN;
	int rodLength = ind+1;
	if (rodLength <= N)take = price[ind] + f(ind, N-rodLength, price, dp);

	return dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp (n, vector<int>(n+1, -1));
	return f(n-1, n, price, dp);
}

// only recursion would cost a exponential TC (>2^n), and max auxiliary stack space would be O(target)
// memoization TC = O(n*n+1), SC = O(n*n+1) + O(target)

// tabulation
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp (n, vector<int>(n+1, 0));
	for (int N=0; N<=n; N++)dp[0][N] = N*price[0];
	for (int ind=1; ind<n; ind++){
		for (int N=0; N<=n; N++){
			int notTake = 0 + dp[ind-1][N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if (rodLength <= N)take = price[ind] + dp[ind][N-rodLength];
			dp[ind][N] = max(take, notTake);
		}
	}
	return dp[n-1][n];
}
// TC = O(n*n+1), SC = O(n*n+1)

// space optimizaiton
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>prev(n+1, 0), curr(n+1, 0);
	for (int N=0; N<=n; N++)prev[N] = N*price[0];
	for (int ind=1; ind<n; ind++){
		for (int N=0; N<=n; N++){
			int notTake = 0 + prev[N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if (rodLength <= N)take = price[ind] + curr[N-rodLength];
			curr[N] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[n];
}


// space optimization to a single array (similar as previous problem - unbounded knapsack)
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>prev(n+1, 0);
	for (int N=0; N<=n; N++)prev[N] = N*price[0];
	for (int ind=1; ind<n; ind++){
		for (int N=0; N<=n; N++){
			int notTake = 0 + prev[N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if (rodLength <= N)take = price[ind] + prev[N-rodLength];
			prev[N] = max(take, notTake);
		}
	}
	return prev[n];
}

