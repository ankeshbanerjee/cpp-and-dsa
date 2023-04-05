#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if (destination.first == source.first &&
            destination.second == source.second) return 0;
            
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist (n, vector <int> (m, 1e9));
        dist[source.first][source.second] = 0;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        queue <pair<int, pair<int, int>> > q;
        q.push({0, {source.first, source.second}});
        
        while (!q.empty()){
            auto temp = q.front();
            int dis = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            q.pop();
            
            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]){
                   dist[nrow][ncol] = dis + 1;
                   if (nrow == destination.first && ncol == destination.second) 
                        return dis + 1;
                   q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        
        return -1;
    }
};
