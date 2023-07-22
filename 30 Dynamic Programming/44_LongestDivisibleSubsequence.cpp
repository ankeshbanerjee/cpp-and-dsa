#include <bits/stdc++.h>
using namespace std;


// entire code is same as printing longest increasing subsqeuence
// 2 things are modified-
// 1. the nums array is sorted (coz subset is needed, so relative ordering doesn't matter)
// by sorting, we have to only check the divisibility for the last index
// e.g., let a subset be [1, 4, 8], when 16 is getting checked to get added, only its divisibility with 8 is needed to be checked.
// by sorting it is ensured that, if it is divisible by 8, then it will be divisible by all the other elements
// coz, 8 is divisible by 4 and 1. so, 16 will also be divisible by them
// 2. the check condition is changed (nums[ind] % nums[prev] == 0)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <int> dp(n, 1), hash(n, 0);

        int maxi = INT_MIN;
        int lastIndex = -1;

        // O(n^2)
        for (int ind=0; ind<n; ind++){
            hash[ind] = ind;
            for (int prev = 0; prev < ind; prev++){
                if (nums[ind] % nums[prev] == 0 && 1+dp[prev] > dp[ind]){
                    dp[ind] = 1+dp[prev];
                    hash[ind] = prev;
                }
            }
            if (maxi < dp[ind]){
                maxi = dp[ind];
                lastIndex = ind;
            }
        }

        vector <int> ans;
        // O(n)
        while (hash[lastIndex] != lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
