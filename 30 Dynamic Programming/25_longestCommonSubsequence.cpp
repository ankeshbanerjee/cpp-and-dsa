#include <bits/stdc++.h>
using namespace std;

// starting with dp on strings
// common pattern for dp on strings - match and not match
// match -> if text1[i] and text2[j] matches, take that char into the result, and call f(i-1, j-1)

// else if notMatch -> if (text1[i] != text2[j]) two calls will be there -
// f(i-1, j) and f(i, j-1)
// return the max of them

class Solution {
private:
    int f (int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        // base case
        if (i<0 || j<0){
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        //match
        if (text1[i] == text2[j]) return dp[i][j] = 1+f(i-1, j-1, text1, text2, dp);

        // not match
        return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, text1, text2, dp);
    }
};
// no. of subsequences of text1 = 2^n, text2 = 2^m, so, TC of recursion = O(2^n * 2^m) ; SC = O(n+m) (coz at max, the call can go upto n+m level)
// memoization : TC = O(n*m); SC = o(n*m) + O(n+m)

// tabulation
// as negative index can't be possible for tabulation, so index shifting is been done
// i.e., n means n-1, m means m-1, i means i-1, and 0 means -1
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // index=0 will work as index=-1
        for (int i=0; i<=n; i++) dp[i][0] = 0;
        for (int i=0; i<=m; i++) dp[0][i] = 0;

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                //match
                if (text1[i-1] == text2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                // not match
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }   
};
// TC = O(n*m); SC = o(n*m)


// space optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int>prev(m+1, 0), curr(m+1, 0);
       
       // index=0 will work as index=-1
        for (int j=0; j<=m; j++) prev[j] = 0;

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
};

//TC = O(n*m); SC = o(m)