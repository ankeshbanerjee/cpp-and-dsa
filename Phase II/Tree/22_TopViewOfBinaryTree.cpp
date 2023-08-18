#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // {vertical level, node}
        map<int, int> nodes;
        // {node, vertical level}
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();
                // if this vertical level is not present in the map, then insert it, otherwise not
                if(nodes.find(p.second) == nodes.end())
                    nodes[p.second] = p.first->data;
                if(p.first->left)
                    q.push({p.first->left, p.second-1});
                if(p.first->right)
                    q.push({p.first->right, p.second+1});
            }
        }
        
        vector<int> ans;
        for (auto it : nodes){
            ans.push_back(it.second);
        }
        return ans;
    }

};

// TC = O(N)
// SC = O(2N) (for map of two variables) + O(N) (for queue)

// this cannot be done easily using dfs (for explanation see video)