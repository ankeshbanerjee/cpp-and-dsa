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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode * key = root;
        while(key != NULL){
            if (key->val == val)
                break;
            if(key->val < val)
                key = key->right;
            else
                key = key->left;
        }
        return key;
    }
};