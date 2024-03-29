// Those who cannot remember the past are condemned to repeat it .... ~DP

// There are two approaches people use to solve dynamic programming
// 1. Tabulation -> Bottom-Up (base case to the required)
// 2. Memoization -> Top-Down (required to the base case)

// important terms : 
// overlapping subproblems : while solving a problem, when we end up solving a part problem again,
// then it is called overlapping subproblem
// Memoization : tend to store the of subproblems in some map / table

#include <bits/stdc++.h>
using namespace std;

int f (int n, vector <int> &dp){
    // base case
    if (n <= 1)return n;
    // step 3 : check if the subproblem is previously solved or not
    if (dp[n] != -1)return dp[n];
    
    // step 2 : store values in dp array
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main (){
    int n;
    cin >> n;
    // memoization => convert recursion to dp (Top-Down approach)
    // step 1 : create an array to store the results of overlapping subproblems
    // (check for the parameters which are changing, here 1 parameter is changing, so create 1-D array)
    vector <int> dpM(n+1, -1);  // size n+1 because there is f(0) also (base case)
    // the size of the dp array will be from base case to the required answer's index
    // i.e., size = number of subproblems
    // here from 0 to n, that's why (n+1)
    cout << f(n, dpM) << endl;
    // TC = O(N) ; SC = O(N) + O(N) (dp array + recursion call stack)

    // Tabulation : (Bottom-Up : from base case to the result) : this can be done by observing the recursion solution
    vector<int> dpT(n+1, -1);
    // look at the base cases and assign their values in the dp array accordingly
    dpT[0] = 0;
    dpT[1] = 1;
    // for 1 changing parameter (1-D dp), 1 outer loop for tabulation
    for (int i=2; i<=n; i++){
        // just replace f(n-1) and f(n-2) with dp[n-1] and dp[n-2]
        dpT[i] = dpT[i-1] + dpT[i-2];
    }
    cout << dpT[n] << endl;
    // TC = O(N) ; SC = O(N)

    // Space optimization :  whenever there is ind-1 or ind-2 types of stuffs, then there must be space optimization
    int prev = 1, prev2 = 0;
    for (int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl; // prev will be the ans, because after the end of the for loop, i will be i+1, prev will store the ans
    // TC = O(N) ; SC = O(1)
return 0;
}