#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution {
private:
    int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        //base case
        if (i==0 && j==0) return grid[i][j];

        if (dp[i][j] != -1)return dp[i][j];
        int up, left;
        up = left = INT_MAX;
        if (i>0) up = grid[i][j] + f(i-1, j, dp, grid);
        if (j>0) left = grid[i][j] + f(i, j-1, dp, grid);
        return dp[i][j] = min (up, left);
    }
    // or,
    // int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
    //     //base case
    //     if (i==0 && j==0) return grid[i][j];
    //     if (i<0 || j<0)return (int)(1e9);    // this can't be reached so store a huge value that can't be reached

    //     if (dp[i][j] != -1)return dp[i][j];
    //     int up = grid[i][j] + f(i-1, j, dp, grid);
    //     int left = grid[i][j] + f(i, j-1, dp, grid);
    //     return dp[i][j] = min (up, left);
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, -1));
        return f(m-1, n-1, dp, grid);
    }
};
// TC = O(m*n) 
// SC = O(path length) + dp array space = O((m-1) + (n-1)) + O(m*n)


// tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int up, left;
                    up = left = 1e9;
                    if (i>0) up = grid[i][j] + dp[i-1][j];
                    if (j>0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min (up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// TC = O(m*n)
// SC = O(m*n)


// space optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev (n, 0);
        for (int i=0; i<m; i++){
            vector<int> curr (n, 0);
            for (int j=0; j<n; j++){
                if (i==0 && j==0) curr[j] = grid[i][j];
                else{
                    int up, left;
                    up = left = 1e9;
                    if (i>0) up = grid[i][j] + prev[j];
                    if (j>0) left = grid[i][j] + curr[j-1];
                    curr[j] = min (up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
// TC = O(m*n)
// SC = O(n)