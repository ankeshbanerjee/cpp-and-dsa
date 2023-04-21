#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
int timer = 1;
void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, 
            int tin[], int low[], vector<vector<int>> &bridges){

    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for (auto it : adj[node]){
        if (it == parent)continue;
        if (vis[it] == 0){
            dfs(it, node, adj, vis, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            // checking for bridge or not
            if (low[it] > tin[node]){ // condition of the edge being a bridge
                bridges.push_back({it, node});
            }
        }
        else{
            low[node] = min(low[node], low[it]);
        }
    }
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <int> adj[n]; // O(V + 2E) ->space
        for (auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // O(3N) -> space
        vector <int> vis(n, 0);
        int tin[n]; // time of insertion in DFS
        int low[n]; // lowest insertion time of all adjacent nodes apart from parent
        vector<vector<int>> bridges;
        dfs (0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};

// TC = O(V+2E) -> time complexity of dfs
// SC = O(V+2E) + O(3V)