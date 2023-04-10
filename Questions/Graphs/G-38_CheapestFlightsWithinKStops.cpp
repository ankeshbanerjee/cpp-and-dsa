#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // dijkstra's algorithm, 
        //but based on the no. of stops, not on the distance, like usual appraoch
        
        // adj list
        vector <pair<int, int>> adj[n];
        for (auto it : flights){
            int u = it[0];
            int v = it[1];
            int edgeWeight = it[2];
            adj[u].push_back({v, edgeWeight});
        }
        vector <int> dist (n, 1e9);
        dist[src] = 0; 
        // {stops, {node, dist}}
        // a queue will suffice, as the elements will be stored sequentially, 
        // in increasing order of no. of stops, so no need of priority queue
        queue<pair <int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();
            
            if (stops > K) continue; // to save some iterations
            for (auto it : adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (cost + edgeWeight < dist[adjNode] && stops <= K){
                    dist[adjNode] = cost + edgeWeight;
                    q.push({stops+1,{adjNode, dist[adjNode]}});
                }
            }
        }
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};

// TC = E = number of edges = flights.size()
// in dijkstra's algorithm, if a simple q is taken instead of a pq, then the TC is O(E)