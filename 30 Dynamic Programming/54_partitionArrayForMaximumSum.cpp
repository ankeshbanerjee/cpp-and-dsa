#include <bits/stdc++.h>
using namespace std;


// FRONT PARTITION

// starting from the front
// generating the partitions according to the given k (maximum size of subarray)
// maximum of all possible partitions is the answer

class Solution {
private:
    int f(int i, int k, vector<int> &arr, int n, vector<int> &dp){
        // base case
        if (i==n) return 0;

        if (dp[i] != -1) return dp[i];

        int len = 0, maxi = INT_MIN, maxSum = INT_MIN;
        for (int ind=i; ind < min(i+k, n); ind++){
            len++;
            maxi = max(maxi, arr[ind]);
            int sum = len*maxi + f(ind+1, k, arr, n, dp);
            maxSum = max(maxSum, sum);
        }

        return dp[i] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, k, arr, n, dp);
    }
};
// recursion - EXPONENTIAL
// memoization - TC = O(N) * O(K), SC = O(N) + auxiliary stack space (O(N))

// tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for (int i=n-1; i>=0; i--){
            int len = 0, maxi = INT_MIN, maxSum = INT_MIN;
            for (int ind=i; ind < min(i+k, n); ind++){
                len++;
                maxi = max(maxi, arr[ind]);
                int sum = len*maxi + dp[ind+1];
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};

// TC = O(N*K)
// SC = O(N)