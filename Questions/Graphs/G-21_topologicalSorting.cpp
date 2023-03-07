/*
topological sorting : it is the linear ordering of the vertices such that 
if there is an edge from u to v, then u is always placed before v in that ordering.
it is relevant for DAG (Directed Acyclic Graph)
because:
1. if undirected, then u - v means, u -> v and v -> u
so, which vertex should be placed before which, can't be decided
2. suppose a cyclic graph, where, edges are: 1 -> 2 and 2 -> 3 and 3 -> 1
so, if we try to place them in the afore mentioned linear ordering then
1 should be before 2, 2 should be before 3 and 3 should be before 1, which is not possible
because as stated before 1 should be before 2 and hence should also be before 3 because 2 is before 3 
*/

/*
Intuition:
1. traverse with normal dfs
2. when dfs is complete for a node, push that node into the stack
3. when the dfs for entire graph is complete, push the elements of stack from top into the ans vector,
until the stack gets emptied.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void dfs (int node, vector <int> &vis, vector <int> adj[], stack <int> &st){
        vis[node] = 1;
        for (auto it: adj[node]){
            if (!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector <int> ans;
	    vector <int> vis (V, 0);
	    stack <int> st;
	    for (int i=0; i<V; i++){
	        if (!vis[i]){
	            dfs(i, vis, adj, st);
	        }
	    }
	    while (!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
