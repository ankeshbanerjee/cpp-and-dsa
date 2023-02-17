#include <bits/stdc++.h>
using namespace std;

int main (){
    // input format
    // 5 6 // n m
    // 1 2 // following inputs are for edges
    // 1 3
    // 2 4
    // 3 4
    // 3 5
    // 4 5

    int n, m; // n nodes, m edges
    cin >> n >> m;

    // creating matrix for storing graphs (using 1 based indexing)
    int adj[n+1][n+1];

    // mark the inputs given in the qs as one
    // 1 2 means there is an edge between 1 and 2, so this is same as if we say there is an edge between 2 and 1
    // so, mark adj[1][2] = 1 and adj[2][1] = 1

    for (int i=0; i<m; i++){ // there are m columns in the input regarding edges, so loop is run m times
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // TC = O(M), SC = O(N*N)
return 0;
}