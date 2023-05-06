#include<bits/stdc++.h>
using namespace std;

class Solution {
int f (int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    // base case
    int m = matrix[0].size();
    if (i==0 && j>=0 && j<m) return dp[i][j] = matrix[i][j];
    if (j<0 || j>=m) return (int)1e9;
    //or,
    // if (j<0 || j>=m) return (int)1e9;
    // if (i==0) return dp[i][j] = matrix[i][j];

    if (dp[i][j] != -1) return dp[i][j];
    int ldg = matrix[i][j] + f(i-1, j-1, matrix, dp);
    int up = matrix[i][j] + f(i-1, j, matrix, dp);
    int rdg = matrix[i][j] + f(i-1, j+1, matrix, dp);
    
    return dp[i][j] = min(ldg, min(up, rdg));
}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp (n, vector<int> (m, -1));
        int mini = (int)1e9;
        for (int i=0; i<m; i++){
            mini = min (mini, f(n-1, i, matrix, dp));
        }
        return mini;
    }
};
// Using only recursion will cost a TC of 3^n, which is exponential in nature, and a recursive stack of O(n)
// In memoization, TC = O(N*M), bcz, there are N*M different values of (i, j)
// SC = recursive stack space + dp array = O(N) + O(N*M)


// recursion calls another recursion, passes parameters, stores in stack, which takes a lot more time than O(N*M)
// So, better to use tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp (n, vector<int> (m, 0));
        // base cases
        for (int i=0; i<m; i++){
            dp[0][i] = matrix[0][i];
        }

        for (int i=1; i<n; i++){
            for (int j=0; j<m; j++){
                int up, ldg, rdg;
                ldg = rdg = 1e9;
                if (j-1>=0) ldg = matrix[i][j] + dp[i-1][j-1];
                up = matrix[i][j] + dp[i-1][j];
                if (j+1<m) rdg = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min (up, min(ldg, rdg));
            }
        }

        int mini = 1e9;
        for (int i=0; i<m; i++){
            mini = min (mini, dp[n-1][i]);
        }
        return mini;
    }
};
// TC = O(N*M)
// SC = O(N*M)

// space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev (m, 0), curr(m, 0);
        // base cases
        for (int i=0; i<m; i++){
            prev[i] = matrix[0][i];
        }

        for (int i=1; i<n; i++){
            for (int j=0; j<m; j++){
                int up, ldg, rdg;
                ldg = rdg = 1e9;
                if (j-1>=0) ldg = matrix[i][j] + prev[j-1];
                up = matrix[i][j] + prev[j];
                if (j+1<m) rdg = matrix[i][j] + prev[j+1];
                curr[j] = min (up, min(ldg, rdg));
            }
            prev = curr;
        }

        int mini = 1e9;
        for (int i=0; i<m; i++){
            mini = min (mini, prev[i]);
        }
        return mini;
    }
};

// TC = O(N*M)
// SC = O(N)