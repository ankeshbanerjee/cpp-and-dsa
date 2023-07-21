#include <bits/stdc++.h>
using namespace std;

// see lecture dp-42
// Longest increasing subsequence is stored in 'ans' vector

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, 1), hash(n, 0);

        int maxi = INT_MIN;
        int lastIndex = -1;
        for (int ind=0; ind<n; ind++){
            hash[ind] = ind;
            for (int prev = 0; prev < ind; prev++){
                if (nums[ind] > nums[prev] && 1+dp[prev] > dp[ind]){
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
        while (hash[lastIndex] != lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(), ans.end());
        for (auto it : ans) cout << it << " ";
        return maxi;
    }
};