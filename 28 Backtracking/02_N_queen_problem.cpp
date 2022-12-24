// approach : 
// place one queen in each column,
// place one queen in each row,
// make sure no queens attack each other (attack is possible in same rows, columns, and diagonals)

// check for every row of the first column, remaing board will be solved by recursion

#include <bits/stdc++.h>
using namespace std;

void addSolution (vector<vector <int>> &ans, vector <vector<int>> &boards, int n){
    vector <int> temp;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            temp.push_back(boards[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe (int row, int col, vector <vector<int>> &boards, int n){
    int x = row;
    int y = col;

    // we don't need to check for the right part, bcz we are going from left to right, so right part is not filled, so no need to check

    // check for row
    while (y >= 0){
        if (boards[x][y] == 1)
            return false;
        y--;
    }

    // we don't need to check for column, bcz once we place a Q in a col, then we make our next call for the next col
    // so, no two Qs can be placed in the same col

    // check for diagonals
    // upper diagonal
    x = row;
    y = col;

    while (x >= 0 && y >= 0){
        if (boards[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // Lower diagonal
    x = row;
    y = col;

    while (x < n && y >= 0){
        if (boards[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}
// optimization: use maps in isSafe function for O(1) complexity instead of O(n), while checking for row and diagonals (see codehelp L-83) (code commented below)

void solve (int col, vector <vector<int>> &boards, vector<vector <int>> &ans, int n){
    // base case
    if (col == n){
        addSolution (ans, boards, n); // to convert boards into 1-D array and store into ans
        return;
    }

    // solve for all the rows in the first col, rest will be taken care by recurssion
    for (int row = 0; row < n; row ++){
        if (isSafe(row, col, boards, n)){
            boards[row][col] = 1; // place the queen by marking as 1
            solve (col+1, boards, ans, n);  // after placing check for the rest of the board
            // backtrack
            boards[row][col] = 0; // while returning it has been made zero, to check for the other possible solutions
        }
    }
}

/*

bool isSafe (int row, int col, vector <vector<int>> &boards, int n, map <int, bool> &mr, map <int, bool>&mdu, map <int, bool>&mdd){
    if (mr[row] == true)
        return false;
    else if (mdd[row+col] == true)
        return false;
    else if (mdu[n-1+col-row] == true)
        return false;
    else
        return true;
}


void solve (int col, vector <vector<int>> &boards, vector<vector <int>> &ans, int n, map <int, bool> &mr, map <int, bool>&mdu, map <int, bool>&mdd){
    // base case
    if (col == n){
        addSolution (ans, boards, n);
        return;
    }

    for (int row = 0; row < n; row ++){
        if (isSafe(row, col, boards, n, mr, mdu, mdd)){
            boards[row][col] = 1;
            mr[row] = true;
            mdd[row+col] = true;
            mdu[n-1+col-row] = true;
            solve (col+1, boards, ans, n, mr, mdu, mdd); 
            // backtrack
            boards[row][col] = 0;
            mr[row] = false;
            mdd[row+col] = false;
            mdu[n-1+col-row] = false;
        }
    }
}

*/

vector <vector<int> > nQueen (int n){
    vector <vector<int>> boards (n, vector<int>(n,0));
    vector<vector <int>> ans;
    int col = 0;

    /*
    // for using map in isSafe function
    map <int, bool>mr; // map for cheking row
    map <int, bool>mdd; // map for checking down-left diagonal
    map <int, bool>mdu; // map for checking upper-left diagonal
    // solve (col, boards, ans, n, mr, mdu, mdd);
    */

    solve (col, boards, ans, n);
    return ans;
}

// TC = n!
// SC = n*n

int main (){
    
return 0;
}
