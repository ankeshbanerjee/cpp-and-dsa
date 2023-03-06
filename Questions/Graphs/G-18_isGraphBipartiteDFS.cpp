#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check  (int node, vector<vector<int>>& graph, vector<int> &color){
        // using DFS
        for (auto it : graph[node]){
            // if not colored
            if (color[it] == -1){
                color[it] = !color[node];
                if (!check (it, graph, color)) return false;
            }
            else if (color[it] == color[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector <int> color (v, -1);
        for (int i=0; i<v; i++){
            // if not colored
            if (color[i] == -1){
                color[i] = 0;
                if (!check(i, graph, color)) return false;
            }
        }
        return true;
    }
};

// TC & SC : same as that of DFS