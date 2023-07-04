#include <bits/stdc++.h>
using namespace std;

// it's a question of counting all the possible ways, so doing take + notTake
// and as it states infinite supply of coins, so staying at same index in 'take' case

class Solution {
private:
    int f(int ind, int T, vector<int> &coins, vector<vector<int>> &dp){
        // base case
        if (ind == 0){
            return (T%coins[0] == 0);
        }
        
        if (dp[ind][T] != -1) return dp[ind][T];
        // take or notTake
        int notTake = f(ind-1, T, coins, dp);
        int take = 0;
        if (coins[ind] <= T) take = f(ind, T-coins[ind], coins, dp);

        return dp[ind][T] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return f(n-1, amount, coins, dp);
    }
};
// the recursive soln. will have TC >> O(2^n), coz, we are standing at the same ind, so tell the TC to be EXPONENTIAL 
// and SC is also >> O(n)
// assume, amount will reduce at least by 1, in each call, so SC can be at max O(amount)
// though, memoization will have a TC = O(n*amount)
// and SC = O(n*amount) + O(amount) (recursion stack space)


// tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for (int T=0; T<=amount; T++) dp[0][T] = (T % coins[0] == 0);

        for (int ind=1; ind<n; ind++){
            for (int T=0; T<=amount; T++){
                int notTake = dp[ind-1][T];
                int take = 0;
                if (coins[ind] <= T) take = dp[ind][T-coins[ind]];
                dp[ind][T] = take + notTake;
            }
        }

        return dp[n-1][amount];
    }
};
// TC = O(n*amount)
// SC = O(n*amount)


// space optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1, 0), curr(amount+1, 0);
        for (int T=0; T<=amount; T++) prev[T] = (T % coins[0] == 0);

        for (int ind=1; ind<n; ind++){
            for (int T=0; T<=amount; T++){
                int notTake = prev[T];
                int take = 0;
                if (coins[ind] <= T) take = curr[T-coins[ind]];
                curr[T] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};
// TC = O(n*amount)
// SC = O(amount)