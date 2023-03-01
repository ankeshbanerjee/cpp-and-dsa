//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // DFS can be used but to get the taste of BFS, solving using BFS
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int>(m, 0));
        queue <pair<int, int>> q;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        // multisource BFS
        for (int i =0; i<n; i++){
            for (int j=0; j<m; j++){
                // traversing the boundaries (first row, last row, first col, last col)
                if (i==0 || i == n-1 || j == 0 || j == m-1){
                    if (grid[i][j] == 1){
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traversing 4 directions for neighbours
            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
            }
        }

        // all the routes to reach boundary are marked visited by the above bfs
        // so, the ans is the count of the non-visited lands
        int count = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (!vis[i][j] && grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};

// TC = O(N*M*4) = O(N*M) : at worst case all are lands(1) (N*M) and each of them has 4 neighbours (4*N*M)
// SC = O(N*M) : for vis array


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends