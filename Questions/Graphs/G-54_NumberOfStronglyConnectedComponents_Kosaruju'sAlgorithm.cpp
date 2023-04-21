// strongly connected components : a component is a strongly connected component, if each node of that component is reachable to every other node in that component

// there are 3 steps in Kosaruju's algorithm to find the number of strongly connected components;
// step 1 : sort all the edges of the graph, according to their finishing time
// (why ? upon sorting, we will be able to get the node of the first strongly connected component)
// step 2 : reverse all the edges
// step 3 : perform dfs until the stack gets empty

// intuition : 
// first focus on the second step
// the reason of reversing the edges in simple
// suppose initially it was : scc1 -> scc2 -> scc3 -> scc4
// in such a condition if i perform a dfs, i will end up visting all nodes
// now if I reverse the edges, then scc1 <- scc2 <- scc3 <- scc4
// so, after reversing the edges, I can't go to scc2 from scc1, or scc3 from scc2 and so on.
// then I have to only just count the number of dfs call made in the outer loop
// and another thing, reversing all the edges will not affect the inner nodes of a scc, because inside a scc, each node is reachable to every other node
// so, even after reversing, they will still be reachable to each other.

// now, there is only one doubt remaining, that is,
// even after reversing the edges, I can see that if I start dfs from such a node which belongs to scc4 (scc1 <- scc2 <- scc3 <- scc4),
// then I wlll end up visiting all the nodes in the graph and I will not get my answer.
// so how to know from which node to start the the dfs?
// that why, in the first step, We have sorted all the edges according to their finishing time
// this ensures that, after sorting, the element placed at the stack top, is a part of the first strongly connected component (scc1)
// so, we can start dfs from that

// now in the final step, we have to just count the number of dfs calls we are making from the outer loop, which is the no. of scc in the graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void dfs (int node, vector <int> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = 1;
        for (auto it : adj[node]){
            if (!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    void dfs3 (int node, vector<int>adjT[], vector <int> &vis){
        vis[node] = 1;
        for (auto it : adjT[node]){
            if (!vis[it]){
                dfs3(it, adjT, vis);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // step 1
        // O(V) + O(V) ->space
        vector <int> vis(V, 0);
        stack <int> st;
        // O(V+E) -> time (for dfs)
        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        // step 2
        // O(V+E) -> space
        vector<int> adjT[V];
        // O(V+E) -> time
        for (int i=0; i<V; i++){
            // reseting the vis array to reuse it
            vis[i] = 0;
            for (auto it : adj[i]){
                // it->i
                adjT[it].push_back(i);
            }
        }
        
        // step 3
        int scc = 0;
        // O(V+E) -> time (for dfs again)
        while (!st.empty()){
            int node = st.top();
            st.pop();
            
            if (!vis[node]){
                scc++;
                dfs3(node, adjT, vis);
            }
        }
        
        return scc;
    }
};