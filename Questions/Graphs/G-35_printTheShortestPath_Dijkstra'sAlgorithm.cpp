#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector <pair <int, int>> adj[n+1];
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue <pair<int, int>, 
        vector<pair<int, int>>, greater <pair<int, int>>> pq;
        vector <int> dist(n+1, 1e9), parent(n+1);
        int src = 1;
        dist[src] = 0;
        pq.push({0, src});
        for (int i=0; i<n+1; i++)parent[i] = i;
        
        while (!pq.empty()){
            auto temp = pq.top();
            int dis = temp.first;
            int node = temp.second;
            pq.pop();
            
            for (auto it : adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if (dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        if (dist[n] == 1e9) return {-1};
        vector <int> path;
        int node = n;
        
        while (parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }
};
