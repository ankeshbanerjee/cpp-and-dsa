#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class DisjointSet
    {
    public:
        vector<int> rank, parent, size;
        // constructor
        DisjointSet(int n)
        {
            parent.resize(n + 1);
            rank.resize(n + 1, 0); // n+1 so that it can be used for both 0 and 1 based indexing
            size.resize(n + 1, 1); // intially every node is a component of size 1

            for (int i = 0; i < n + 1; i++)
                parent[i] = i;
        }

        int findUltimateParent(int u)
        {
            // base case
            if (parent[u] == u)
                return u;
            return parent[u] = findUltimateParent(parent[u]);
        }

        void unionByRank(int u, int v)
        {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if (ulp_u == ulp_v)
                return;

            if (rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u])
            {
                parent[ulp_v] = ulp_u;
            }
            else
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v)
        {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if (ulp_u == ulp_v)
                return;

            if (size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // O(M)
        vector<pair<int, pair<int, int>>> edges;
        // O(V+ 2E)
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];

                edges.push_back({wt, {i, adjNode}});
            }
        }

        // O(MlogM)
        sort(edges.begin(), edges.end());
        int sumWt = 0;

        DisjointSet ds(V);
        // O(M * 4 * alpha * 2)
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
            {
                sumWt += wt;
                ds.unionByRank(u, v);
            }
            else
            {
                continue;
            }
        }

        return sumWt;
    }
};