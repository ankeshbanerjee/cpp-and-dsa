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