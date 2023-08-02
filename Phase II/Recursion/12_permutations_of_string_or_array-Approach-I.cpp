#include <bits/stdc++.h>
using namespace std;

// in this approach we will use an extra space (freq)
// this will be used to mark the element which is taken into the ds, in the current call
// so, that the marked element is not taken in further calls

// intuition is - to go to each element, take that into ds, and mark that

class Solution {
    // using extra space
private:
    void findPermutations(vector<int> &ds, vector<int> &freq, vector<vector<int>> &ans, vector<int> &nums){
        // base case
        if (ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for (int i=0; i<nums.size(); i++){
            if (freq[i] == 1) continue;
            ds.push_back(nums[i]);
            freq[i] = 1;
            findPermutations(ds, freq, ans, nums);
            freq[i] = 0;
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        vector<vector<int>> ans;
        findPermutations(ds, freq, ans, nums);
        return ans;
    }
};

// time complexity -
// O(n!) (to generate all the permutations) * O(n) (for the loop running inside the function, OR, you can say this is the time taken to insert the 'ds' into 'ans')
// so, time complexity = O(n! * n)

// space complexity -
// O(n) (for ds) + O(n) (for freq) (without considering the auxiliary stack space (O(n)) and space required for 'ans' (O(n!*n)))