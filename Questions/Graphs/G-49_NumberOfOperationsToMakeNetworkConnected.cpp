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

    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : connections){
            int u = it[0];
            int v = it[1];
            int cntExtra = 0;
            if (ds.findUltimateParent(u) == ds.findUltimateParent(v)){
                cntExtras++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        
        int cntComponents = 0;
        for (int i=0; i<n ;i++){
            if(ds.parent[i] == i)cntComponents++;
        }

        int ans = cntComponents - 1;
        if (cntExtras >= ans)return ans;
        else return -1;
    }
};