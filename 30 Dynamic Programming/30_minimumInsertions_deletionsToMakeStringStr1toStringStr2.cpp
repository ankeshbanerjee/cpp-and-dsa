#include <bits/stdc++.h>
using namespace std;

// to find the minimum number of insertions or deletions
// first we need to figure out the maximum portion which should not be touched
// and that is the lcs(str1, str2)
// the no. of deletions in str1 will be the no. of characters other than the lcs i.e., (str1.size()-lcs)
// now we have to insert the characters from str2, which are not present in the lcs, into str1
// so, insertions = (str2.size()-lcs)

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    vector<int>prev(m+1, 0), curr(m+1, 0);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            //match
            if (text1[i-1] == text2[j-1]) curr[j] = 1+ prev[j-1];
            // not match
            else curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }

    return prev[m];
}   
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();
    int lcs_length = longestCommonSubsequence(str, ptr);
    int deletions = n-lcs_length;
    int insertions = m-lcs_length;
    return (deletions+insertions);

    // in short 
    // return (str.size()+ptr.size()-2*longestCommonSubsequence(str, ptr));
}