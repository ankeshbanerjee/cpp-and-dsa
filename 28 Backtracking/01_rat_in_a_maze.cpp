// backtracking means that what we have done before, mark that as done
// no need to process for that further

#include <bits/stdc++.h>
using namespace std;

bool isPossibleMove (int newX, int newY, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n){
    if ((newX >= 0 && newX < n) && (newY >=0 && newY < n) && arr[newX][newY] == 1 && vis[newX][newY] != 1){
        return true;
    }
    else
        return false;
}

void solve (int x, int y, string str, vector<string> &ans, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n){
    // base case
    if (x == n-1 && y == n-1){
        ans.push_back(str);
        return;
    }

    vis[x][y] = 1;

    // movements : D L R U
    // D
    if (isPossibleMove (x+1, y, vis, arr, n)){
        solve(x+1, y, str + 'D', ans, vis, arr, n);  
    }
    
    // L
    if (isPossibleMove (x, y-1, vis, arr, n)){
        solve(x+1, y, str + 'L', ans, vis, arr, n);
    }
    
    // R
    if (isPossibleMove (x, y+1, vis, arr, n)){
        solve(x, y+1, str + 'R', ans, vis, arr, n);
    }
    
    // U
    if (isPossibleMove (x-1, y, vis, arr, n)){
        solve(x-1, y, str + 'D', ans, vis, arr, n);
    }

    vis[x][y] = 0;
}

vector <string> ratInaMaze (vector<vector<int>> &arr, int n){
    vector<vector<bool> > isVisited (n, vector<bool>(n,0));     // vector <vector<data_type>> vec (row, vector<data_type> (col, intial_value)) 
    vector<string> ans;
    string path = "";
    if (arr[0][0] == 0)
        return ans;

    solve (0, 0, path, ans, isVisited, arr, n);
    return ans;
}

// TC = 4^(N^2), bcz from a certain posn., 4 calls can be done, and in each call N^2 blocks will be visited in the worst case
// SC = O(N*M)

int main (){
    
return 0;
}