#include <bits/stdc++.h>
using namespace std;

void bfs (int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue <pair<int, int>> q;
    vis[row][col] = 1;
    q.push({row, col});
    
    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // checking for the neighbours and marking them as visited
        for (int delrow = -1; delrow <= 1; delrow++){
            for (int delcol = -1; delcol <= 1; delcol++){
                int newrow = row + delrow;
                int newcol = col + delcol;
                if (newrow >=0 && newrow < n && newcol >=0 && newcol < m
                && !vis[newrow][newcol] && grid[newrow][newcol] == '1'){
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }
}

int numIslands (vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis (n, vector<int>(m, 0));
    int count = 0;
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            if (!vis[row][col] && grid[row][col] == '1'){
                count++;
                bfs(row, col, vis, grid);
            }
        }
    }
}

/*
SC = O(N^2) (for visited matrix) + O(N^2) (for queue in worst case, where every node is marked '1') == O(N^2)

in worst case all the nodes all marked as 1, then bfs will be called once
in that call, it will visit everyone, which takes N*M*9 (coz, for each node it will check for 9 neighbours (8 neighbours and the node itself))

and in worst case, the outer loop will run N*M times to find the first '1'
so, TC = O(N*M) (for outer loop in worst case) + O(N*M*9) (for bfs call in worst case where all are marked '1') 
which is near equal to, TC = O(N*M)

or, in other words, we can say that we are visiting each node once, so the complexity is O(N*M)
*/

int main (){
    
return 0;
}