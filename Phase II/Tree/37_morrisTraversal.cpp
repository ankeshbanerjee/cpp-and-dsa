#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// morris traversal ->
// TC = O(N) & SC = O(1)
// it uses constant space because morris traversal is based upon THREADED TREE concept.

// Just remember 3 steps(cases) and it will be easy
// case 1 ->
// when left of curr is NULL ->
// push curr into inorder, and move to right.

// case 2 ->
// when left of curr is not NULL.
// then before moving left, find the right most node of the left subtree.
// connect that node to curr and then move left

// case 2.0->
// after linking is done, when I will come back to curr, how will I then know that whether I have to go right or left?
// if I find that the right most node of the left subtree is already connected to curr, then I can know that I have visited the left subtree
// and its time to go to the right subtree. 
// And before going to right, make sure to remove the thread between rightmost node of left subtree and curr, to keep the tree as it was.

// in inorder -> left root right
// so, before moving right, make sure to push curr into the inorder

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr != NULL){
            if (curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode * prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

// TC = O(N) + O(N) (traversing all the nodes) = O(N)
// first O(N) is for the inner while loop, (it is amortized O(N)).
// because all the iterations together will make O(N).
// the inner while loop, throughout will run for O(N), not in individual terms.
// in total the inner while loop produces O(N).
// SC = O(1)

// preorder morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;
        while (curr != NULL){
            if (curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode * prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
// a single line change between inorder and preorder morris traversal
// preorder means root left right
// so, before going to left, push curr into the preorder