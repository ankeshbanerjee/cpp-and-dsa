/*
Intuition:
Kahn's Algorithm is only valid for DAG (directed acyclic graphs)
In DAGs the size of the ans vector is equal to the number of nodes in the graph
but, if the graph is cyclic, then the size of the ans vector will be less than the number of nodes in the graph
so, here we are just keeping a count of the nodes which are eligible to be pushed in the ans vector
if cnt == V, then it is acyclic graph, so return false
if cnt < V, then it contains cycle, so return true
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // using topo sort (BFS / Kahn's algorithm)
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector <int> indegree (V, 0);
        for (int i=0; i<V; i++){
            for (auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue <int> q;
        for (int i=0; i<V; i++){
            // pushing those nodes into the queue, whose indegrees are 0
            if (indegree[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for (auto it: adj[node]){
	            // when pushed into ans vector, the edges of that node are considered to be no more there
	            // so, the indegrees of the neighbours of that will reduce by 1
                indegree[it]--;
                if (indegree[it]==0) q.push(it);
            }
        }
        
        return (cnt == V) ? false : true;
    }
};
