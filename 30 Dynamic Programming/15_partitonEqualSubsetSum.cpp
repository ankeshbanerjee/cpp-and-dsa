#include <bits/stdc++.h>
using namespace std;

// if I have to split the array into two parts with equal sum, and the sum of all elements of the array is totalSum
// then the sum of each part has to be totalSum/2, so it is clear that if totalSum is odd
// then it will not be possible to split in two subsets having same sum, so return false;
// now, we have to check if a subset exists with subset sum equal to totalSum/2
// if exists, return true, coz, if one subset is having a sum of totalSum/2, 
// then the subset formed by remaining elements of the array will also have sum = totalSum/2

class Solution {
private:
    // space optimized solution of the problem - 'subset sum equal to K'
    bool subsetSumToK(int n, int k, vector<int> &arr) {
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
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i=0; i<n; i++)totalSum += nums[i];
        if (totalSum % 2) return false;

        return subsetSumToK(n, totalSum/2, nums); 
    }
};

// TC = O(n*k) + O(n)
// SC = O(k)