#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck (int node, vector<int> adj[], vector <int> &vis, vector <int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for (auto it : adj[node]){
            if (!vis[it]){
                if (dfsCheck(it, adj, vis, pathVis)) return true;
            }
            else if (pathVis[it]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector <int> vis(V, 0);
        vector <int> pathVis(V, 0);
        for (int i=0; i<V; i++){
            if (!vis[i]){
                if (dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

// TC = O(V+E), bcz directed graph
// SC = O(V)
