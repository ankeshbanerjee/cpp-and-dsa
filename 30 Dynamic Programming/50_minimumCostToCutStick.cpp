#include <bits/stdc++.h>
using namespace std;


// as there can be multiple possible ways to cut the stick
// so, to find the best possible way, we are using partition dp
// as rule of partition dp, take the entire cuts array first
// but before that, insert 0 at the beginning and n (size of the stick) at the end of the cuts array
// it will be needed to compute the cost

// Now, the first question that arrises, is
// how will I make two partition in the cuts array, so that the partitions (sub problems) can be solved independently?
// let's consider the cuts array - 
// [3, 4, 5, 1]
// let's say, I wanna make a cut at ind = 4.
// then the two partitions of the stick will be -
// [0, 1, 2, 3, 4, 5] - first partition
// [5, 6, 7] - second partition
// so, can the partitions - [3] and [5, 1] be independently solved?
// the answer is NO!
// coz, in the second partition [5 1], cut index 1 will belong to the first partition of the stick ([3] (cuts) => [0, 1, 2, 3, 4, 5] (stick)). 
// so, the solution of second partition will be dependent upon the first partition.
// so, they can't be independently solved

// so, to make the two partitions be independently solvable
// we need to sort the cuts array, so if we sort the previous array
// [1, 3, 4, 5]
// this ensures that the partitions are independently solvable
// coz, now if I wanna cut at ind = 3, then the partitions will be - [1] and [4, 5]
// so, it is clear that both the partitions are independent of each other

// now, how will the function look like?
// two parameters will be there to represent the start and end index of cuts (i, j)
// run a loop to try out all the possible two partitions of the stick
// i.e., to try out all the possible cut indices, and return the minimum cost among all of them
// Now, to make a cut, cost is the length of the stick on which cut is made.
// this cost can be computed by (cuts[j+1]-cuts[i-1])
// this can be found out while doing dry run with an example
// so, when the first cut is made on the stick, the cost will be the initial length of the stick
// that's why 0 and n was added at the beginning and end of the cuts array
// so that, when i=1 and j=c(size of cuts), the cost comes out to be n (cuts[c+1] - cust[1-1] = n - 0 = n)

// now the total cost will be the sum of the cost to make the partition + the minimum costs of each of the two partitions
// return the minimum of all such possible ways
// (try out all the cut indeces in between i and j, and find out on which index if I make a cut, the cost is coming out to be minimum)

class Solution {
private:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        // base case
        if (i>j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for (int ind=i; ind<=j; ind++){
            int cost = cuts[j+1]-cuts[i-1] + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
        return f(1, c, cuts, dp);
    }
};
// recursion - exponential
// memoization - TC = O(C*C) * C = O(C^3); SC = O(C^2) + O(C)

// tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int> (c+1, 0));
       
        for (int i=c; i>=1; i--){
            for (int j=1; j<=c; j++){
                if (i>j) continue;
                int mini = INT_MAX;
                for (int ind=i; ind<=j; ind++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }

       return dp[1][c];
    }
};
// TC = O(C^3); SC = O(C^2)