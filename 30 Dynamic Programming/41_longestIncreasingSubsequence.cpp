#include <bits/stdc++.h>
using namespace std;


// based on same trick for dp on subsequences - take or not take
// changing parameters are - current index and previous index which was taken into subsequence
// initially prev_ind == -1, coz, for ind == 0, no prev_ind is there
// not take -> if not taken length of subsequence remains same, prev_ind remains same, ind becomes ind+1
// now we can take only if previously no element is taken (prev_ind == -1) or
// nums[ind] > nums[prev_ind]
// if taken, ind becomes ind+1, current current ind becomes prev_ind
// return the max of them
// note : as, -1 <= prev_ind <= n-1 (coz, ind can go to n (base case), so, prev_ind can go to n-1)
// so creating dp array of dp[n][n+1]
// and dp[ind][-1] is not possible, no shfiting co-ordinates by doing dp[ind][prev_ind+1]
// so, if prev_ind == -1, after shifting it becomes -1+1 = 0;
class Solution {
private:
    int f (int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp, int n){
        // base case
        if (ind == n) return 0;

        if (dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        // not take
        int notTake = 0 + f(ind+1, prev_ind, nums, dp, n);

        // take
        int take = INT_MIN;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]){
            take = 1 + f(ind+1, ind, nums, dp, n);
        }
        return dp[ind][prev_ind+1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return f(0, -1, nums, dp, n);
    }
};
// recursion -> TC = O(2^N), SC = O(N)
// memoization -> TC = O(N^2), SC = O(N^2) + O(N)


// tabulation -> small thing to notice-
// prev_ind means the previous indeces of current index
// so, prev_ind can lie between ind-1 to -1
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for (int ind=n-1; ind>=0; ind--){
            for (int prev_ind=ind-1; prev_ind>= -1; prev_ind--){
                // not take
                int notTake = 0 + dp[ind+1][prev_ind+1];
                // take
                int take = INT_MIN;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1] = max(notTake, take);
            }
        }

        return dp[0][-1+1];
    }
};
// TC = O(N^2), SC = O(N^2)


// space optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n+1, 0), curr(n+1, 0);
        
        for (int ind=n-1; ind>=0; ind--){
            for (int prev_ind=ind-1; prev_ind>= -1; prev_ind--){
                // not take
                int notTake = 0 + front[prev_ind+1];
                // take
                int take = INT_MIN;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    take = 1 + front[ind+1];
                }
                curr[prev_ind+1] = max(notTake, take);
            }
            front = curr;
        }

        return front[-1+1];
    }
};
// TC = O(N^2), SC = O(N)*2


// this method is required to print the Longest Increasing subsequence
// here, dp[i] means the length of longest increasing subsequence, upto index i
// see lecture dp-42
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, 1);

        int maxi = INT_MIN;
        for (int ind=0; ind<n; ind++){
            for (int prev = 0; prev < ind; prev++){
                if (nums[ind] > nums[prev]){
                    dp[ind] = max (dp[ind], 1+dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;
    }
};
// TC = O(N^2), SC = O(N)