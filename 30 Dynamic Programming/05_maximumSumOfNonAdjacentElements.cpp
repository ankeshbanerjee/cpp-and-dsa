// memoization approach
#include <bits/stdc++.h> 
using namespace std;

int f(int ind, vector <int> &nums, vector<int> &dp){
    // base case
    if (ind == 0)return nums[ind];
    
    if (dp[ind] != -1)return dp[ind];
    // take = nums[ind] + f(ind-2) =>taking the current index into the sum
    int take = nums[ind];
    if (ind >= 2) take += f(ind-2, nums, dp); // handling the edge case
    // not taking the current index into the sum
    int doNotTake = f(ind-1, nums, dp);

    return dp[ind] = max(take, doNotTake);
}
// or, 
// int f(int ind, vector <int> &nums, vector<int> &dp){
//     // base case
//     if (ind == 0)return nums[ind];
//     if (ind < 0)return 0;

//     if (dp[ind] != -1)return dp[ind];
//     int take = nums[ind] + f(ind-2, nums, dp);
//     int doNotTake = f(ind-1, nums, dp);

//     return dp[ind] = max(take, doNotTake);
// }
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    // f(i) denotes the maximum sum from index (0 to i-1)
    // f(n-1) will denote the maximum sum from (0 - n-1) index 
    return f(n-1, nums, dp);
}

// Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    for (int i=1; i<n; i++){
        int take = nums[i];
        if (i>1) take += dp[i-2];
        int doNotTake = dp[i-1];
        dp[i] = max(take, doNotTake);
    }
    return dp[n-1];
}

// space optimization
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0], prev2 = 0;
    for (int i=1; i<n; i++){
        int take = nums[i] + prev2;
        int doNotTake = prev;
        int curr = max(take, doNotTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}