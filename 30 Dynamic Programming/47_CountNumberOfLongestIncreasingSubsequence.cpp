#include <bits/stdc++.h>
using namespace std;

// modification in code of LIS
// count[i] stores the no.s of LISs which ends at index i
// whenever dp[ind] < 1+ dp[prev], i.e., whenever dp[ind] gets updated, set count[ind] = count[prev]
// coz, whenever the current element (nums[ind]) gets added to the subsequences of 'prev' index, 
// then the count of LISs which ends at 'ind', becomes count[prev]
// now, if the current element (nums[ind]) encounters another subsequence of same length (dp[ind] == 1 + dp[prev])
// then the count of LISs which end at 'ind', gets increased by count[prev] (count[ind] += count[prev])
// finally, the length of LIS is stored in maxi
// Now, add all the counts of LISs whose length is = maxi

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, 1), count (n, 1);

        int maxi = INT_MIN;
        for (int ind=0; ind<n; ind++){
            for (int prev = 0; prev < ind; prev++){
                if (nums[ind] > nums[prev] && dp[ind] < 1+dp[prev]){
                    dp[ind] = 1+dp[prev];
                    count[ind] = count[prev];
                }
                else if (nums[ind] > nums[prev] && dp[ind] == 1 + dp[prev]){
                    count[ind] += count[prev];
                }
            }
            maxi = max (maxi, dp[ind]);
        }

        int ans = 0;
        for (int i=0; i<n; i++){
            if (dp[i] == maxi) ans += count[i];
        }

        return ans;
    }
};