#include <bits/stdc++.h>
using namespace std;

// brute force approach will be -
// generate all subsets, then use a set to avoid duplicates
// time complexity = O(2^n) (to generate all subsets) * O(mlog(m)) (to insert a subset into the set, let the average size of subsets is m) = O(2^n * mlog(m))
// this will give TLE


// optimised approach - recursion -
// similar approach as combination sum II
// in short,
// 0th level recursion call generates empty subset
// 1st level recursion call generates all subsets of size 1
// 2nd level generates all subsets of size 2
// ........

class Solution {
private:
    void findSubsets(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int n){
        ans.push_back(ds);
        for (int i=ind; i<n; i++){
            if (i>ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1, ds, ans, nums, n);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort (nums.begin(), nums.end());
        int n = nums.size();
        findSubsets(0, ds, ans, nums, n);
        return ans;
    }
};

// time complexity = O(2^n)(to generate all 2^n subsequences) * O(k) (to push the subsequence into the ans, where the average size of subsets is k) = O(2^n * k)
// space complexity = size of ans vector + auxiliary stack space
//                  = O(2^n * k) (size of each subset is k and there are 2^n subsets) + O(n)