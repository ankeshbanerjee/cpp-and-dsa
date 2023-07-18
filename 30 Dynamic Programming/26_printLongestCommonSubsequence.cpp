#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    // tabulation code of length of lcs
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // // index=0 will work as index=-1
    for (int i=0; i<=n; i++) dp[i][0] = 0;
    for (int i=0; i<=m; i++) dp[0][i] = 0;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            //match
            if (text1[i-1] == text2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            // not match
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // code for printing lcs
    string lcs = "";
    // initiating lcs string with the length of lcs_length with dummy character as '$'
    int lcs_length = dp[n][m];
    for (int i=0; i<lcs_length; i++)lcs+='$';
    int index = lcs_length-1;

    int i=n, j=m;
    // whenever i or j reaches 0, that means either of strings has exhausted
    while(i>0 && j>0){
        if (text1[i-1] == text2[j-1]){
            // if matched, go to the upper left diagonal element
            lcs[index] = text1[i-1];
            index--, i--, j--;
        }
        // not matched - move to the max of previous column or previous row element
        else if (dp[i][j-1] > dp[i-1][j]){
            j--;
        }
        else {
            i--;
        }
    }

    return lcs;
}

int main (){
    string s1 = "abcde";
    string s2 = "bdgek";
    cout << longestCommonSubsequence(s1, s2) << endl;
return 0;
}