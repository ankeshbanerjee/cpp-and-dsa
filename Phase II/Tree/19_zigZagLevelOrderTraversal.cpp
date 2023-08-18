#include <bits/stdc++.h>
using namespace std;

// everything same as level order traversal
// only changing the index of storing the current node, according to the leftToRight flag

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> lvl(lvlSize);
            for (int i=0; i<lvlSize; i++){
                TreeNode * node = q.front();
                q.pop();
                // find the position of the current node
                int index = (leftToRight) ? i : (lvlSize-i-1);
                lvl[index] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            // after this level
            leftToRight = !leftToRight;
            ans.push_back(lvl);
        }

        return ans;
    }
};