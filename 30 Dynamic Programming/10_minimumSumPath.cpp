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