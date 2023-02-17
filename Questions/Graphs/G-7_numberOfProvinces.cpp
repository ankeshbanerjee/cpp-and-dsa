#include <bits/stdc++.h>
using namespace std;

void dfs (int node, vector<int> adjls[], int vis[]){
    vis[node] = 1;
    for (auto it: adjls[node]){
        if (!vis[it]){
            dfs (it, adjls, vis);
        }
    }
}

int numProvinces (vector<vector<int>> adj, int V){
    // convert the adjancency matrix to adjancency list
    vector<int> adjls[V];
    for (int i=0; i<V; i++){
        for (int j=0; j<V; j++){
            if (adj[i][j] == 1 && j != i ){ /*not considering the self edges, coz, those will be of no use in traversing the graph*/
                adjls[i].push_back(j);
            }
        }
    }
    // creating visited array
    int vis[V] = {0};
    int count;
    for (int i=0; i<V; i++){
        if (!vis[i]){
            count++;
            dfs(i, adjls, vis);
        }
    }
    return count;
}

//SC = O(N) (for visited array) + O(N) (recursion stack space) = O(N)
/* for (i = 0 -> V){
    // this loop runs N times
    inside this, the dfs call will go for every nodes in total
    the total dfs TC for the entire graph is O(N + 2E)
}
TC = O(N) + O(N + 2E), which near equal to O(N)
*/

int main (){
    
return 0;
}