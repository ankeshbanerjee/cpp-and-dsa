#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // approach will be same as dijkstra's with a little modification by introducing ways
        // adj list
        vector <pair <int, int>> adj[n];
        for (auto it : roads){
            int u = it[0];
            int v = it[1];
            int edge = it[2];
            adj[u].push_back({v, edge});
            adj[v].push_back({u, edge});
        }

        vector <int> dist(n, 1e9), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        // {dist, node}
        priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);

        while (!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it: adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};

// TC = E log V