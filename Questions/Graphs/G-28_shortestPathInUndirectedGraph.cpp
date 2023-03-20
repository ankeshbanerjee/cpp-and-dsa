// as all the edges are unit weighted, there is no need to use any other standard algorithm to get any sorted ordering to solve
// so, bfs is used to solve this in O(N+M), which is less compared to other standard algorithms
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here

        // solving using bfs
        // creating the adj list
        vector <int> adj[N];
        for (int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int dist[N];
        for (int i=0; i<N; i++) dist[i] = 1e9;
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            for (auto it: adj[node]){
                if (dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        
        vector <int> ans (N, -1);
        for (int i=0; i<N; i++){
            if (dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        
        return ans;
    }
};