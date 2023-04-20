#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  class DisjointSet {
    public: 
    vector <int> rank, parent, size;
    // constructor
    DisjointSet (int n){
        parent.resize(n+1); 
        rank.resize(n+1, 0); // n+1 so that it can be used for both 0 and 1 based indexing
        size.resize(n+1, 1); // intially every node is a component of size 1

        for (int i=0; i<n+1; i++)parent[i] = i;
    }

    int findUltimateParent(int u){
        // base case
        if (parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)return;

        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)return;

        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    };
  
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        // step 1 : connect the nodes in the form of disjoint set
        for (int row = 0; row < n; row++){
            for (int col=0; col < n; col++){
                if (grid[row][col] == 0)continue;
                int dr[4] = {1, 0, -1, 0};
                int dc[4] = {0, 1, 0, -1};
                for (int i=0; i<4; i++){
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];
                    if (adjRow >=0 && adjRow < n && adjCol >=0 && adjCol < n
                    && grid[adjRow][adjCol] == 1){
                        int nodeNo = row*n + col;
                        int adjNodeNo = adjRow * n + adjCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // step 2 : go to all the zeros and try to convert them in 1
        int mx = INT_MIN;
        for (int row = 0; row < n; row++){
            for (int col=0; col < n; col++){
                if (grid[row][col] == 1)continue;
                int dr[4] = {1, 0, -1, 0};
                int dc[4] = {0, 1, 0, -1};
                unordered_set<int> adjComponents;
                for (int i=0; i<4; i++){
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];
                    if (adjRow >=0 && adjRow < n && adjCol >=0 && adjCol < n
                    && grid[adjRow][adjCol] == 1){
                        int adjNodeNo = adjRow * n + adjCol;
                        adjComponents.insert(ds.findUltimateParent(adjNodeNo));
                    }
                }
                int sizeTotal = 0;
                for (auto it : adjComponents){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        for (int node = 0; node < n*n ; node++){
            mx = max(mx, ds.size[ds.findUltimateParent(node)]);
        }

        return mx;
    }
};

// TC = O(N^2)
// SC = O(N^2)