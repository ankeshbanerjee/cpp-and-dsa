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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        for (auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        // intuition is to make union of the rows with cols which hold stones
        // nodes of the disjoint set represents the number of rows and cols
        DisjointSet ds(maxRow + maxCol + 1); // '+1' for safety purposes (no need actually)

        // using set to store those rows and cols, which are involved in holding stones
        unordered_set <int> stoneNodes;
        for (auto it : stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            ds.unionBySize(row, col);
            stoneNodes.insert(row);
            stoneNodes.insert(col);
        }

        int cnt = 0;
        for (auto it: stoneNodes){
            if (ds.findUltimateParent(it) == it)cnt++;
        }
        
        return n - cnt;
    }
};