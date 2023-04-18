#include<bits/stdc++.h>
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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map <string, int> mapMailNode;
        int n = accounts.size();
        DisjointSet ds(n);
        // step 1 : create the map and disjoint set
        for (int i=0; i<n; i++){
            for (int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // step 2 : store it in the mergedMail array
        vector<string> mergedMail[n];
        for (auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findUltimateParent(it.second);
            mergedMail[node].push_back(mail);
        }

        // step 3 : make the ans vector
        vector<vector<string>> ans;
        for (int i=0; i<n; i++){
            if (mergedMail[i].size() == 0)continue;
            else{
                sort(mergedMail[i].begin(), mergedMail[i].end());
                vector <string> temp;
                temp.push_back(accounts[i][0]);
                for (auto it : mergedMail[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};