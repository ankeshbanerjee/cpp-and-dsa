#include <bits/stdc++.h>
using namespace std;

// similar problem as buy and sell stocks II, with a slight modification
// here we have a constraint that we can make at most two transactions
// i.e., buying and selling at most two stocks. And we have to return the max profit
// so, with all the things from 'buy and sell stocks II' being kept here, 
// we have introduced a new changing parameter - 'cap', which indicates the number of remaining transactions
// initially its value is 2, coz, initially we can make at most two transactions
// when i buy a stock the 'cap' doesn't change, coz, the transaction is complete only when i sell the stock
// so, 'cap' will only change when i sell a stock (cap changes to cap-1)

// and in the base case, 
// if I have exhausted the array, OR, the cap is 0 (i.e., no more transactions are left)
// then I have nothing to gain from the market, so return 0;

class Solution {
private:
    int f(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp){
        // base case
        if (ind==n || cap==0) return 0;
        
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

       if (buy){
            return dp[ind][buy][cap] = max(-prices[ind]+f(ind+1, 0, cap, prices, n, dp), 
                                                0+f(ind+1, 1, cap, prices, n, dp));
       }

        return dp[ind][buy][cap] = max(prices[ind]+f(ind+1, 1, cap-1, prices, n, dp), 
                                                0+f(ind+1, 0, cap, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, n, dp);
    }
};
// recursive -> TC = exponential; SC = O(N)
// Memoization -> TC = O(N*2*3); SC = O(N*2*3) + O(N)


// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for (int ind=n-1; ind>=0; ind--){
            for (int buy=0; buy<=1; buy++){
                for (int cap=1; cap<3; cap++){
                    if (buy)
                        dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap], 
                                0+dp[ind+1][1][cap]);
                    else
                        dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1], 
                                0+dp[ind+1][0][cap]);
                }
            }
        }

        return dp[0][1][2];
    }
};
// TC = O(N*2*3); SC = O(N*2*3) 


// space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        
        for (int ind=n-1; ind>=0; ind--){
            for (int buy=0; buy<=1; buy++){
                for (int cap=1; cap<3; cap++){
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

        return after[1][2];
    }
};
// TC = O(N*2*3); SC = O(2*3) = O(1) (const)



// another approach
// instead of using dp[N][2][3], in this approach we can use dp[N][4] in this method
// here, newly introduced parameter is transaction, which have 4 values - 0, 1, 2, 3
// 0->buy, 1->sell, 2->buy, 3->sell :-> thus it represents 2 transactions
// so, here is no need to 'buy' parameter, coz,
// if (transaction % 2 == 0) we can buy
// else we can sell

// base case is if array is exhausted of all the transactions have done (i.e., transaction == 4)
// we can get nothing more from the market, so return 0;

// recursive code
class Solution {
private:
    int f(int ind, int transaction, vector<int> &prices, int n){
        // base case
        if (ind == n || transaction == 4) return 0;

        if (transaction % 2 == 0)
            return max(-prices[ind] + f(ind+1, transaction+1, prices, n),
                    0 + f(ind+1, transaction, prices, n));
            
        return max(prices[ind] + f(ind+1, transaction+1, prices, n), 
                    0+ f(ind+1, transaction, prices, n));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0, 0, prices, n);
    }
};
// TC = exponential, SC = O(N)

// memoization
class Solution {
private:
    int f(int ind, int transaction, vector<int> &prices, int n, vector<vector<int>> &dp){
        // base case
        if (ind == n || transaction == 4) return 0;

        if(dp[ind][transaction] != -1) return dp[ind][transaction];
        if (transaction % 2 == 0)
            return dp[ind][transaction] = max(-prices[ind] + f(ind+1, transaction+1, prices, n, dp),
                    0 + f(ind+1, transaction, prices, n, dp));
            
        return dp[ind][transaction] = max(prices[ind] + f(ind+1, transaction+1, prices, n, dp), 
                    0+ f(ind+1, transaction, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return f(0, 0, prices, n, dp);
    }
};
// TC = O(N*4); SC = O(N*4) + O(N)

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (5, 0));
        
        for (int ind=n-1; ind>=0; ind--){
            for (int transaction=0; transaction<=3; transaction++){
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
// TC = O(N*4); SC = O(N*4)

// space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> after(5, 0), curr(5, 0);
        
        for (int ind=n-1; ind>=0; ind--){
            for (int transaction=0; transaction<=3; transaction++){
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
// TC = O(N*4); SC = O(4) = const