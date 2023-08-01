#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombinations(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates,   
    int n){
        // base case
        if (target == 0){   // if you don't want to add too many conditions, avoid this base case, only keep the below one(general base case)
            ans.push_back(ds);
            return;
        }
        if (ind == n){
            if (target == 0) ans.push_back(ds);
            return;
        }

        // not pick
        findCombinations(ind+1, target, ds, ans, candidates, n);

        // pick
        if (target>=candidates[ind]){
            ds.push_back(candidates[ind]);
            findCombinations(ind, target-candidates[ind], ds, ans, candidates, n);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        int n = candidates.size();
        findCombinations(0, target, ds, ans, candidates, n);
        return ans;
    }
};

// if there was not infinite supply of elements, the time complexity would have been O(2^n)
// but, this is a problem of infinite supply, where we decide to stand at the same index
// so, here time complexity would be different.
// now, let the target is t.
// in worst case, the target will reduce by 1 in each recursion call.
// and when the t becomes 0, we return the call.
// so, recursion calls will be from t to 0, in worst case,
// and in each call there are 2 options - pick or not pick
// so, 2*2*2*...t times = 2^t
// and, adding the ds into the ans, is not a constant operation. so, let this operation requires k time.
// so time complexity will be at max -> O(2^t * k)
// is time complexity is asked, then simply tell it to be EXPONENTIAL. If further explanation is asked, then only tell the above explanation.

// space complexity can't be told exactly
// it will entirely depend on the number of combinations we are having.
// hypothetically, if the average length is K and there are x combinations.
// then, the space complexity will be O(K*x)
// again, it is totally hypothetical