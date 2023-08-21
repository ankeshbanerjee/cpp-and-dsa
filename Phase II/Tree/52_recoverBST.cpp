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

// brute approach ->
// store and inorder -> O(N)
// sort the inorder -> O(NlogN)
// find the mismatches between these two -> O(N)
// swap the mismatches
// TC = O(N) + O(NlogN) + O(N)


// optimized approach ->
// while doing the inorder traversal, keep the track of nodes which are not is sorted order
// TreeNode* first -> first node which shows discrepency
// middle -> adjacent node of first, with which 'first' has discrepency
// last -> if second violation is noticed, store that node in 'last'.

// now two cases are possible->
// 1. discrepencies are adjacent-> swap first and middle (last is NULL in this case)
// 2. discrepencies are not adjacent -> swap first and last (first, middle, last all are non-null in this case)

class Solution {
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorderHelper(TreeNode* root){
        if (root==NULL)
            return;

        inorderHelper(root->left);
        if (prev != NULL && prev->val > root->val){
            if (first == NULL){
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inorderHelper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorderHelper(root);
        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};
// TC = O(N)
// SC = O(N), (which can be further optimized by morris traversal)