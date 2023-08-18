#include <bits/stdc++.h>
using namespace std;

// naive approach -
// finding the path sum between every two possible nodes.
// surely, this will take O(N^2) time

// optimized approach - similar of finding height of tree
class Solution {
private:
    int solve(TreeNode * root, int &maxi){
        if (root == NULL) return 0;
        
        // if solve(root->left, maxi) is < 0, then leftMaxPath = 0. similar with rightMaxPath
        int leftMaxPath = max(0, solve(root->left, maxi));
        int rightMaxPath = max(0, solve(root->right, maxi));
        maxi = max(maxi, root->val+leftMaxPath+rightMaxPath);
        return root->val + max(leftMaxPath, rightMaxPath);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int maxPath = solve(root, maxi);
        return maxi;
    }
};
// TC = O(N)
// SC = O(N)