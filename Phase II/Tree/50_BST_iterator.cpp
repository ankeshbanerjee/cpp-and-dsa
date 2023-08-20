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

// naive approach is to store the entire inorder traversal in a vector
// this would cost a SC = O(N)
// and TC of next() and hasnext() would be O(1)

// optimized approach takes a SC = O(H)
// inorder => LEFT ROOT RIGHT, these are shown in the code by comments
class BSTIterator {
private:
    stack<TreeNode* >st;
    void pushInorder(TreeNode* root){
        TreeNode* temp = root;
        // LEFT
        while(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushInorder(root);
    }
    
    int next() {
        TreeNode* next = st.top(); // ROOT
        st.pop();
        pushInorder(next->right); // RIGHT
        return next->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

// SC = O(H), coz, at max the size of the stack will be the height of the tree.
// TC (next(), hasnext()) = O(1)