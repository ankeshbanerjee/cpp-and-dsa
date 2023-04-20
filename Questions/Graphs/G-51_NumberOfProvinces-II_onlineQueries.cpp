#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  class DisjointSet {
    vector <int> rank, parent, size;
    public: 
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
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds (n*m);
        int vis[n][m];
        int cnt = 0;
        memset (vis, 0, sizeof(vis));
        vector <int> ans;
        for (auto it : operators){
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            cnt++;
            vis[row][col] = 1;
            int delrow[] = {1, 0, -1, 0};
            int delcol[] = {0, 1, 0, -1};
            for (int i = 0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >=0  && ncol < m){
                    if (vis[nrow][ncol] == 1){  // if the adjacent node is an island
                        int nodeNo = row*m + col;
                        int adjNodeNo = nrow*m + ncol;
                        if (ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo)){
                            ds.unionBySize(nodeNo, adjNodeNo);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        };
        
        return ans;
    }
};
