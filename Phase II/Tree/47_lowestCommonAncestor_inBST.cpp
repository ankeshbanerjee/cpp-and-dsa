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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL)
            return NULL;

        TreeNode* temp = root;
        while(temp != NULL){
            // both p, q are less than current node => lca belongs to left subtree of current node
            if (p->val < temp->val && q->val < temp->val)
                temp = temp->left;
            // both p, q are more than current node => lca belongs to right subtree of current node
            else if (p->val > temp->val && q->val > temp->val)
                temp = temp->right;
            // if one of them is lesser and another is greater than current node => means the current node is the lca, so break
            else
                break;
        }
        return temp;
    }
};

// TC = O(H)
// SC = O(1)