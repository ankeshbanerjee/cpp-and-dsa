#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// watch this solution from CODEHELP

// approach 1 -> preorder traversal and make linked list from that nodes
// appraoch 2 -> recursive solution, TC = O(N) & SC = O(N)
// apporach 3 -> morris traversal, most optimized TC = O(N), SC = O(1)

class Solution {
public:
    // morris traversal
    void flatten(TreeNode* root) {
        TreeNode * curr = root;
        while (curr != NULL){
            if (curr->left == NULL)
                curr = curr->right;
            else{
                TreeNode* prev = curr->left;
                while (prev->right != NULL)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        }
    }
};

// notice, 'curr = curr->right' is common in both if and else, so merge them, as shown below
class Solution {
public:
    // morris traversal
    void flatten(TreeNode* root) {
        TreeNode * curr = root;
        while (curr != NULL){
            if (curr->left != NULL){
                TreeNode* prev = curr->left;
                while (prev->right != NULL)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};