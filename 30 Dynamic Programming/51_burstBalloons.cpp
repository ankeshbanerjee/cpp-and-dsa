#include <bits/stdc++.h>
using namespace std;

// let a set of balloons be 
// [b1 b2 b3 b4 b5 b6]
// now, at first, if I decide to burst b4
// and decide to solve (b1 b2 b3) and (b5 b6) individually,
// i.e., coins = b3*b4*b5 + (b1 b2 b3) + (b5 b6)
// will that work?
// the answer is NO!
// why?
// in (b1 b2 b3), if I try to burst b3, then it will depend on b5,
// coz, after bursting b4, the array will be - [b1 b2 b3 b5 b6]
// so, now if I burst b3, then coins i will get is b2*b3*b5, so it involves b5, which is the part of second partition.
// similarty, instead of b3, if I wanna burst b5, it will depend on b3, which is a part of first partition.

// now, one may think, that only the boundary elements are dependent on each other, like b3 is dependent on b5, or b5 is dependent on b3
// but that's not true. coz, not only the boundary elements, rather each element of a partition, might be dependent on other partition
// coz, after bursting b4, suppose I have bursted b3.
// so, the array will be - [b1 b2 b5 b5]
// so, now, if I try to burst b2, then the coins i will get will be = b1*b2*b5
// so, I can see b2 is also dependent of b5, which is of another partition
// so, not only the boundary elements, rather each element of a partition, might be dependent on other partition
// like, here b2 of partition (b1 b2 b3) is dependent on (b5 b6) partition
// so, these partitions(or subproblems) are dependent on each other. so, I can't solve them individually.

// so, I can't start from the front. i.e., I can't look out for which balloon is to be bursted at first.
// rather I will go in opposite direction. i.e., I'll check what will happen when a balloon (nums[ind]) is bursted at the last.
// loop through the array to check for all the possibilites of each balloon, 
// all the baloons are iterated through, to know which baloon is to be bursted at the last, to get the maximum coins.

// as this is a partition dp, the function will be f(i, j)
// and this formula will give the no. of coins, coins = nums[i-1]*nums[ind]*nums[j+1]
// now, to avoid complications
// add 1 at the beginning and end of nums array
// initially, whole array is to be considered. so, i=1, j=nums.size() (before inserting 1s at both the ends)
// as initially we are considering which balloon is to be bursted at the last, so, the coins to burst the last baloon is
// coins = 1 * b * 1
// so, adding 1 at the end and begining, gives this easily
// coz, coins = nums[i-1]*nums[ind]*nums[j+1]
// as initially, i=1, j=nums.size(), so, coins = 1*nums[ind]*1

// now how does this ensures that each subproblem can be individually solved?
// let this be the array - [b1 b2 b3 b4 b5 b6]
// if b4 is bursted last, then the subproblems are - (b1 b2 b3) and (b5 b6)
// now, in the second last burst, the options are-
// [b1 b4] or [b2 b4] or [b3 b4] or [b4 b5] or [b4 b6]
// each of them are only dependent on b4, which is at (j+1)th index, (and dependent also on, nums[i-1] which is 1 in this case)
// but the subproblems now can be individually solved, none is dependent on anyone
// and the total coins you will get at any stage is - coins = nums[i-1]*nums[ind]*nums[j+1] + f(i, ind-1) + f(ind+1, j)
// i.e., coins = coins got to burst nums[ind] + coins got from left subproblem + coins got from right subproblem


// memoization
class Solution {
private:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        // base case
        if (i>j)return 0;
        if (dp[i][j] != -1)return dp[i][j];
        int maxi = INT_MIN;
        for (int ind=i; ind<=j; ind++){
            int coins = nums[i-1]*nums[ind]*nums[j+1] + f(i, ind-1, nums, dp) + f(ind+1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, nums, dp);
    }
};
// recursion - exponential
// memoization - TC = O(n*n) * n = O(n^3); SC = O(n^2) + O(n)


// tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
        
        for (int i=n; i>=1; i--){
            for (int j=1; j<=n; j++){
                if (i>j) continue;
                int maxi = INT_MIN;
                for (int ind=i; ind<=j; ind++){
                    int coins = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};
// TC = O(n^3); SC = O(n^2)