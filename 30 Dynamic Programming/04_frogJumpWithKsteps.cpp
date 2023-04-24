#include <bits/stdc++.h>
using namespace std;

// memoization
int f (int ind, vector <int> &heights, vector<int> &dp, int k){
    if (ind == 0)return 0;
    if (dp[ind] != -1)return dp[ind];
    int mn = INT_MAX;
    for (int i=1; i<=k; i++){
        if(ind >= i){
            mn = min (mn, f(ind-i, heights, dp, k));
        }
        else{
            break;
        }
    }
    return dp[ind] = mn;
}

int frogJumpK(int n, vector<int> heights, int k){
    vector<int> dp(n, -1);
    return f(n-1, heights, dp, k);
}
// TC = O(N*K) ; SC = O(N) + O(N)

// tabulation
int frogJumpK(int n, vector<int> heights, int k){
    vector<int> dp(n, -1);
    dp[0] = 0;
    int mn = INT_MAX;
    for (int i=1; i<n; i++){
        for (int j=1; j<=k; j++){
            if (i>=j){
                mn = min(mn, dp[i-j]);
            }
            else{
                break;
            }
        }
        dp[i] = mn;
    }
}
// TC = O(N*K) ; SC = O(N)

// Space optimization : space can be optimized from O(N) to O(K), but if N=K, then in worst case the space will be O(N)
// so space optimization is of no use
// but to do space optimization to O(K), we need to store the k previouses like prev1, prev2, prev3, ..., prevk in an array of size k