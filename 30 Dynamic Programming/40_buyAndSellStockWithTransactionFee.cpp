#include <bits/stdc++.h>
using namespace std;

// same as buy and sell stock II
// each transaction has a fee
// so, we have to subtract that fee either while buying or selling
// here, subtracting fee while selling
// otherwise, it could be subtracted while buying also

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int aheadNotBuy, aheadBuy, currNotBuy, currBuy;
        aheadNotBuy = aheadBuy = 0;

        for (int ind=n-1; ind>=0; ind--){

            currBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

            currNotBuy = max(prices[ind] - fee + aheadBuy, 0 + aheadNotBuy);

            aheadNotBuy = currNotBuy;
            aheadBuy = currBuy;

        }
        return aheadBuy; 
    }
};