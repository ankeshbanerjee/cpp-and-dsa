// slight modifications in the solution of the problem - critical connections in a graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;
    void dfs (int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<int> &mark){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]){
            if (!vis[it]){
                dfs(it, node, adj, vis, tin, low, mark);
                low[node] = min(low[node], low[it]);
                // check for articulation point
                if (low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        // O(4V) -> space
        vector <int> vis (V, 0);
        int tin[V]; // stores the insertion time during dfs
        int low[V]; // minimum of all adjacent nodes' insertion time apart from parent and visited ones
        vector <int> mark(V, 0);
        // O(V + E) -> time (for dfs)
        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }
        // O(V) -> space
        vector <int> ans;
        // O(V) -> time
        for (int i=0; i<V; i++){
            if (mark[i] == 1)ans.push_back(i);
        }
        if (ans.size() == 0)return {-1};
        return ans;
    }
};