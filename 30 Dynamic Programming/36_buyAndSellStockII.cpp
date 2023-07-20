#include <bits/stdc++.h>
using namespace std;

// buy and sell stock II
// problem states that buying and selling is allowed multiple times, and we have to return the max profit
// constraint is that, if a stock is bought, then it has to be sold, before buying any other stock
// so, two changing parameters can be there -> ind, buy (buy = 0/1, which states that if I can or cannot buy in the next ind)
// now at a call, if (buy == 1), then there are two options -
// buy or notBuy, just like take or notTake in dp on subsequences problems
// if I buy the current stock, it will cost me prices[ind], which I have to subtract from the ans, so the call -> -prices[ind] + f(ind+1, 0, prices, n, dp)
// in the call, buy is set to 0, coz, i have bought in the current index, so i can't buy in the next index (ind+1)
// other option is notBuy, if I don't buy, then it will cost me nothing, and i can still buy in the next index (ind+1). so the call -> 0 + f(ind+1, 1, prices, n, dp)
// Now, to get the max profit, take the max of (buy, notBuy)
// And if (buy == 0), that means i can't buy in the current index, then there will also be similar two options -
// sell or notSell
// if sold in the curr ind, then price[ind] will be added to the ans, and i can buy in the next index so, prices[ind] + f(ind+1, 1, prices, n, dp)
// if not sold in the curr ind, then no amount will be added, and i can't buy in the next index, so, 0 + f(ind+1, 0, prices, n, dp)
// now to get the max profit, take the max of these two cases

// base case

// commented one -
// if (ind == n-1), then
// if I can't buy, then i will sell the stock, coz that's what i can do to get the max profit in the last remaining index
// so, return prices[ind] in that case
// and if I can buy, definitely I should not buy, coz, I will not be able to sell it later, coz I am standing at the last index.
// so, return 0 (coz, not buying will not me nothing)

// we can write the base case in another way
// if (ind == n), this means, the array is exhausted, so no more profit I can do, so return 0;


class Solution {
private:
    int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        // base case

        // if (ind == n-1){
        //     if (buy){
        //         return 0;
        //     }
        //     else return prices[n-1];
        // }
        // or,
        if (ind == n)return 0;

        if (dp[ind][buy] != -1)return dp[ind][buy];

        if (buy){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, prices, n, dp), 0 + f(ind+1, 1, prices, n, dp));
        }

        return dp[ind][buy] = max(prices[ind] + f(ind+1, 1, prices, n, dp), 0 + f(ind+1, 0, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, buy, prices, n, dp);
    }
};
// recursion -> TC = O(2^N), coz, in each call, two options are there -> if (buy) => sell / notSell; if(!buy) => buy / notBuy
// SC = O(N)
// memoization -> TC = O(N*2), SC = O(N*2) + O(N)

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        dp[n][0] = dp[n][1] = 0;

        for (int ind=n-1; ind>=0; ind--){
            for (int buy = 0; buy<=1; buy++){
                int profit = 0;
                if (buy){
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1]; 
    }
};
// or, 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));
        dp[n-1][0] = prices[n-1];
        dp[n-1][1] = 0;

        for (int ind=n-2; ind>=0; ind--){
            for (int buy = 0; buy<=1; buy++){
                int profit = 0;
                if (buy){
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1]; 
    }
};
// TC = O(N*2), SC = O(N*2)



// space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        ahead[0] = ahead[1] = 0;

        for (int ind=n-1; ind>=0; ind--){
            for (int buy = 0; buy<=1; buy++){
                int profit = 0;
                if (buy){
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else{
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1]; 
    }
};
// or, 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        ahead[0] = prices[n-1];
        ahead[1] = 0;

        for (int ind=n-2; ind>=0; ind--){
            for (int buy = 0; buy<=1; buy++){
                int profit = 0;
                if (buy){
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else{
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1]; 
    }
};
// TC = O(N*2), SC = O(4) = const = O(1)

// space optimization using 4 variables
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int aheadNotBuy, aheadBuy, currNotBuy, currBuy;
        aheadNotBuy = aheadBuy = 0;

        for (int ind=n-1; ind>=0; ind--){

            currBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

            currNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);

            aheadNotBuy = currNotBuy;
            aheadBuy = currBuy;

        }
        return aheadBuy; 
    }
};
// this is not any further optimization, coz, this takes 4 variables
// and the previous space optimization also uses two 2-sized array, so 4 places
// so, space required is same in both the cases