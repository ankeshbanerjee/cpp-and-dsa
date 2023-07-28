#include <bits/stdc++.h>
using namespace std;


// initially taking the entire array into consideration (i=0, j=n-1)
// as we noticed that inside the function it is needed to have the count of 'F' also
// so, introduced a third paramter - 'isTrue', which can have two values - 0 and 1
// f(i, j, 0) => no of ways to get 'F', in exp[i...j]
// f(i, j, 1) => no of ways to get 'T', in exp[i...j]

// now trying out all the possible partitions inside exp[i...j]
// for (int ind = i+1; ind <= j-1; ind+=2) => this ind jumps to each operator inside exp[i...j], that's why doing ind = ind+2
// then get the no. of T/F of the left partition by f(i, ind-1, 0/1)
// get the no. of T/F of the right partition by f(ind+1, j, 0/1)
// then count the no.s of T/F according to the current operator (exp[ind])

#include <bits/stdc++.h> 
#define ll long long
int mod = 1e9+7;

ll f(int i, int j, int isTrue, string & exp, vector<vector<vector<ll>>> &dp){
    // base case
    if (i>j) return 0;
    if (i==j){
        if (isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ways = 0;
    for (int ind = i+1; ind <= j-1; ind+=2){
        ll lF = f(i, ind-1, 0, exp, dp);
        ll lT = f(i, ind-1, 1, exp, dp);
        ll rF = f(ind+1, j, 0, exp, dp);
        ll rT = f(ind+1, j, 1, exp, dp);
        if (exp[ind] == '&'){
            if (isTrue) ways = (ways + (lT*rT)%mod) % mod;
            else ways = (ways + (lF*rF)%mod + (lF*rT)%mod + (lT*rF)%mod) % mod; 
        }
        else if (exp[ind] == '|'){
            if (isTrue) ways = (ways + (lT*rT)%mod + (lF*rT)%mod + (lT*rF)%mod) % mod;
            else ways = (ways + (lF*rF)%mod) % mod;
        }
        else {
            // T^T = F, F^F = F, T^F = T, F^T = T
            if (isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod) % mod;
            else ways = (ways + (lT*rT)%mod + (lF*rF)%mod) % mod;
        }
    }

    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
    return f(0, n-1, 1, exp, dp);
}
// TC = O(N*N*2) * N = O(N^3)
// SC = O(N*N*2) + auxiliarty stack space


// tabulation
#include <bits/stdc++.h> 
#define ll long long
int mod = 1e9+7;

int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, 0)));
    for (int i=0; i<n; i++){
        dp[i][i][1] = exp[i] == 'T';
        dp[i][i][0] = exp[i] == 'F';
    }

    for (int i=n-1; i>=0; i--){
        for (int j=i; j<n; j++){
            if (i==j)continue;
            for (int isTrue=0; isTrue <= 1; isTrue++){
                ll ways = 0;
                for (int ind = i+1; ind <= j-1; ind+=2){
                    ll lF = dp[i][ind-1][0];
                    ll lT = dp[i][ind-1][1];
                    ll rF = dp[ind+1][j][0];
                    ll rT = dp[ind+1][j][1];
                    if (exp[ind] == '&'){
                        if (isTrue) ways = (ways + (lT*rT)%mod) % mod;
                        else ways = (ways + (lF*rF)%mod + (lF*rT)%mod + (lT*rF)%mod) % mod; 
                    }
                    else if (exp[ind] == '|'){
                        if (isTrue) ways = (ways + (lT*rT)%mod + (lF*rT)%mod + (lT*rF)%mod) % mod;
                        else ways = (ways + (lF*rF)%mod) % mod;
                    }
                    else {
                        // T^T = F, F^F = F, T^F = T, F^T = T
                        if (isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod) % mod;
                        else ways = (ways + (lT*rT)%mod + (lF*rF)%mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n-1][1];
}
// TC = O(N^3)
// SC = O(N*N*2)