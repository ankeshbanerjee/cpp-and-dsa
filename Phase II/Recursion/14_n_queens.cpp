#include <bits/stdc++.h>
using namespace std;

// isSafe function -
// though, a queen can attack in all the 8 directions
// but here we have to check for only 3 directions
// coz, we are going from left to right, so, no need to take care of 3 right directions (right upper diag, right row, right lower diag)
// and, as we are placing only one queen in a col, so, no need of extra check of upper and lower direction
// so, we have to check for only remaining three directions (left upper diag, left row, left lower diag)

class Solution {
private:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int r = row;
        int c = col;

        // check for upper left diagonal
        row = row-1, col = col-1;
        while (row>=0 && col>=0){
            if (board[row][col] == 'Q')return false;
            row--, col--;
        }

        // check for left row
        row = r, col = c;
        while (col>=0){
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // check for lower left diagonal
        row = r, col = c;
        while (row<n && col>=0){
            if (board[row][col] == 'Q') return false;
            row++, col--;
        }

        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        // base case
        if (col == n){
            ans.push_back(board);
            return;
        }
        for (int row = 0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve (0, board, ans, n);
        return ans;
    }
};


// optimised approach
// instead of O(3*n) loop isSafe function,
// we can use hashing (some hash arrays) to do the same
class Solution {
private:
    void solve(int col, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, 
        vector<int> &lowerDiagonal, vector<vector<string>> &ans, int n){
        // base case
        if (col == n){
            ans.push_back(board);
            return;
        }
        for (int row = 0; row<n; row++){
            if(leftRow[row] != 1 && lowerDiagonal[row+col] != 1 && upperDiagonal[n-1 + col-row] != 1){
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col-row] = 1;
                board[row][col] = 'Q';
                solve(col+1, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col-row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal (2*n-1, 0);
        vector<int> lowerDiagonal (2*n-1, 0);
        solve (0, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
        return ans;
    }
};