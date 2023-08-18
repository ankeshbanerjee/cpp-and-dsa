#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == NULL || root == p || root == q)
            return root;
        
        TreeNode * left = solve(root->left, p, q);
        TreeNode * right = solve(root->right, p, q);

        if (left && right)
            return root;
        if (left)
            return left;
        if (right)
            return right;
              
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};

// TC = O(N)
// SC = O(N) (worst case -> skewed trees)