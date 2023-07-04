// subsequence => contiguous or non-contiguous part of an array, where the elements follows the relative ordering
// subset might or might not follow the relative ordering
// [1, 2, 3, 4] => (1, 2) is a subsequence but (2, 1) is not becuase it doesn't follow the relative ordering

// thumb rule of dp regarding subsequences -
// express the problem in two parameters - (ind, target)
// explore all the possibilites on that index - take or notTake (all the dp on subsequences will be based on this 'take' and 'notTake' approach)
// return ans

// in this problem f(ind, target) means considering the array from index [0 to ind]
// i.e., in the entire array till index 'ind', does 'target' exists or not

#include <bits/stdc++.h> 
using namespace std;

// memoization
bool f (int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    // base case
    // target is achieved, i.e., target is no more
    if (target==0)return true;
    if (ind==0) return arr[0] == target;

    if (dp[ind][target] != -1) return dp[ind][target];

    // the possibilities are not take or take
    bool notTake = f(ind-1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = take || notTake;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}
// recursion without memoization would cause a TC of O(2^n), coz, every pair (ind, target) has to options - take or notTake
// TC of memoization is O(n*k) and SC is O(n*k) + O(n) (recursion stack space)
// recursion stack space is O(n), coz, at a strech, the call can maxium go n to 0 i.e., f(n, taget) to f(0, target)


// tabulation - 2 changing parameters (ind, target) - 2 outer loops
bool subsetSumToK(int n, int k, vector<int> &arr) {
  // Write your code here.
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  for (int ind=0; ind < n; ind++) dp[ind][0] = true;
  if(arr[0] <= k) dp[0][arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= k; target++) {
      bool notTake =dp[ind - 1][target];
      bool take = false;
      if (arr[ind] <= target)
        take = dp[ind - 1][target - arr[ind]];
        dp[ind][target] = take || notTake;
    }
  }

  return dp[n-1][k];
}
// TC = O(n*k), SC = O(n*k)


// space optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
  // Write your code here.
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

  return prev[k];
}
// TC = O(n*k)
// SC = O(k)