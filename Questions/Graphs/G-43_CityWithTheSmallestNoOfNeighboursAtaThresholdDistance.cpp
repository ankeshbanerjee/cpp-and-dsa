#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        
        // using Floyd Warshall 
        vector<vector<int>> matrix (n, vector<int> (n, 1e9));
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];  
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
            
        for (int i=0; i<n; i++)matrix[i][i] = 0;
        
        // apply algorithim
        for (int via = 0; via < n; via++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (matrix[i][via] == 1e9 || matrix[via][j] == 1e9) continue;
                    if (matrix[i][via] + matrix[via][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][via] + matrix[via][j];
                    }
                }
            }
        }
        
        int minCityConnections = n;
        int cityNo = -1;
        
        for (int city=0; city<n; city++){
            int cnt = 0;
            for (int adjCity=0; adjCity<n; adjCity++){
                if (matrix[city][adjCity] <= distanceThreshold)
                    cnt++;
            }
            
            if (cnt <= minCityConnections){
                minCityConnections = cnt;
                cityNo = city;
            }
        }
        
        return cityNo;
    }
};
// TC = O(N^2)
// SC = O(N^2)


// using dijkstra's algorithm :

class Solution {
private:
    void dijkstra (int src, int n, vector<pair<int, int>> adj[], vector <vector<int>> &matrix){
        // {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater <pair<int, int>> > pq;
        vector <int> dist (n, 1e9);
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()){
            auto temp = pq.top();
            int dis = temp.first;
            int node = temp.second;
            pq.pop();
            
            for (auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                
                if (dist[node] + edW < dist[adjNode]){
                    dist[adjNode] = dist[node] + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        matrix[src] = dist;
    }
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
        vector <pair<int, int>> adj[n];
        for (auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector <vector<int>> matrix (n, vector<int> (0));
        for (int city=0; city<n; city++){
            dijkstra(city, n, adj, matrix);
        }
        
        int minCityConnections = n;
        int cityNo = -1;
        
        for (int city=0; city<n; city++){
            int cnt = 0;
            for (int adjCity=0; adjCity<n; adjCity++){
                if (matrix[city][adjCity] <= distanceThreshold)
                    cnt++;
            }
            
            if (cnt <= minCityConnections){
                minCityConnections = cnt;
                cityNo = city;
            }
        }
        
        return cityNo;
    }
};


// TC = O(N*ElogV + N^2) = O(N*MlogN + N^2)
// SC = O(N^2)