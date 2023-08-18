#include <bits/stdc++.h>
using namespace std;

// diameter means the longest distance between any two nodes of a tree
// the path need not to go through the root

// naive approach -
// findMax(root)
//     if (root == NULL) return;
//     int lh = height(root->left);
//     int rh = height(root->right);
//     maxi = max(maxi, lh+rh);
//     findMax(root->left);
//     findMax(root->right);

// TC = O(N^2), coz, reaching each of N nodes, finding height for each node, which takes at max O(N)


// optimized approach
class Solution {
private:
    int height (TreeNode* root, int &diameter){
        if (root == NULL)return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1+max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int ht = height (root, diameter);
        return diameter;
    }
};