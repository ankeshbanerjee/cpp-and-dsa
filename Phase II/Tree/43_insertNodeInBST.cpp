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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return root = new TreeNode(val);
        TreeNode* temp = root;
        TreeNode* prev = NULL;
        while (temp != NULL){
            prev = temp;
            if (temp->val < val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        if (val < prev->val)
            prev->left = new TreeNode(val);
        else
            prev->right = new TreeNode(val);
        
        return root;
    }
};