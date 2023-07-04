#include <bits/stdc++.h>
using namespace std;

// this is the knapsack problem with a modification
// here, each element can be taken into the bag multiple times
// so, while 'take', stand at the same index

int f (int ind, int wt, vector<int> &profit, vector<int> &weight,
vector<vector<int>> &dp){
    // base case
    if (ind == 0){
        return ((int)(wt/weight[0])) * profit[0];
    }

    if (dp[ind][wt] != -1) return dp[ind][wt];
    int notTake = 0 + f(ind-1, wt, profit, weight, dp);
    int take = INT_MIN;
    if (weight[ind] <= wt)take = profit[ind] + f(ind, wt-weight[ind], profit, weight, dp);

    return dp[ind][wt] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return f(n-1, w, profit, weight, dp);
}
// Recursion - TC >> O()

// tabulation
#include <bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // wtrite Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w+1, 0));
    // weight can be anywhere in between 0 to w
    for (int wt=0; wt<=w; wt++) dp[0][wt] = ((int)(wt/weight[0])) * profit[0];

    for (int ind=1; ind<n; ind++){
        for (int wt=0; wt<=w; wt++){
            int notTake = 0 + dp[ind-1][wt];
            int take = INT_MIN;
            if (weight[ind] <= wt)take = profit[ind] +  dp[ind][wt-weight[ind]];
            dp[ind][wt] = max(take, notTake);
        }
    }

    return dp[n-1][w];
}


// space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // wtrite Your Code Here.
    vector<int> prev(w+1, 0), curr(w+1, 0);
    // weight can be anywhere in between 0 to w
    for (int wt=0; wt<=w; wt++) prev[wt] = ((int)(wt/weight[0])) * profit[0];

    for (int ind=1; ind<n; ind++){
        for (int wt=0; wt<=w; wt++){
            int notTake = 0 + prev[wt];
            int take = INT_MIN;
            if (weight[ind] <= wt)take = profit[ind] +  curr[wt-weight[ind]];
            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[w];
}


// space optimization to single array
// observation from the above code is that, while calculating curr[wt],
// the values needed are => prev[wt] and curr[wt-something] (previous values of curr)
// so, the previous values of prev aren't needed.
// so, we can only use the prev array to store the values of curr in the following way -
// store the prev[wt], then calculate current value using previous values and stored prev[wt]
// then rewrite that value in prev[wt]

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // wtrite Your Code Here.
    vector<int> prev(w+1, 0);
    // weight can be anywhere in between 0 to w
    for (int wt=0; wt<=w; wt++) prev[wt] = ((int)(wt/weight[0])) * profit[0];

    for (int ind=1; ind<n; ind++){
        for (int wt=0; wt<=w; wt++){
            int notTake = 0 + prev[wt];
            int take = INT_MIN;
            if (weight[ind] <= wt)take = profit[ind] +  prev[wt-weight[ind]];
            prev[wt] = max(take, notTake);
        }
    }

    return prev[w];
}
