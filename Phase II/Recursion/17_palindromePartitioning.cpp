#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome (int start, int end, string &s){
        while (start<end){
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void findPartitions(int ind, string &s, vector<string> &partition, vector<vector<string>> &ans){
        // base case
        if (ind == s.size()){
            ans.push_back(partition);
            return;
        }

        for (int i=ind; i<s.size(); i++){
            if (isPalindrome(ind, i, s)){
                partition.push_back(s.substr(ind, i-ind+1));
                findPartitions(i+1, s, partition, ans);
                partition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        findPartitions(0, s, partition, ans);
        return ans;
    }
};