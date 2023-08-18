#include <bits/stdc++.h>
using namespace std;

// question has asked to return ans in lexicographically sorted order
// so, calling functions in the order -> D -> L -> R -> U (lexicographically sorted)

class Solution{
    private:
    void solve(int row, int col, string &path, vector<vector<int>> &vis, vector<vector<int>> &m, int n, vector<string> &ans){
        // base case
        if (row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        
        vis[row][col] = 1;
        
        // D
        if (row+1<n && m[row+1][col] == 1 && !vis[row+1][col]){
            path.push_back('D');
            solve(row+1, col, path, vis, m, n, ans);
            path.pop_back();
        }
            
        // L
        if (col-1>=0 && m[row][col-1] == 1 && !vis[row][col-1]){
            path.push_back('L');
            solve(row, col-1, path, vis, m, n, ans);
            path.pop_back();
        }
        
        // R
        if (col+1<n && m[row][col+1] == 1 && !vis[row][col+1]){
            path.push_back('R');
            solve(row, col+1, path, vis, m, n, ans);
            path.pop_back();
        }
        
        // U
        if (row-1>=0 && m[row-1][col] == 1 && !vis[row-1][col]){
            path.push_back('U');
            solve(row-1, col, path, vis, m, n, ans);
            path.pop_back();
        }
        
        vis[row][col] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1)
            solve (0, 0, path, vis, m, n, ans);
        return ans;
    }
};


// write less code
// avoiding if conditions in solve function
class Solution{
    private:
    void solve(int row, int col, string &path, vector<vector<int>> &vis, vector<vector<int>> &m, int n, 
    vector<string> &ans, int drow[], int dcol[]){
        // base case
        if (row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        
        vis[row][col] = 1;
        
        string move = "DLRU";
        for (int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && m[nrow][ncol] == 1 && !vis[nrow][ncol]){
                path.push_back(move[i]);
                solve(nrow, ncol, path, vis, m, n, ans, drow, dcol);
                path.pop_back();
            }
        }
        
        vis[row][col] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // maintain DLRU pattern
        int drow[4] = {+1, 0, 0, -1};
        int dcol[4] = {0, -1, +1, 0};
        if (m[0][0] == 1)
            solve (0, 0, path, vis, m, n, ans, drow, dcol);
        return ans;
    }
};

// time complexity = O(4^(n*n))
// coz, there are 4 movements for each (row, col)
// and there are (n*n) no. of such states
// so, 4*4*4*4*.....(n*n) times = 4^(n*n)

// space complexity = O(n*n)
// coz, the maximum depth of the recursion tree is (n*n)