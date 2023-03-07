/*
Intuition:
1. push all the nodes, having indegree 0, into the queue
2. take them out of the Queue one by one and decrease the indegree of the adjacent nodes by 1
3. and then if any of the adjacent nodes have its indegree = 0, then push it into the queue
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector <int> inDegree (V,0);
	    for (int i=0; i<V; i++){
	        for (auto it: adj[i]){
	            inDegree[it]++;
	        }
	    }
	    queue <int> q;
	    vector <int> ans;
	    for (int i=0; i<V; i++){
	        // pushing the nodes in Q, whose indegree is 0
	        if (inDegree[i] == 0)q.push(i);
	    }
	    
	    while (!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for (auto it : adj[node]){
	            // when pushed into ans vector, the edges of that node are considered to be no more there
	            // so, the indegrees of the neighbours of that will reduce by 1
	            inDegree[it]--;
	            if (inDegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
	}
};

// TC = O(V + E)
// SC = O(V)
