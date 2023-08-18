#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string ans = "";
        vector<char> nums(n);
        for (int i=0; i<n; i++){
            fact = fact * (i+1);
            nums[i] = '1' + i;
        }
        k = k-1;
        // O(n)
        while (nums.size()){
            int setSize = fact/nums.size();
            int ind = k/setSize;
            ans += nums[ind];
            fact = fact/nums.size();
            k = k % fact;
            // O(n)
            nums.erase(nums.begin() + ind);
        }
        return ans;
    }
};

// time complexity = O(n) * O(n) = O(n^2)
// space complexity = O(n) (for nums) + O(n) (for ans)