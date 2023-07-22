#include <bits/stdc++.h>
using namespace std;

// intuition : 
// traverse through the array
// generate all the increasing subsequences
// return the length of the longest one

// binary search approach :
// as generating all the subseqeunces become hectic and takes a lot of time
// so, instead of generating new subsequences, replace the elements in the same temp array
// to get the position, where to replace the new element. use lower_bound function
// int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
// lower_bound returns the ind such that -
// temp[ind] == nums[i] or temp[ind] > nums[i] (just greater element of nums[i])
// ultimately, temp.size() is the length of longest increasing subseqeunce
// but, it is noteworthy that temp is not the longest increasing subsequence
// this method is used to get the length of longest increasing subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> temp;
        temp.push_back(nums[0]);
        int len = 1;

        for (int i=1; i<n; i++){
            if (nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return len;
    }
};

// TC = O(nlog(n))
// SC = O(n)