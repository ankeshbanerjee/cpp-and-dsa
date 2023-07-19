#include <bits/stdc++.h>
using namespace std;


// minimum number of operations to make s1 to s2
// operations - insertion, deletion, replacement of any character
// the approach for solving any dp on string problem is match or notmatch
// match -> operation = 0, only shrink both the string by 1 (if (word1[i] == word2[j]) return dp[i][j] = 0 + f(i-1, j-1, word1, word2, dp);)
// not match -> then possible operations are insertion, deletion, replacement, try out all these ways then return the best(min) of them
// insertion = 1+f(i, j-1, word1, word2, dp), coz insertion will be done at the next index of i of s1, so, i will stay at the same place
// deletion = 1+f(i-1, j, word1, word2, dp), coz deletion will shrink only the s1
// replace = 1+f(i-1, j-1, word1, word2, dp), coz, s1[i] will be replaced by s2[j], so both will shrink

// base case ->
// if s1 gets exhausted first, then add all the remaining characters of s2, so no. of insertions = j+1 (if (i<0) return j+1;)
// if s2 gets exhausted first, then delete all the remaining characters of s1, so no. deletions = i+1 (if (j<0) return i+1;)

class Solution {
private:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        // base case
        if (i<0) return j+1;
        if (j<0) return i+1;

        if (dp[i][j] != -1)return dp[i][j];
        // match
        if (word1[i] == word2[j]) return dp[i][j] = 0 + f(i-1, j-1, word1, word2, dp);

        // not matched
        return dp[i][j] = min(1+f(i, j-1, word1, word2, dp), 
                min(1+f(i-1, j, word1, word2, dp), 1+f(i-1, j-1, word1, word2, dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp (n, vector<int>(m, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};
// recursion - TC = exponential (3^n * 3^m), SC = O(n+m)
// memoization - TC = O(n*M), SC =  O(n*M)+O(n+m)


// tabulation - shifting indeces for tabulation (1-based indexing)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0));

        for (int j=0; j<=m; j++)dp[0][j] = j;
        for (int i=0; i<=n; i++)dp[i][0] = i;

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                // match
                if (word1[i-1] == word2[j-1])dp[i][j] = dp[i-1][j-1];
                // not matched
                else dp[i][j] = min(1+dp[i][j-1], 
                        min(1+dp[i-1][j], 1+dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};
// TC = O(n*M), SC =  O(n*M)


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>prev(m+1, 0), curr(m+1, 0);

        for (int j=0; j<=m; j++)prev[j] = j;

        for (int i=1; i<=n; i++){
            curr[0] = i;
            for (int j=1; j<=m; j++){
                // match
                if (word1[i-1] == word2[j-1])curr[j] = prev[j-1];
                // not matched
                else curr[j] = min(1+curr[j-1], 
                        min(1+prev[j], 1+prev[j-1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};
// TC = O(n*M), SC =  O(2M)

// space optimization to 1-d array is not possible coz, both prev[j-1] and curr[j-1] is needed
