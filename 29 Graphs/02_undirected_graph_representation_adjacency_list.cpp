#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    // here we'll use an array of size n+1 (for 1 based indexing), whose elements are vector <int> typed
    // every index of that array will store the neighbouring elements of it
    vector <int> adj[n+1];
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    // in undirected graphs, v is neighbour of u,
        adj[v].push_back(u);    // besides u is neighbour of v, simultaneously
    }
    // TC = O(M), SC = O(2E), bcz, in undirected graphs every edge has two nodes,
    // and there are 2E elements stored in vector <int> adj[n+1] this data structure
    // Note : here E = M
return 0;
}