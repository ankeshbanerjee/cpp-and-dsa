#include <bits/stdc++.h>
using namespace std;

// multiset is same as set, with an exception, that is, it allows same elements

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // (x(vertical line), y(horizontal line)) -> {set of nodes in this co-ord(x, y)}
        map <int, map<int, multiset<int>>> nodes;
        // <Node*, <x, y>>
        queue<pair<TreeNode *, pair<int, int>> > q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            // insert the curr node in its respective set
            nodes[p.second.first][p.second.second].insert(p.first->val);
            if (p.first->left)
                q.push({p.first->left, {p.second.first-1, p.second.second+1}});
            if (p.first->right)
                q.push({p.first->right, {p.second.first+1, p.second.second+1}});
        }

        vector<vector<int>> ans;
        for (auto it : nodes){
            vector<int>temp;
            for (auto p : it.second){
                temp.insert(temp.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// TC = O(NlogN), traversing each node, logN to insert into the set
// SC = O(N), storing N nodes