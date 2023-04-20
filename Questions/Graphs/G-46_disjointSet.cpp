// if we want to know if any two nodes, let u and v, lies under the same component or not, in constant time
// then we have to implement disjoint set

// union can be done in two ways : 1. union by rank 2. union by size
// time complexity of findUltimateParent = O(4*alpha) and unionBySize = O(4*alpha) and unionBySize = O(4*alpha)
// O(4*alpha) = O(1) = constant time

// Use recursion to find ultimate parent (process is knows as path compression)

// union by Rank :
// 1. find ultimate parent of u and v
// 2. find the ranks of ulp_u and ulp_v
// 3. always connect the smaller ranked node to the bigger one

// why connect the smaller to the bigger?
// if we do the opposite, i.e., if we connect the bigger to the smaller, then only the two nodes of the smaller will take lesser time to reach the ultimate parent
// but the nodes of the bigger branch will take more time to reach the ultimate parent
// as the number of nodes is greater in the bigger branch, so the overall time needed is much more in this case
// now if we connect smaller to the bigger, the nodes of the smaller node will take more time to reach the ultimate parent
// but the nodes of the bigger branch will take lesser time to reach the ultimate parent.
// as the number of nodes in the bigger branch is more, so the time needed in this case is comparatively lesser

// rank and height are different :
// as every node is directly connected to its ultimate parent, so the height is 1.
// as the height is 1 for all nodes, so a similar concept of rank is introduced to implement the algorithm

// union by Size :
// 1. find ultimate parent of u and v
// 2. find the ranks of ulp_u and ulp_v
// 3. always connect the smaller sized node to the bigger one and add the size of the added node to the bigger node

// Note :  1. After connecting all the given edges, the parent array may not store the ultimate parent of each node,
//            so, whenever you need to get the ultimate parent of any node, just call the findUltimateParent() function.
//         2. Here a graph is not created, rather Disjoint set is completely a different data structure

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector <int> rank, parent, size;
    public: 
    // constructor
    DisjointSet (int n){
        parent.resize(n+1); 
        rank.resize(n+1, 0); // n+1 so that it can be used for both 0 and 1 based indexing
        size.resize(n+1, 1); // intially every node is a component of size 1

        for (int i=0; i<n+1; i++)parent[i] = i;
    }

    int findUltimateParent(int u){
        // base case
        if (parent[u] == u) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)return;

        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)return;

        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Same component" << endl;
    else cout << "different component" << endl;
    ds.unionBySize(3, 7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Same component" << endl;
    else cout << "different component" << endl;

    
    return 0;
}