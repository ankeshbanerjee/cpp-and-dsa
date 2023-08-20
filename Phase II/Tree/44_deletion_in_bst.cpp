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


// simple steps ->
// 1. find the node to delete
// 2. the elements of the left subtree is smaller than that of right subtree
// 3. so, find the right most guy of left subtree. 
// 4. attach the entire right subtree of the node to this rightMost guy's right.

// one edge case,
// if there is no left subtree of the node,
// return the node's right subtree, that will directly connect to it's parent.

class Solution {
private:
    TreeNode* findRightMost(TreeNode* node){
        TreeNode* temp = node;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }
    TreeNode* deleteHelper(TreeNode* node){
        if (node->left == NULL)
            return node->right;
        // find right most guy of left subtree
        TreeNode* rightMost = findRightMost(node->left);
        rightMost->right = node->right;
        TreeNode* nodeToReturn = node->left;
        // delete node
        node->left = node->right = NULL;
        delete(node);
        return nodeToReturn;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL)
            return NULL;
        if (root->val == key)
            return deleteHelper(root);
        // search for the node
        TreeNode* temp = root;
        while (temp != NULL){
            if (key < temp->val){
                if (temp->left != NULL && temp->left->val == key)
                    temp->left = deleteHelper(temp->left);  // delete node
                else 
                    temp = temp->left;
            }
            else{
                if (temp->right != NULL && temp->right->val == key)
                    temp->right = deleteHelper(temp->right);    // delete node
                else 
                    temp = temp->right;
            }
        }
        return root;
    }
};