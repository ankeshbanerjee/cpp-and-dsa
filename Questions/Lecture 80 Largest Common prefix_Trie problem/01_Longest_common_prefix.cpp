#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix (vector <string> &arr){
    string ans;

    for (int i=0; i<arr[0].length(); i++){
        char ch = arr[0][i];
        bool isSameInAll = true;
        for (int j=1; j<arr.size(); j++){
            if (arr[j].length() < i || ch != arr[j][i]){
                isSameInAll = false;
                break;
            }
        }
        if (isSameInAll)
            ans.push_back(ch);
        else
            break;     
    }
    return ans;
}

// TC = O(M*N), M = length of first string, N = no. of strings
// SC = O(1)

int main (){
    vector <string> arr = {"coding", "coder", "codingninjas", "codechef", "codeforces"};
    cout << longestCommonPrefix(arr) << endl;
    
return 0;
}