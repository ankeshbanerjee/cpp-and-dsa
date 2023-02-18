#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs (int node, int parent, int vis[], vector <int> adj[]){
        vis[node] = 1;
        for (auto adjacentNode : adj[node]){
            if (!vis[adjacentNode]){
                if (dfs(adjacentNode, node, vis, adj))
                    return true;
            }
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for (int i=0; i<V; i++){
            if (!vis[i]){
                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }
        
        return false;
    }
};

// TC = O(N + 2E) : dfs will run for each neighbour of every node, total no. of neighbours is 2E, and total no. of nodes is N, so N+2E
// SC = O(N) : recursive stack space and vis array

int main (){
    
return 0;
}