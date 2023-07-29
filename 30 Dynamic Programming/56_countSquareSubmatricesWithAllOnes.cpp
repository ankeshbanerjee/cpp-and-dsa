#include <bits/stdc++.h>
using namespace std;

// brute force solution might be like this -
// stand at each indeces, run some for loops, expand to check how long a square can be formed, 
// expantion is possible if the neighbours are 1 and there would be many other checks as well.
// so, this can become complicated

// recursive solution is not intuitive.
// so, this types of square's problem can be solved by tabulation
// here, dp[i][j], represents the number of squares, whose right-bottom end is at (i, j)

// copy the first row and first column of matrix array to dp array
// coz, in the first row or first column, if an element is '1', then the no. of squares, where the element is bottom-right corner of the square,
// will be none but he himself.

// if an element is 0 (matrix[i][j] == 0), it can't be a part of a square, 
// i.e., no. of squares whose bottom-right end is that index (i, j), is 0

// in the code, taking the minimal of all the neighbours of dp[i][j], so that square is formed, not rectangle
// coz, taking any other value than the minimal, would cause the formation of rectangle

// sum of all values of dp, will be the ans.

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); 
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for (int i=0; i<n; i++) dp[i][0] = matrix[i][0];
        for (int j=0; j<m; j++) dp[0][j] = matrix[0][j];

        for (int i=1; i<n; i++){
            for (int j=1; j<m; j++){
                if (matrix[i][j] == 0)
                    continue;
                else
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;  // +1, coz each block himself is a square
            }
        }

        int sum = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                sum += dp[i][j];
            }
        }

        return sum;
    }
};