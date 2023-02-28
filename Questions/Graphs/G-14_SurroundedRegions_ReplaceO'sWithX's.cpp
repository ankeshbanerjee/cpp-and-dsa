#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs (int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board,
        int delrow[], int delcol[], int n, int m){

            vis[row][col] = 1;
            // neighbours
            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                        dfs (nrow, ncol, vis, board, delrow, delcol, n, m);
                    }
            }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis (n, vector<int>(m, 0));
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        // check for boundary O's

        // first row
        for (int i=0; i<m; i++){
            if (!vis[0][i] && board[0][i] == 'O'){
                dfs(0, i, vis, board, delrow, delcol, n, m);
            }
        }
        // last row
        for (int i=0; i<m; i++){
            if (!vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(n-1, i, vis, board, delrow, delcol, n, m);
            }
        }
        // first column
        for (int i=0; i<n; i++){
            if (!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board, delrow, delcol, n, m);
            }
        }
        // last row
        for (int i=0; i<n; i++){
            if (!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, vis, board, delrow, delcol, n, m);
            }
        }

        // replacing the elgible O's with X's
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};