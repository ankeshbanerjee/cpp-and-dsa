#include <bits/stdc++.h>
using namespace std;

// approach : 
// let s be a string
// if we reverse the string, then the palindromic subsequence will remain the same
// because a string is palindromic if it remains the same even after getting reversed
// so, the portion of the string, which is palindromic (palindromic subsequence),
// will remain the same, even after reversing the string.
// and that will be nothing but the longest common subsequence of s and rev(s)
// coz, let s contains a palindromic subsequence, 
// upon reversing, the subsequence will remain same as that is palindromic
// so, the longest same common part of s and rev(s) is the longest palindromic subsequence of s
// so, lcs(s, rev(s)) = longest palindromic subsequence

// in short -
// what does palindrome mean? -> reverse is same
// so, if some portion of the string is palindromic
// when you write that string in reverse, that portion should remain the same.
// so, if some portion of s and rev(s) is matching, i.e., a common subsequence of s and rev(s)
// is palindromic subsequence

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
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};