#include <bits/stdc++.h>
using namespace std;

// same code as longest increasing subsequence
// here, the question asks for subsets, so sorting the array according to the string lengths
// so, the length of the strings has been taken care of, we will surely start from the smallest possible string
// Only change here is the check condition, (checkPossible (arr[ind], arr[prev]))

bool checkPossible (string &s1, string &s2){
    if (s1.size() != s2.size()+1) return false;
    int first = 0;
    int second = 0;
    while (first < s1.size()){
        if (s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }

    if (first == s1.size() && second == s2.size()) return true;
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);
    vector <int> dp(n, 1);

    int maxi = INT_MIN;
    for (int ind=0; ind<n; ind++){
        for (int prev = 0; prev < ind; prev++){
            if (checkPossible(arr[ind], arr[prev])){
                dp[ind] = max (dp[ind], 1+dp[prev]);
            }
        }
        maxi = max(maxi, dp[ind]);
    }

    return maxi;
}
// TC = O(N^2 * L)
// SC = O(N)


// or, space optimization code of longest increasing subsequence
#include <bits/stdc++.h> 
bool checkPossible (string &s1, string &s2){
    if (s1.size() != s2.size()+1) return false;
    int first = 0;
    int second = 0;
    while (first < s1.size()){
        if (s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }

    if (first == s1.size() && second == s2.size()) return true;
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &words)
{
    // Write your code here.
    int n = words.size();
    sort(words.begin(), words.end(), comp);
    vector<int> front(n+1, 0), curr(n+1, 0);
    
    for (int ind=n-1; ind>=0; ind--){
        for (int prev_ind=ind-1; prev_ind>= -1; prev_ind--){
            // not take
            int notTake = 0 + front[prev_ind+1];
            // take
            int take = INT_MIN;
            if (prev_ind == -1 || checkPossible(words[ind], words[prev_ind])){
                take = 1 + front[ind+1];
            }
            curr[prev_ind+1] = max(notTake, take);
        }
        front = curr;
    }

    return front[-1+1];
}