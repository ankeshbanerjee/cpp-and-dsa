#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
bool isSafe (int ind, int col, vector<int> &color, vector<vector<int>> &adj){
    for (auto it : adj[ind]){
        if (color[it] == col) return false;
    }
    return true;
}
bool solve (int ind, vector<int> &color, vector<vector<int>> &adj, int m, int n){
    // base case
    if (ind == n){
        return true;
    }

    for (int col = 1; col <= m; col++){
        if (isSafe(ind, col, color, adj)){
            color[ind] = col;
            if (solve(ind+1, color, adj, m, n)) return true;
            color[ind] = 0;
        }
    }

    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (mat[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color (n, 0);
    if (solve(0, color, adj, m, n)) return "YES";
    return "NO";
}

// time complexity - O(m^n)
// space complexity - O(n)(color vector) + O(n) (auxiliary stack space)
