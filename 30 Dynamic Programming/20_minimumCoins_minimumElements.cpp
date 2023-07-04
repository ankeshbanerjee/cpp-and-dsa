#include <bits/stdc++.h> 
using namespace std;

// this is a dp problem on infinite supplies, and a problem of dp on subsequences
// things are very much similar to that of take and notTake approach, with a slight modification due to infinite supply of coins
// whenever there is problem like - 'infinite supply' or 'multiple use',
// when you consider 'take', stand at the same index, with reducing the value of target.
// and the rule of writing base case in subsequence problems is -
// go to the last index (here index 0)
// then consider an array containing a single element and consider a possible target

int f(int ind, int target, vector<int> &nums, vector <vector<int>> &dp){
    // base case
    if (ind == 0){
        if (target % nums[0] == 0) return target/nums[0];
        else return 1e9;    // not returning 0, coz the count will not be 0 in this case, rather it will not be possible to have a count, so return a larget value
    }

    if (dp[ind][target] != -1)return dp[ind][target];
    // take or notTake
    int notTake = 0 + f(ind-1, target, nums, dp);
    int take = INT_MAX;
    if (nums[ind] <= target) take = 1 + f(ind, target-nums[ind], nums, dp);

    return dp[ind][target] = min(take, notTake);
}
int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    vector <vector<int>> dp (n, vector<int>(x+1, -1));
    int ans = f(n-1, x, nums, dp);
    if (ans >= 1e9)return -1;
    return ans;
}

// the recursive soln. will have TC >> O(2^n), coz, we are standing at the same ind, so tell the TC to be EXPONENTIAL 
// and SC is also >> O(n)
// assume, target will reduce at least by 1, in each call, so SC can be at max O(target)
// though, memoization will have a TC = O(n*target)
// and SC = O(n*target) + O(target) (recursion stack space)


// tabulation
int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    vector <vector<int>> dp (n, vector<int>(x+1, 0));
    // target can be of any value between 0 to x
    for (int target = 0; target <=x; target++){
        if (target % nums[0] == 0) dp[0][target] = target/nums[0];
        else dp[0][target] = 1e9;
    }

    for (int ind=1; ind<n; ind++){
        for (int target=0; target<=x; target++){
            int notTake = 0 + dp[ind-1][target];
            int take = INT_MAX;
            if (nums[ind] <= target) take = 1 + dp[ind][target-nums[ind]];

            dp[ind][target] = min(take, notTake);
        }
    }
    int ans = dp[n-1][x];
    if (ans >= 1e9)return -1;
    return ans;
}

// TC = O(n*target)
// SC = O(n*target)
// sometimes, it may happen that tabulation might give TLE, whereas memoization doesn't
// it can happen coz, the test cases might be set up in such a way that, the memoization code may not have to run for less than (n*target) times
// but, tabulation runs exactly for (n*target) times,
// in such cases go for space optimization


// space optimization
#include <bits/stdc++.h> 
int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    vector<int>prev(x+1, 0), curr(x+1, 0);
    // target can be of any value between 0 to x
    for (int target = 0; target <=x; target++){
        if (target % nums[0] == 0) prev[target] = target/nums[0];
        else prev[target] = 1e9;
    }

    for (int ind=1; ind<n; ind++){
        for (int target=0; target<=x; target++){
            int notTake = 0 + prev[target];
            int take = INT_MAX;
            if (nums[ind] <= target) take = 1 + curr[target-nums[ind]];

            curr[target] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[x];
    if (ans >= 1e9)return -1;
    return ans;
}

// TC = O(n*target)
// SC = O(target)
