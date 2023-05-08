#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f (int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        int row = grid.size();
        int col = grid[0].size();
        // base case
        if (j1 <0 || j1 >= col || j2<0 || j2>=col) return -1e8; // big negative value, so that it can never be considered, not taking INT_MIN, because addition of something -ve to INT_MIN, will cause overflow
        if (i == row-1){
            if (j1==j2)return dp[i][j1][j2] = grid[i][j1];
            else return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)return dp[i][j1][j2];

        // explore all the paths to get the maximum cherries
        int maxi = 0;
        for (int dj1 = -1; dj1<=1; dj1++){
            for (int dj2 = -1; dj2 <= 1; dj2++){
                int cherries = 0;
                if (j1==j2) cherries = grid[i][j1]; 
                else cherries = grid[i][j1] + grid[i][j2];
                cherries += f(i+1, j1+dj1, j2+dj2, grid, dp);
                maxi = max (maxi, cherries);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp (row, vector<vector<int>> (col, vector<int>(col, -1)));
        return f(0, 0, col-1, grid, dp);
    }
};

// recursive soln. TC = O(3^n * 3^n) = O(9^n) bcz, there are n rows, and in each row recursion will be called for 3*3 = 9 times,
// so, for n rows => 9*9*9*.....n times = O(9^n)
// SC = O(N)

// memoization : TC = O(N*M*M) * 9, bcz there are N*M*M combinations and for each combination, the loop will run for 3*3 = 9 times
// SC = dp array + recursive stack space = O(N*M*M) + O(N)


// tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int>(m, 0)));
        // base case
        for (int j1 = 0; j1<m; j1++){
            for (int j2=0; j2<m; j2++){
                if (j1==j2)dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // tabulation goes opposite of memoization, so i will go from n-2 to 0
        for (int i=n-2; i>=0; i--){
            // j can go in any dirn., as we are mainly concerned about i, i.e., j1 and j2 also could've gone from m-1 to 0
            for (int j1 = 0; j1<m; j1++){
                for (int j2=0; j2<m; j2++){
                    int maxi = 0;
                    for (int dj1 = -1; dj1<=1; dj1++){
                        for (int dj2 = -1; dj2 <= 1; dj2++){
                            int cherries = 0;
                            if (j1==j2) cherries = grid[i][j1]; 
                            else cherries = grid[i][j1] + grid[i][j2];
                            if (j1+dj1 < m && j1+dj1 >= 0 && j2+dj2 < m && j2+dj2 >= 0)
                                cherries += dp[i+1][j1+dj1][j2+dj2];
                            else cherries += -1e8;
                            maxi = max (maxi, cherries);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};


// space optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 1D optimized to two variables
        // 2D optimized to 1D array
        // 3D will be optimized to 2D array

        vector<vector<int>> front(m, vector<int> (m, 0)), curr (m, vector<int> (m, 0));
        // base case
        for (int j1 = 0; j1<m; j1++){
            for (int j2=0; j2<m; j2++){
                if (j1==j2)front[j1][j2] = grid[n-1][j1];
                else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for (int i=n-2; i>=0; i--){
            for (int j1 = 0; j1<m; j1++){
                for (int j2=0; j2<m; j2++){
                    int maxi = 0;
                    for (int dj1 = -1; dj1<=1; dj1++){
                        for (int dj2 = -1; dj2 <= 1; dj2++){
                            int cherries = 0;
                            if (j1==j2) cherries = grid[i][j1]; 
                            else cherries = grid[i][j1] + grid[i][j2];
                            if (j1+dj1 < m && j1+dj1 >= 0 && j2+dj2 < m && j2+dj2 >= 0)
                                cherries += front[j1+dj1][j2+dj2];
                            else cherries += -1e8;
                            maxi = max (maxi, cherries);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m-1];
    }
};