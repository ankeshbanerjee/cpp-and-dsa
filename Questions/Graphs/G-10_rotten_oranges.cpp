#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cntfresh = 0;
        
        queue <pair<pair<int,int>, int>> q;
        int vis[r][c]; 
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    if (grid[i][j] == 1){
                        cntfresh++;
                    }
                    vis[i][j] = 0;
                }
            }
        }
        
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        int time = 0;
        int cnt = 0;
        while (!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = t;
            q.pop();
            
            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c &&
                   vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    cnt++;
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        
        return (cnt != cntfresh) ? -1 : time;
        
    }
};

/*
Here using bfs, bcz we have process level wise, i.e., all the rotten oranges will rotten its neighbours simultaneously
i.e., all the neighbours of the same level will be rottened simultaneously
but dfs, would've done that one by one, not simultaneuosly

TC & S.C = O(N*M)
*/

int main (){
    
return 0;
}