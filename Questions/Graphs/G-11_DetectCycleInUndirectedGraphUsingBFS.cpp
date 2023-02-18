#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detectCycle (int src, int vis[], vector<int> adj[]){
        vis[src] = 1;
        queue <pair<int,int>> q; // {node, parent}
        q.push({src, -1});
        
        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto it: adj[node]){
                if (!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        // for graphs with multiple components
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if (detectCycle (i, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

/*
TC = O(N+2E) : consider the adj matrix, for each vertex, bfs will run for its degrees, and total degree is 2E
and total no. of vertices is N, so, N + 2E

SC = O(N) : for using queue, vis array
*/

int main (){
    
return 0;
}