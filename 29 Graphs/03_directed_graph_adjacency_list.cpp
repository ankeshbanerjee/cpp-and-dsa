#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, m; 
    cin >> n >> m;
    vector <int> adj[n+1];
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    
        // in directed graphs, v is neighbour of u, but that doesn't mean that u is neighbour of v
    }
return 0;
}