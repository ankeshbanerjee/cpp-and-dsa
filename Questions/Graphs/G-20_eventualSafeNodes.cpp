#include <bits/stdc++.h>
using namespace std;

// main intution
// two conditions to fulfill to be a safe Node
// 1. the node should not be a part of a cycle
// 2. the node should not be leading to a cycle
// the below approach is almost same as the 'detect cycle in directed graph' problem, with just a few modifications

class Solution {
private:
    bool dfsCheck (int node, vector<vector<int>> &graph, vector<int> &vis,
             vector<int> &pathVis, vector<int> &safeCheck){
                 
        vis[node] = 1;
        pathVis[node] = 1;
        safeCheck[node] = 0;

        for (auto it: graph[node]){
            if (!vis[it]){
                if (dfsCheck (it, graph, vis, pathVis, safeCheck)) return true;
            }
            else if (pathVis[it]) return true;
        }

        safeCheck[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector <int> vis(V, 0);
        vector <int> pathVis(V, 0);
        vector <int> safeNodes;
        vector <int> safeCheck(V, 0);
        // for components
        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfsCheck (i, graph, vis, pathVis, safeCheck);
            }
        }

        for (int i=0; i<V; i++){
            if (safeCheck[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};