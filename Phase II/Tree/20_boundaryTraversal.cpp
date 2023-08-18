#include <bits/stdc++.h>
using namespace std;

// O(H)
void addLeftBoundary(TreeNode<int> * root, vector<int> &ans){
    TreeNode<int> * cur = root->left;
    while (cur && (cur->left || cur->right)){
        ans.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// O(N)
void addLeaves (TreeNode<int> * root, vector<int> &ans){
    // preorder traversal to add leaves
    if (!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }

    if(root->left)
        addLeaves(root->left, ans);
    if(root->right)
        addLeaves(root->right, ans);
}

// O(H)
void addRightBoundary(TreeNode<int> *root, vector<int> &ans){
    TreeNode<int> * cur = root->right;
    stack<int> st;
    while (cur && (cur->left || cur->right)){
        st.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans;
    if (root==NULL) return ans;
    ans.push_back(root->data);
    if (!root->left && !root->right) return ans;
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}

// TC = O(H) + O(H) + O(N) = O(N)
// SC = O(N)
