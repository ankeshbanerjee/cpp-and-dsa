#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution {
private:
    int f (int row, int col, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid){
        // base case
        if (row == 0 && col == 0 && obstacleGrid[row][col] != 1)return 1;
        if (obstacleGrid[row][col] == 1)return 0;

        if (dp[row][col] != -1)return dp[row][col];
        int up = 0, left = 0;
        if (row > 0) up = f(row-1, col, dp, obstacleGrid);
        if (col > 0) left = f(row, col-1, dp, obstacleGrid);
        return dp[row][col] = up + left;        
    }
    // or, 
    // int f (int row, int col, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid){
    //     // base case
    //     if (row == 0 && col == 0 && obstacleGrid[row][col] != 1)return 1;
    //     if (row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)return 0;
    //     if (row <0 || col < 0) return 0;

    //     if (dp[row][col] != -1)return dp[row][col];
    //     int up = f(row-1, col, dp, obstacleGrid);
    //     int left = f(row, col-1, dp, obstacleGrid);
    //     return dp[row][col] = up + left;        
    // }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, -1));
        return f(m-1, n-1, dp, obstacleGrid);
    }
};

// tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i==0 && j==0 && obstacleGrid[i][j] != 1)dp[i][j] = 1;
                else if (obstacleGrid[i][j] == 1)dp[i][j] = 0;
                else{
                    int up = 0, left = 0;
                    if (i>0) up = dp[i-1][j];
                    if (j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev (n, 0);
        for (int i=0; i<m; i++){
            vector<int> curr (n, 0);
            for (int j=0; j<n; j++){
                if (i==0 && j==0 && obstacleGrid[i][j] != 1)curr[j] = 1;
                else if (obstacleGrid[i][j] == 1)curr[j] = 0;
                else{
                    int up = 0, left = 0;
                    if (i>0) up = prev[j];
                    if (j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};