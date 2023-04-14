#include <bits/stdc++.h>
using namespace std;

// Spanning tree : Spanning tree is a tree with N nodes and N-1 edges, where each node is reachable to every other node
// Minimum spanning tree (MST) : MST is the spanning tree obtained from a given graph, whose sum of edges is 
// minimum among all the spanning trees, that can be obtained from that given graph

// Prim's Algorithm : to find the minimum spanning tree
// basic intuition : going to each node and find for the smallest edge, which is the basic greedy intuition
// so, Prim's algo is simply based on greedy intuition.

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // {wt, node}
        priority_queue <pair<int, int>, 
        vector <pair<int, int>>, greater<pair<int, int>> > pq;
        vector <int> vis(V, 0);
        int sum = 0;
        pq.push({0, 0});
        
        // E
        while (!pq.empty()){
            // log E
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (vis[node] == 1)continue;
            vis[node] = 1;
            sum += wt;
            
            // E log E
            for (auto it : adj[node]){
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode]){
                    pq.push({edW, adjNode});
                }
            }
        }
        
        return sum;
    }
};

// TC = E log E + E log E = O(E log E)
// SC = O(E)


// if we were asked to return the MST in the form of array (vector <pair<int, int>> MST), then
// the pq will be of pair <int, pair<int, int>> => {wt, {node, parent}};
// {parent, node} is to be pushed in the MST array just after this line in the above code : 'if (vis[node] == 1)continue;'
// return MST