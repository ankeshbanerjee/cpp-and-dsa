#include <bits/stdc++.h>
using namespace std;

// similar problem as buy and sell stock III
// in that case cap was 2. 
// in this problem cap is k.
// so, just do cap = k everywhere

// space optimization code of first approach of buy and sell stock III
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        
        for (int ind=n-1; ind>=0; ind--){
            for (int buy=0; buy<=1; buy++){
                for (int cap=1; cap<=k; cap++){
                    if (buy)
                        curr[buy][cap] = max(-prices[ind]+after[0][cap], 
                                0+after[1][cap]);
                    else
                        curr[buy][cap] = max(prices[ind]+after[1][cap-1], 
                                0+after[0][cap]);
                }
            }
            after = curr;
        }

        return after[1][k];
    }
};



// second approach of buy and sell stock III
// in buy and sell stock, cap = 2, then there were 4 transactions
// now as cap = k, tranNo. = 2*k

// memoization
class Solution {
private:
    int f(int ind, int transaction, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
        // base case
        if (ind == n || transaction == 2*k) return 0;

        if(dp[ind][transaction] != -1) return dp[ind][transaction];
        if (transaction % 2 == 0)
            return dp[ind][transaction] = max(-prices[ind] + f(ind+1, transaction+1, prices, n, k, dp),
                    0 + f(ind+1, transaction, prices, n, k, dp));
            
        return dp[ind][transaction] = max(prices[ind] + f(ind+1, transaction+1, prices, n, k, dp), 
                    0+ f(ind+1, transaction, prices, n, k, dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2*k, -1));
        return f(0, 0, prices, n, k, dp);
    }
};
// TC = O(N*K); SC = O(N*K) + O(N)


// tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
        
        for (int ind=n-1; ind>=0; ind--){
            for (int transaction=0; transaction<=2*k-1; transaction++){
                if (transaction % 2 == 0)
                    dp[ind][transaction] = max(-prices[ind] + dp[ind+1][transaction+1],
                            0 + dp[ind+1][transaction]);
                    
                else dp[ind][transaction] = max(prices[ind] + dp[ind+1][transaction+1], 
                            0+ dp[ind+1][transaction]);
            }
        }

        return dp[0][0];
    }
};
// TC = O(N*K); SC = O(N*K)


// space optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k+1, 0), curr(2*k+1, 0);
        
        for (int ind=n-1; ind>=0; ind--){
            for (int transaction=0; transaction<=2*k-1; transaction++){
                if (transaction % 2 == 0)
                    curr[transaction] = max(-prices[ind] + after[transaction+1],
                            0 + after[transaction]);
                    
                else curr[transaction] = max(prices[ind] + after[transaction+1], 
                            0+ after[transaction]);
            }
            after = curr;
        }

        return after[0];
    }
};
// TC = O(N*K); SC = O(K)