#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f (int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n){
        // base case
        if (i == n-1) return triangle[i][j];

        if (dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + f(i+1, j, triangle, dp, n);
        int diagonal = triangle[i][j] + f(i+1, j+1, triangle, dp, n);
        return dp[i][j] = min(down, diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int> (n, -1));
        // here, if we go from (n-1 -> 0), we have to call the recursive function from each element of the last row,
        // i.e., f(n-1, 0), f(n-1, 1), f(n-1, 2), ......., f(n-1, n-1)
        // then, the answer will minimum of all of those 
        // i.e., min (f(n-1, 0), f(n-1, 1), f(n-1, 2), ......., f(n-1, n-1))
        // so, instead of calling the func. for each elements of the last row,
        // it's better to call f(0, 0), and let the func. find out the answer (minimum sum path)
        // so recursion goes like (0 -> n-1), so as memoization
        return f(0, 0, triangle, dp, n);
    }
};
// recursive solution : TC = 2^(1+2+3+....+n) => bcz, for each (i, j) there is 2 options and there are such (1+2+3+....+n) cells, so the TC is such
// SC = recursive stack space = O(path length) = O(n)

// Memoization solution : TC = O(n*n), bcz, (1+2+3+....+n) combinations of (i, j) which is near equal to n*n
// SC = O(path length) (recursive stack space) + O(n*n) (dp array)


// tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int> (n, 0));
        // base case
        for (int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        // tabulation always goes in the opposite direction of memoization
        // here memoization goes from (0 to n-1), so tabulation goes in the opposite of that, i.e., (n-1 -> 0)
        // here the recurrence reln. is like i+1 or j+1
        // so, the tabulation will be opposite of that, i.e., i-- or j--
        for (int i=n-2; i>=0; i--){
            // j goes also in similar fashion
            for (int j=i; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
        
    }
};
// TC = O(n*n) (nearly)
// SC = O(n*n) (dp array)


// space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front (n, 0), curr(n, 0);
        // base case
        for (int i=0; i<n; i++){
            front[i] = triangle[n-1][i];
        }
        for (int i=n-2; i>=0; i--){
            // vector <int> curr(n, 0);
            for (int j=i; j>=0; j--){
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];
                curr[j] = min(down, diagonal);
            }
            front = curr;
        }

        return front[0];
        
    }
};
// TC = O(n*n) (nearly)
// SC = O(n)