#include <bits/stdc++.h>
using namespace std;


// dp on strings - match or not match with some modifications
// '?' - matches any single character
// '*' - matches any sequence of length 0 or more
// solution :->
// if matched -> 
// shrink both the strings by 1 (if (p[i] == s[j] || p[i] == '?') return dp[i][j] = f(i-1, j-1, p, s, dp);)
// now, complexity arises when we encounter '*'
// to deal with '*', we can think of two possibilities
// 1. consider '*' as empty sequence -> then p string will shrink by 1 (to let '*' go out of consideration)
// and s string will remain the same (f(i-1, j, p, s, dp))
// 2. take the s[j] into the sequence of '*', then s string will shrink by 1, and p string will stand at the same index
// f(i, j-1, p, s, dp)
// to try out both the ways we will return 'OR' of the above two cases (if(p[i] == '*') return dp[i][j] = f(i-1, j, p, s, dp) | f(i, j-1, p, s, dp);)
// Now one case remains -> that is Not match, if not matched then simply return false;

class Solution {
private:
    bool f(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        // base case
        if (i<0 && j<0) return true;
        if (i<0 && j>=0) return false;
        if (j<0){
            for (int ii=0; ii<=i; ii++){
                if (p[ii] != '*')return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];
        // match
        if (p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = f(i-1, j-1, p, s, dp);
        }

        if(p[i] == '*'){
            return dp[i][j] = f(i-1, j, p, s, dp) | f(i, j-1, p, s, dp);
        }

        // not match
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, p, s, dp);
    }
};
// recursion -> TC = O(2^N * 2^M); SC = O(N+M)
// memoization -> TC = O(N*M); SC = O(N*M) + O(N+M)


// tabulation - shifting indeces to avoid negative index
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for (int j=1; j<=m; j++)dp[0][j] = false;
        for (int i=1; i<=n; i++){
            bool flag = true;
            for (int ii=1; ii<=i; ii++){
                if (p[ii-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                // not match
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};
// TC = O(N*M); SC = O(N*M)


// space optimization - slightly tricky
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<bool>prev(m+1, false), curr(m+1, false);
        prev[0] = true;
        for (int j=1; j<=m; j++)prev[j] = false;

        for (int i=1; i<=n; i++){
            // the curr[0] has to be set in each row
            bool flag = true;
            for (int ii=1; ii<=i; ii++){
                if (p[ii-1] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for (int j=1; j<=m; j++){
                if (p[i-1] == s[j-1] || p[i-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[i-1] == '*'){
                    curr[j] = prev[j] | curr[j-1];
                }
                // not match
                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};
// TC = O(N*M); SC = O(M)