#include <bits/stdc++.h>
using namespace std;

// brute force approach -
// generate all the subsets, and calculate the sum of each of them
// this can be done by power set algorithm
// whose time complexity = O(2^n * n)


// optimised approach - using recursion (pick or not pick)

class Solution
{
private:
    void findSums(int ind, int sum, vector<int> &ans, vector<int> &arr, int n){
        // base case
        if (ind == n){
            ans.push_back(sum);
            return;
        }
        
        // not pick
        findSums(ind+1, sum, ans, arr, n);
        
        // pick
        findSums(ind+1, sum+arr[ind], ans, arr, n);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        findSums(0, 0, ans, arr, N);
        return ans;
    }
};

// time complexity -
// for each ind, we have 2 options, pick or not pick
// so, 2*2*2*...n times = 2^n
// and finally sorting the ans, which requires, 2^nlog(2^n)
// so, time complexity = O(2^n) + O(2^n*log(2^n))

// space complexity -
// O(2^n) + O(n)
// space required to store all the subsets (2^n) + auxiliary stack space (n)