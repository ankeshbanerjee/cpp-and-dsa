#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check  (int start, vector<vector<int>>& graph, vector<int> &color){
        queue <int> q;
        q.push(start);

        while (!q.empty()){
            int node = q.front();
            q.pop();

            for (auto it : graph[node]){
                // if not colored
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // adjacing node having same color as that of current node
                else if (color[it] == color[node])return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector <int> color (v, -1);

        // checking for all the components
        for (int i=0; i<v; i++){
            // if not colored
            if (color[i] == -1){
                if (!check(i, graph, color)) return false;
            }
        }
        return true;
    }
};

// TC & SC = same as that of bfs
// TC = O(V+2E) SC = O(V)