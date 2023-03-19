/*

Algorithm:
1. Topo sort the graph 
2. pop the top element from the stack and relax the edges

Intuition:
here topo sort has been used, after getting the linear ordering, we can move sequentially according to reachability
so, the no. of steps is reduced and it is solved in O(N+M), which is less than any other standard algorithm like Dijkstra's algorithm

how it happens?
suppose the topo sort is : 6 5 4 2 0 1 3
so, assume, we reached 4. that means we can only reach 4 from 6 and 5, not from 2, 0, 1 or 3 (elements after 4)
and the result for 6 and 5 is already computed.
that means if we are reaching a node, the previous nodes already have their answers
so, after getting the topo sorted ordering, we don't need to check for each and every other element for one node.
which reduces the no. of steps or iterations.

in short, Whenever you examine the node n in a topological ordering, you have the guarantee that you've already traversed every possible path to n.
Using this it's clear to see that you can generate the shortest path with one linear scan of a topological ordering

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
     void topoSort (int node, vector <pair<int, int>> adj[], int vis[], stack<int> &st){
         vis[node] = 1;
         for (auto it : adj[node]){
             if (!vis[it.first]){
                 topoSort (it.first, adj, vis, st);
             }
         }
         st.push(node);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        // create the adjacency list
        vector <pair<int, int>> adj[N];
        for (int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // step 1 : topo sort using dfs
        stack <int> st;
        int vis[N] = {0};

        // O(N+M)
        for (int i=0; i<N; i++){
            if (!vis[i]){
                topoSort (i, adj, vis, st);
            }
        }
        
        // step 2 : do the distance thing
        vector <int> dist(N);
        for (int i=0; i<N; i++) dist[i] = 1e9;
        dist[0] = 0;

        // O(N+M)
        while (!st.empty()){
            int node = st.top();
            st.pop();
            
            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for (int i=0; i<N; i++){
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};

