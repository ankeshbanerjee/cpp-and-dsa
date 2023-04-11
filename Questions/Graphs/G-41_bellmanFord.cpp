#include <bits/stdc++.h>
using namespace std;

// Bellman ford algorithm : 
// it helps to detect negative cycles, which is dijkstra's algo is unable to do.
// it is valid for directed graph. if undirected graph is given, then store the edges as directed graph, i.e., u-v => u->v & v->u

// algorithm:
// Relax all the edges for N-1 times
// Relaxation => if (dist[u] + wt < dist[v])dist[v] = dist[u] + wt;

// why N-1 times?
// in N-1 iterations we will get the dist array, in each iteration we will be able to get the shortest of a new node
// In a graph of N nodes, in worst case, you will take N-1 edges to reach from the first to the last,
// thereby iterate for N-1 iterations

// Try drawing a graph which takes more than N-1 edges for any path, it is not possible.

// How to detect Negative cycle?
// we should be able to get the final dist array by the N-1 iterations
// if a negative cycle is present, then dist should decrease after every iteration.
// so, even after N-1 iterations, if we do another iteration (Nth iteration)
// and notice that dist changes, then will be sure about the presence of negative cycle.

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    vector <int> dist (V, 1e8);
    dist[S] = 0;
    
    for (int i=0; i<V-1; i++){
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    
    // N relaxation for detecting negative cycle
    for (auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    
    return dist;
}


// TC = O(V*E) = quadratic time complexity