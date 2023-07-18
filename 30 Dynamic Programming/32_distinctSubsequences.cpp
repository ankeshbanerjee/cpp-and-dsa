#include <bits/stdc++.h>
using namespace std;

// rules to write recurrence of problems like count all the ways
// base case will return 0 or 1
// return the summation of all the possibilites (f()+f()+f()+...)

// two cases are possbile
// if(s[i] == t[j]), then - two cases would be possible
// 1. taking the character in the first string into consideration, then both string will shrink (f(i-1, j-1))
// 2. not taking the character in the first string into consideration, then the first string will shrink, the second will remain the same (f(i-1, j))
// else, not matched => find for subsequences in the rest part of the first string (f(i-1, j))

class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        // base case
        if(j < 0) return 1;
        if (i < 0) return 0;

        if(dp[i][j] != -1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        }

        return dp[i][j] = f(i-1, j, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};
// recursion - TC = Exponential (2^n * 2^m), SC = O(n+m)
// memoization = TC = O(N*M), SC = O(N*M) + O(N+M)

// tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // dp array of type double to avoid runtime error
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

        for (int i=0; i<=n; i++)dp[i][0] = 1;
        for (int j=1; j<=m; j++)dp[0][j] = 0;
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return (int)dp[n][m];
    }
};
// TC = O(N*M), SC = O(N*M)


// space optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double>prev(m+1, 0), curr(m+1, 0);

        prev[0] = 1;
        
        for (int i=1; i<=n; i++){
            curr[0] = 1;
            for (int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else curr[j] = prev[j];
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};
// TC = O(N*M), SC = O(2M)


// single array space optimization - 
// similar to as that of 01 knapsack
// to calculate curr[j], we need prev[j] and prev[j-1]
// the values of prev, beyond j, are not needed to calculate curr[j]
// so, we can utilize those to store the current values, instead of using another seperate curr array
// to do this, we have to start the j loop from right side
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double>dp(m+1, 0);
        dp[0] = 1;
        for (int i=1; i<=n; i++){
            dp[0] = 1;
            for (int j=m; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }

        return (int)dp[m];
    }
};