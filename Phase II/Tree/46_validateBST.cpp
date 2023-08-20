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
    bool isValidHelper(TreeNode* root, long low, long high){
        if (root==NULL)
            return true;

        if (root->val <= low || root->val >= high)
            return false;
        return isValidHelper(root->left, low, root->val) 
            && isValidHelper(root->right, root->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root, LONG_MIN, LONG_MAX);
    }
};