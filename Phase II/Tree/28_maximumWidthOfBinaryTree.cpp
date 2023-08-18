#include <bits/stdc++.h>
using namespace std;

// this indexing approach is the intution of segment tree
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        // {node, index}
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long maxi = 0;
        while(!q.empty()){
            int size = q.size();
            long long min = q.front().second; // the index of the first element of each level is the minimum of that index
            long long first, last;
            for (int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                long long index = q.front().second - min;
                q.pop();
                if (i==0) first = index;
                if (i == size-1) last = index;
                if (node->left)
                    q.push({node->left, 2*index+1});
                if (node->right)
                    q.push({node->right, 2*index+2});
            }
            maxi = max(maxi, (last-first+1));
        }
        return (int)maxi;
    }
};

// TC = O(N)
// SC = O(N)