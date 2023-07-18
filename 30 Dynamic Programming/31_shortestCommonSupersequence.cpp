#include <bits/stdc++.h>
using namespace std;

// if the length of shortest common supersequence is asked
// that would be simple, first, find out the lcs_length
// then ans = s1.size() + s2.size() - lcs_length

// here we are going to print the shortest common supersequence
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // code for longest common subsequence with dp array
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // index=0 will work as index=-1
        for (int i=0; i<=n; i++) dp[i][0] = 0;
        for (int i=0; i<=m; i++) dp[0][i] = 0;

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                //match
                if (str1[i-1] == str2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                // not match
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // getting the shortest common supersequence
        // this portion of the code is simiilar as that of printing the Longest Common Subsequence
        // besides taking the lcs string, what we are doing extra here is -
        // storing the characters in the ans, which we are leaving behind, while backtracking.
        // i.e., storing the characters in the ans which are going out, while we move upwards/leftwards/diagonally while backtracking.
        // coz, we need the supersequence, which will contain all the characters of both the strings
        string ans = "";
        int i=n, j=m;
        while (i>0 && j>0){
            if (str1[i-1] == str2[j-1]){
                // character matched, common character will be taken only once (this character is part of lcs)
                ans += str1[i-1];
                i--, j--;
            }
            // characters not matched
            else if (dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }

        // as we have backtracked, so the ans we got is reversed
        // we have to reverse it again to get the actual ans
        reverse(ans.begin(), ans.end());
        return ans;
    }
};