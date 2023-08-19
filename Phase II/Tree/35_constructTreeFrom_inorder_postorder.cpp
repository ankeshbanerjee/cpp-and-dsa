#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode * buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart,
    int postEnd, unordered_map<int, int> &mp){
        if (inStart>inEnd || postStart>postEnd)
            return NULL;
        
        TreeNode * root = new TreeNode (postorder[postEnd]);
        int rootIndexInorder = mp[root->val];
        root->left = buildTreeHelper(inorder, inStart, rootIndexInorder-1, postorder, postStart, postStart + (rootIndexInorder-inStart-1), mp);
        root->right = buildTreeHelper(inorder, rootIndexInorder+1, inEnd, postorder, postStart + (rootIndexInorder-inStart), postEnd-1, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // {inorder-node -> inorder->index}
        unordered_map<int, int> mp;
        for (int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode* root = buildTreeHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
        return root;
    }
};