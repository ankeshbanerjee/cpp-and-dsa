#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* inorderHelper(TreeNode* root, int &k){
        if (root == NULL)
            return NULL;
        
        TreeNode* left = inorderHelper(root->left, k);
        if (left)
            return left;
        k--;
        if (k==0)
            return root;
        
        return inorderHelper(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = inorderHelper(root, k);
        return node->val;
    }
};

// TC = O(N)
// SC = O(N)