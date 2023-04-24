#include <bits/stdc++.h> 
using namespace std;

// memoization
int f (int ind, vector<int> &heights, vector<int> &dp){
    // base case
    if (ind==0)return 0;

    if (dp[ind] != -1) return dp[ind];

    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if (ind>1) right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    return dp[ind] = min(left, right);
} 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector <int> dp(n+1, -1);
    return f(n-1, heights, dp);
}

// tabulation : this can be done by observing the recursion solution
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector <int> dp (n, -1);
    // look at the base cases and assign their values in the dp array accordingly
    dp[0] = 0;

    // just replace f(n-1) and f(n-2) of recurrence relation with dp[n-1] and dp[n-2]
    for (int i=1; i<=n-1; i++){
        int firstStep = dp[i-1] + abs(heights[i]-heights[i-1]);
        int secondStep = INT_MAX;
        if (i>1){
            secondStep = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(firstStep, secondStep);
    }

    return dp[n-1];
}

// space optimization : whenever there is ind-1 or ind-2 types of stuffs, then there must be space optimization
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev = 0;
    int prev2 = 0;
    for (int i=1; i<n; i++){
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if (i>1){
            ss = prev2 + abs(heights[i]-heights[i-2]);
        }
        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}