#include <bits/stdc++.h>
using namespace std;

void solve (int node, vector<int> adj[], int vis[], vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);
    // traverse all the neighbours of current node
    for (auto it: adj[node]){
        if (!vis[it]){
            solve (it, adj, vis, ans);
        }
    }
}

vector<int> dfs (int n, vector<int> adj[]){
    int vis[n] = {0};
    int start = 0; // starting node is 0;
    vector<int> ans;
    solve (start, adj, vis, ans);
    return ans;    
}

// SC = O(N) (for storing n nodes in ans vector) + O(N) (for visited arr) + O(N) (recursion stack space at worst case) = O(N)
/*
solve (){
    // solve function will be called once for each of the n nodes

    for (){
        // this loop will run for all the degrees of each node
        // and total degrees of a graph is 2*E
    }
}

so, TC = O(N) (solve fun. will be called once for each of the N nodes) + O(2E) (the for loop will run for total degrees in the graph)
TC = O(N+2E)
*/

int main (){
    
return 0;
}