#include <bits/stdc++.h>
using namespace std;

// without memoization, TC = 2^(m*n), because, there are will be 2 calls for each node, and there are m*n cells in the grid, so, 2^(m*n)
// SC = O(path length) = O((m-1)+(n-1))

// memoization
class Solution {
private:
    int f (int i, int j, vector<vector<int>> &dp){
        // base case
        if (i==0 && j==0) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int up = 0, left = 0;
        if (i>0){
            up = f(i-1, j, dp);
        }
        if (j>0){
            left = f(i, j-1, dp);
        }
        return dp[i][j] = up + left;
    }
    // or,
    // int f (int i, int j, vector<vector<int>> &dp){
    //     // base case
    //     if (i==0 && j==0) return 1;
    //     if (i<0 || j<0) return 0;

    //     if (dp[i][j] != -1) return dp[i][j];
    //     int up = f(i-1, j, dp);
    //     int left = f(i, j-1, dp);
    //     return dp[i][j] = up + left;
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int> (n, -1));
        return f(m-1, n-1, dp);
    }
};
// TC = O(n*m) => because there are n*m different combinations, so, at max n*m calls
// SC = O((n-1)+(m-1)) + O(n*m)

// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i==0 && j==0)continue;
                int up = 0, left = 0;
                if (i>0){
                    up = dp[i-1][j];
                }
                if (j>0){
                    left = dp[i][j-1];
                }
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};
// TC = O(n*m), SC = O(n*m)


// space optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <int> prev (n, 0);
        for (int i=0; i<m; i++){
            vector <int> temp(n, 0);
            for (int j=0; j<n; j++){
                if (i==0 && j==0) temp[j] = 1;
                else{
                    int up = 0, left = 0;
                    if (i>0) up = prev[j];
                    if (j>0) left = temp[j-1];
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};
// TC = O(n*m)
// SC = O(n)