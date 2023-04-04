#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // using min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector <int> dist(V);
        for (int i=0; i<V; i++)dist[i] = 1e9;
        
        dist[S] = 0;
        pq.push({0, S});
        
        while (!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if (dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};

// dijkstra's algorithm is not valid if there is any -ve weighted edge, or a cycle of -ve weight
// reason : watch striver's lecture 32

// TC : ElogV