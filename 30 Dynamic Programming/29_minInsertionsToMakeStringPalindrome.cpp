#include <bits/stdc++.h>
using namespace std;

// each string can be converted to a palindrome by insertions of some characters
// let a string be s. then, the string (s+rev(s)) is a palindrome
// so the maximum no. of insertions to make a string palindrome is s.size()
// to find the minimum number of insertions,
// first find out the longest portion you should not touch
// then only you can find the minimum number of insertions
// the intution is that you should first keep the longest palindromic subsequence intact.
// then you need to just insert the remaining characters in right postions
// so, the no. of insertions = s.size() - longestPalindromicSubsequence(s)

class Solution {
private:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int>prev(m+1, 0), curr(m+1, 0);

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                //match
                if (text1[i-1] == text2[j-1]) curr[j] = 1+ prev[j-1];
                // not match
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[m];
    }  
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
public:
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};