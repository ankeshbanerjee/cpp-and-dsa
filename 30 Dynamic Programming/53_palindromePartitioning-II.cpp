#include <bits/stdc++.h>
using namespace std;


// FRONT PARTITION TECHNIQUE
// following the front partition technique, we will start checking from the first index of the given string 
// and will check if we can make a partition between the first and the second index. 
// Similarly, then we will include the second index in the account and check if we can make a partition between the second and the third index.
// This process will continue to the last index. 

// here,
// starting from i=0 (first index),
// we are going to to each index till the end (for (int ind=i; ind<n; ind++))
// and checking if s[i...ind] is a palindrome or not
// if s[i...ind] is a palindrome, then a partition can be made at ind
// and the minimum partitions for the rest of the string, can be got by f(ind+1)
// calculating the cost for each possible partitions, and tracking that which possible partition causes minimum partitions
// return that minimum partition

// -1 is done at the answer, coz,
// let s = 'c'
// the function will return 1
// coz the partition made is -> c |
// so, this function, always make a partition after the last index
// so, doing '-1' from the answer

class Solution {
private:
    bool isPalindrome (int i, int j, string &s){
        while (i<j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int n, string &s, vector<int> &dp){
        // base case
        if (i==n) return 0;

        if (dp[i] != -1) return dp[i];
        int minCost = 1e9;
        for (int ind=i; ind<n; ind++){
            int cost = 0;
            if(isPalindrome(i, ind, s)){
                cost = 1 + f(ind+1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp)-1;
    }
};
// recursion -> exponential
// memoization -> TC = O(N) * N = O(N^2) => there are a total of N states and inside each state, a loop of size N(apparently) is running.
// SC = O(N) + Auxiliary stack space O(N)


// tabulation
class Solution {
private:
    bool isPalindrome (int i, int j, string &s){
        while (i<j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int minCost = 1e9;
            for (int ind=i; ind<n; ind++){
                int cost = 0;
                if(isPalindrome(i, ind, s)){
                    cost = 1 + dp[ind+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0]-1;
    }
};

// TC = O(N^2)
// SC = O(N)