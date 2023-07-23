#include <bits/stdc++.h>
using namespace std;

// tabulation
// point to watch out while writing for loops
// i is always on left of j (coz, end index will always be greater than or equal to the start index, and case of (i==j) is already done while writing the base case).
// so, range of j will be (i+1 -> n-1)

#include <bits/stdc++.h> 
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int> (N, 0));

    // base case
    // for (int i=0; i<n; i++) dp[i][i] = 0; // no need to do as dp array is already initialized with 0

    for (int i=N-1; i>0; i--){
        for (int j=i+1; j<N; j++){
            int mini = 1e9;
            for (int k=i; k<j; k++){
                int operations = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, operations);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}

// TC = O(N^3), SC = O(N^2)