#include <bits/stdc++.h>
using namespace std;

vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    // {vertical line, node}
    map<int, int>mp;
    // {Node, vertical line}
    queue<pair<TreeNode<int>*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        mp[p.second] = p.first->data;
        if (p.first->left)
            q.push({p.first->left, p.second-1});
        if (p.first->right)
            q.push({p.first->right, p.second+1});
    }
    vector<int> ans;
    for (auto it : mp)
        ans.push_back(it.second);
    
    return ans;
}

// TC = O(N)
// SC = O(N)