#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSymmetricHelper(TreeNode*left, TreeNode*right){
        if(left==NULL || right==NULL)
            return (left==right);

        if(left->val != right->val)
            return false;
        
        return  isSymmetricHelper(left->left, right->right)
                &&
                isSymmetricHelper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return (root==NULL) || (isSymmetricHelper(root->left, root->right));
    }
};

// TC = O(N), traversing each node once
// SC = O(N), in worst case, the tree would be a skewed tree