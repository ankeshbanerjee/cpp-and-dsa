#include <bits/stdc++.h>
using namespace std;


// problem says that I can't buy on the next day after selling, I've to wait one day to buy again
// so, problem is same as buy and sell stock II
// only when I sell, I go to the next day of the next day i.e., ind+2 (prices[ind] + f(ind+2, 1, prices, n, dp))

class Solution {
private:
    int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        // base case
        if (ind >= n)return 0;

        if (dp[ind][buy] != -1)return dp[ind][buy];

        if (buy){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, prices, n, dp), 0 + f(ind+1, 1, prices, n, dp));
        }

        return dp[ind][buy] = max(prices[ind] + f(ind+2, 1, prices, n, dp), 0 + f(ind+1, 0, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, buy, prices, n, dp);
    }
};


// tabulation
// in case of buy and sell stock, the inner loop for (buy = 0->1) can be avoided
// coz, if I applied the inner loop, then when buy = 0, (dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);) this gets computed
// and when buy = 1, (dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);) this gets computed
// So, avoiding the inner loop and computing both in the same iteration
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        
        for (int ind=n-1; ind>=0; ind--){

             dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);

             dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);

        }

        return dp[0][1];
    }
};


// space optimization
// here space optimization needs three arrays
// for -> curr, ind+1, ind+2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead1(2, 0), ahead2(2, 0), curr(2, 0);
        
        for (int ind=n-1; ind>=0; ind--){

             curr[1] = max(-prices[ind] + ahead1[0], 0 + ahead1[1]);

             curr[0] = max(prices[ind] + ahead2[1], 0 + ahead1[0]);

            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[1];
    }
};