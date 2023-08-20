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

// naive approach->
// storing the inorder and simply solve the two sum problem on it.
// TC = O(N) + O(N)
// SC = O(H) + O(N)

class Solution {
private:
    void inorder(TreeNode* root, vector<int> &in){
        if (root == NULL)
            return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);
        int i=0, j = in.size()-1;
        while (i<j){
            if (in[i]+in[j] == k)
                return true;
            if (in[i]+in[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
};

// optimized approach ->
// using BST iterator

class BSTIterator {
private:
    stack<TreeNode* >st;
    bool reverse = true;
    // reverse -> true -> before() -> gives the elements of inorder, sorted in decreasing order(i.e., reversed inorder), one by one
    // reverse -> false -> next() -> gives the elements of inorder traversal one by one
    void pushInorder(TreeNode* root){
        TreeNode* temp = root;    
        while (temp != NULL){
            st.push(temp);
            if (!reverse)
                temp = temp->left;
            else 
                temp = temp->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushInorder(root);
    }
    
    int next() {
        TreeNode* next = st.top();
        st.pop();
        if (!reverse)
            pushInorder(next->right);
        else
            pushInorder(next->left);
        return next->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // inorder
        BSTIterator l(root, false);
        // reversed inorder 
        BSTIterator r(root, true);
        int i = l.next(), j = r.next();
        while (i<j){
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else 
                j = r.next();
        }
        return false;
    }
};

// TC = O(N)
// SC = O(H)