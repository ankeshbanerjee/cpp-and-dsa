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
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if (detectCycle (i, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

int main (){
    
return 0;
}