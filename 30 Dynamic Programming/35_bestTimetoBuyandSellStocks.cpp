#include <bits/stdc++.h>
using namespace std;

// trying to sell on each day and finding the profit
// if I am trying to sell on i-th day,
// then the buying cost should be the minimum from 1st day to (i-1)th day
// keeping the track of min upto (i-1)th index
// max of all the profit is the ans
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], maxProfit = 0;
        for (int i=1; i<prices.size(); i++){
            int profit = prices[i] - mini;
            maxProfit = max(maxProfit, profit);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};