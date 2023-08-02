#include <bits/stdc++.h>
using namespace std;

// brute force approach involves the similar code as combination sum I
// and to avoid duplicates, set data structure can be used
// this will give TLE

class Solution {
private:
    void findCombinations(int ind, int target, vector<int> &ds, set<vector<int>> &ans, vector<int> &candidates, int n){
        // base case
        if (target == 0){
            ans.insert(ds);
            return;
        }
        if (ind == n){
            if (target == 0) {
                ans.insert(ds);
            }
            return;
        }

        // not pick
        findCombinations(ind+1, target, ds, ans, candidates, n);

        // pick
        if (target>=candidates[ind]){
            ds.push_back(candidates[ind]);
            findCombinations(ind+1, target-candidates[ind], ds, ans, candidates, n);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int>ds;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        findCombinations(0, target, ds, ans, candidates, n);
        vector<vector<int>> finalAns;
        for (auto it : ans){
            finalAns.push_back(it);
        }
        return finalAns;
    }
};

// time complexity - O(2^n * klogn), extra logn factor for using set
// space complexity - O(k*x), where k is the average length of a subsequence, and x is the no. of subsequences
// remember, here space complexity O(k*x), is calculated without considering the auxiliary stack space


// opitimised approach
// question asks to return sorted subsequences, so initially sort the array
// run a loop, and check which element from ind to n-1, can be taken as the current element of the subsequence
// i.e., in the very first function call, I am iterating and checking which can be my 0th element of the subsequences
// in the next call, I will check, which can be the 1st element of the subsequences...... this will go on.
// as the array is sorted, take the advantage of that to avoid taking duplicates


// note : if (i>ind && candidates[i] == candidates[i-1]) continue;
// why i>ind is done?
// i goes from ind to n-1
// so, if you are at the starting index (i=ind)
// you don't need to check for duplicates, as this is the first time you are picking up the element
// but for i>ind, you have to check for duplicates.

// note : findCombinations(i+1, target-candidates[i], ds, ans, candidates, n); <- recursion call
// doing i+1, not ind+1, coz, the subsets have to be sorted, so if we have picked an element as the current element of the subsequence, 
// for the next elements of the subsequence, we will obviously check in the right part of the current element. 
// (coz, the array is sorted, so, elements in the left of the current element are shorter than the current element)

// e.g., let -
// 1    1   2   2   5
// ind      i
// I have taken the current element of the subsequence as 2 (arr[2]);
// so, i is at 2 and let the ind is at 0
// now to get the next elements of the subsequence, we have to go to right of the i, i.e., f(i+1)
// if we do f(ind+1), then the left part of 2 will be considered for the further functions calls, and the left part of 2 contains 1, which is less than 2
// so, sorted pattern for the subsequences will not be maintained


class Solution {
private:
    void findCombinations (int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates, int n){
        // base case
        if (target == 0){
            ans.push_back(ds);
            return;
        }

        for (int i=ind; i<n; i++){
            if (i>ind && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            ds.push_back(candidates[i]);
            findCombinations(i+1, target-candidates[i], ds, ans, candidates, n); 
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        findCombinations(0, target, ds, ans, candidates, n);
        return ans;
    }
};

// time complexity - O(2^n*k), as in worst case, each element would be unique, so 2^n subsets will be formed,
// and the time needed to add the subsequence of length k to the ans is k.
// space complexity - O(k*x), without considering the auxiliary space


// all the array problems, which involve recursion, can be solved using either of these two methods -
// 1. pick or not pick (combination sum I)
// 2. the approach used here (looping through all the elements (combination sum II)