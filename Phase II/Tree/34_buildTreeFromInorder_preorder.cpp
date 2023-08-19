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
    TreeNode * buildTreeHelper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, 
    int inStart, int inEnd, unordered_map<int, int> &mp){
        if (preStart>preEnd || inStart>inEnd)
            return NULL;
        
        TreeNode * root = new TreeNode(preorder[preStart]);
        int rootIndexInorder = mp[preorder[preStart]];
        root->left = buildTreeHelper(preorder, preStart+1, preStart+(rootIndexInorder-inStart), inorder, inStart, rootIndexInorder-1, mp);
        root->right = buildTreeHelper(preorder, preStart+(rootIndexInorder-inStart)+1, preEnd, inorder, rootIndexInorder+1, inEnd, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // {inorder-node -> inorder-index}, so that, it becomes easier to search
        unordered_map<int, int> mp;
        for (int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode * root = buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};

// TC = O(N)
// SC = O(N) (map) + O(N) (recursive stack space)