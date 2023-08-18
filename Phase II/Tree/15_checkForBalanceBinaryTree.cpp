#include <bits/stdc++.h>
using namespace std;

// naive approach
// bool check (Node * root)
//     if (root == NULL) return true;

//     int lh = height(root->left);
//     int rh = height(root->right);
//     if (abs(lh-rh)>1)return false;

//     int leftCheck = check(root->left);
//     int rightCheck = check(root->right);
//     return leftCheck || rightCheck;
// TC = O(N^2), coz going to each of N nodes, and finding the height, which at max takes O(N)

// optimized approach
class Solution {
private:
    int height (TreeNode* root){
        if (root == NULL)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh == -1 || rh == -1) return -1;
        if (abs(lh-rh)>1) return -1;
        return 1+max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (height(root)==-1) return false;
        return true;
    }
};
// TC = O(N)
// SC = O(N)