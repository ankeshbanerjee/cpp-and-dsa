#include <bits/stdc++.h>
using namespace std;

/*
intuition:

1. reverse the edges : 
safenodes are those who lead to terminal nodes. terminal nodes are those who have 0 outdegree
but as we know, topo sort considers dealing with indegrees, and we need to push those nodes into the queue who have 0 indegree
so, to solve using topo sort we reverse the edges, so that outdegrees get converted to indegrees, 
so, the terminal nodes now have 0 indegree and they can be pushed into the queue

2. use normal topo sort to get the ans vector.
sort the vector before returning the ans, as the elements get stored in random order

though, it is better to solve it using dfs, as here extra O(nlogn) time is required to sort the ans vector
and also extra space for reversed adj list, indegree is needed.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // using bfs (topo sort)
        
        // step 1 : reverse the edges of the graph
        int n = graph.size();
        vector <int> adj1[n];
        for (int i=0; i<n; i++){
            // before : i -> it
            // task : it -> i
            for (auto it : graph[i]){
                adj1[it].push_back(i);
            }
        }

        // topo sort
        vector <int> indegree (n, 0);
        for (int i=0; i<n; i++){
            for (auto it : adj1[i]){
                indegree[it]++;
            }
        }

        queue <int> q;
        for (int i=0; i<n; i++){
            if (indegree[i]==0)q.push(i);
        }

        vector <int> topo;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj1[node]){
                indegree[it]--;
                if (indegree[it]==0)q.push(it);
            }
        }

        sort (topo.begin(), topo.end());
        return topo;
    }
};