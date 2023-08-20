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

// naive aprroach ->
// take elements from the preorder one by one,
// search for the right place for that element in the bst, according to the properties of bst
// make a new node, and place it over there.
// this will take O(N*N), first N is for traversing the each element, and another N is for searching the right place for each element.

// approach 2 ->
// sort the preorder to get inorder.
// build tree using preorder and inorder.
// TC = O(NlogN) + O(N)

// most optimized approach below -> O(N)
// only upper bound (ub) is needed
// while going left, the upper bound is the node->val itself
// while going right, the upper bound is the same upper bound of the current node

class Solution {
private:
    TreeNode* buildTree(vector<int> &preorder, int &ind, int ub){
        if (ind == preorder.size() || ub < preorder[ind])
            return NULL;
        TreeNode* node = new TreeNode(preorder[ind++]);
        node->left = buildTree(preorder, ind, node->val);
        node->right = buildTree(preorder, ind, ub);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        TreeNode* root = buildTree(preorder, ind, INT_MAX);
        return root;
    }
};

// TC = O(N)
// SC = O(N)