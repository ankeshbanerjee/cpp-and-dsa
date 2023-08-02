#include <bits/stdc++.h>
using namespace std;

// intuition behind swaping -
// this makes sure that every element can come at every index
// draw recursion tree to get and give explanation

class Solution {
private:
    void findPermutations(int ind, vector<int> &nums, vector<vector<int>> &ans){
        // base case
        if (ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for (int i=ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]);
            findPermutations(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutations(0, nums, ans);
        return ans;
    }
};

// time complexity -
// O(n!) (to generate all the permutations) * O(n) (for the loop running inside the function, OR, you can say this is the time taken to insert the 'ds' into 'ans')
// so, time complexity = O(n! * n)

// space complexity -
// O(n!*n) (for ans vector) + O(n) (auxiliary stack space)