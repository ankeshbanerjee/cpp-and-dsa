#include <bits/stdc++.h>
using namespace std;

void createAdjacencyList (int N, int M, vector<int> adj[]){
    cout << "Enter the edges: " << endl;
    for (int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int> solve (int N, vector<int> adj[]){
    // graph is of 0 based indexing
    int visited[N] = {0};
    visited[0] = 1;
    queue <int> q;
    q.push(0);
    vector <int> bfs;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // pushing the degrees (neighbours) of current node
        for (auto it : adj[node]){
            if (!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;    
}
/*
SC = O(N) (for visited array) + O(N) (for the queue) + O(N) (for the ans - bfs vector) = O(N)
while (){
    // this loop runs for each of the node once
    for (){
        // this loop runs for all the degrees (neighbours) of each node
        // total degrees = 2E
    } 
}
TC = O(N)(for the outer while loop) + O(2E) (for the inner for loop)
*/ 

vector <int> bfsOfGraph(int N, int M){
    vector<int> adj[N];
    createAdjacencyList(N, M, adj);
    return solve(N, adj);
}

int main (){
    vector<int> bfs = bfsOfGraph(7, 7);
    // i/p : 0 1 0 2 1 3 1 4 4 5 2 5 2 6
    cout << "printing bfs:" << endl;
    for (auto it: bfs){
        cout << it << " ";
    }
return 0;
}
