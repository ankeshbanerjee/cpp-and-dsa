#include <bits/stdc++.h>
using namespace std;

// substring -> unlike subsequence, a substring has to be consecutive,
// that means no character should be left in between in case of substring\

// the solution of this can be done by modifying the tabulation code of longest common subsequence
// approach : 
// if match is found, check if the previous index of both the strings have a match or not, then do +1 with that previous match value
// if not matched, just make dp[i][j] = 0
// the max value of the dp array will be the length of longest common substring


int lcs(string &str1, string &str2){
	//	Write your code here.
	int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // // index=0 will work as index=-1
    for (int i=0; i<=n; i++) dp[i][0] = 0;
    for (int i=0; i<=m; i++) dp[0][i] = 0;

	int ans = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            //match
            if (str1[i-1] == str2[j-1]) {
				dp[i][j] = 1+ dp[i-1][j-1];
				ans = max(ans, dp[i][j]);
			}
            // not match
            else dp[i][j] = 0;
        }
    }

	return ans;
}


// space optimization
#include <bits/stdc++.h> 
int lcs(string &str1, string &str2){
	//	Write your code here.
	int n = str1.length();
    int m = str2.length();
    vector<int>prev(m+1, 0), curr(m+1, 0);

	int ans = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            //match
            if (str1[i-1] == str2[j-1]) {
				curr[j] = 1+ prev[j-1];
				ans = max(ans, curr[j]);
			}
            // not match
            else curr[j] = 0;
        }
		prev = curr;
    }

	return ans;
}