#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// naive approach is -
// doing any kind of traversal and count the nodes in O(N)
// but in the optimized approach, we are gonna use the property of complete tree 
// which will take time complexity < O(N)

class Solution {
private:
    int findLeftHeight(TreeNode* root){
        if (root==NULL)
            return 0;
        int cnt = 0;
        TreeNode* temp = root;
        while(temp){
            cnt++;
            temp = temp->left;
        }
        return cnt;
    }
    int findRightHeight(TreeNode* root){
        if (root==NULL)
            return 0;
        int cnt = 0;
        TreeNode* temp = root;
        while(temp){
            cnt++;
            temp = temp->right;
        }
        return cnt;
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        if (leftHeight == rightHeight)
            return (1<<leftHeight) - 1;

        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return 1 + leftCount + rightCount;
    }
};

// TC = O((log N)^2), log N for traversing nodes through the height of the tree. and log N for finding the height at a node
// SC = O(log N)